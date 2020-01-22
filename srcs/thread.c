/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:25:00 by ythomas           #+#    #+#             */
/*   Updated: 2019/12/04 17:57:31 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static const t_func 	g_func[] =
{
	f_mandelbrot,
	f_julia,
	f_burningship,
	f_feigenbaum,
	f_leaf
};

int				fill_buffer_image_t(t_env *env, double pos)
{
	double x;
	double y;
	double rest;

	y = 0.0;
	rest = pos;
	while (y < H_IMAGE)
	{
		x = 0.0 + rest;
		while (x < W_IMAGE)
		{
			g_func[env->fractal](env, x, y);
			if (x + NB_THREAD >= W_IMAGE)
				rest = (x + NB_THREAD) - W_IMAGE;
			x += NB_THREAD;
		}
		y++;
	}
	return (0);
}

void				get_position(t_env *env)
{
	int i;

	i = -1;
	while (++i < NB_THREAD)
	{
		if (env->start_thr[i] == -1)
		{
			env->start_thr[i] = 0;
			fill_buffer_image_t(env, (double)i);
			pthread_exit(NULL);
		}
	}
}

void				setup_start_thr(t_env *env)
{
	int i;

	i = -1;
	while (++i < NB_THREAD)
		env->start_thr[i] = -1;
}

int					fill_buff_image_CPU(t_env *env)
{
	int				i;
	pthread_t		thread[NB_THREAD];

	i = -1;
	setup_start_thr(env);
	while (++i < NB_THREAD)
		pthread_create(&thread[i], NULL, (void *)get_position, env);
	i = -1;
	while (++i < NB_THREAD)
		pthread_join(thread[i], NULL);
	push_image(env);
	return (0);
}
