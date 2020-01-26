/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:09:44 by ythomas           #+#    #+#             */
/*   Updated: 2020/01/26 17:59:20 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static const init_func g_init[] =
{
	init_mandelbrot,
	init_julia,
	init_burningship,
	init_feigenbaum,
	init_leaf
};

static const char		*g_frac_name[] =
{
	"Mandelbrot",
	"Julia",
	"Burningship",
	"Feigenbaum",
	"Leaf"
};

void		reset_fractal(t_env *env)
{
	g_init[env->fractal](env);
	free(env->name);
	env->name = ft_strdup(g_frac_name[env->fractal]);
	fill_buff_image(env);
}

void		change_fractal(t_env *env, int key)
{
	if (key == 83)
		env->fractal = 0;
	else if (key == 84)
		env->fractal = 1;
	else if (key == 85)
		env->fractal = 2;
	else if (key == 86)
		env->fractal = 3;
	else if (key == 87)
		env->fractal = 4;
	reset_fractal(env);
}

void		modify_max_iter(t_env *env, int stat)
{
	if (stat == 1)
	{
		env->max_iter++;
		fill_buff_image(env);
	}
	else
	{
		env->max_iter--;
		fill_buff_image(env);
	}
}

void		deal_with_hidden_menu(t_env *env, int key)
{
	if (key == 35)
	{
		if (env->help == 0)
			env->help = 1;
		else
			env->help = 0;
	}
	else
	{
		if (env->hidden_menu == VISIBLE)
			env->hidden_menu = HIDDEN;
		else
			env->hidden_menu = VISIBLE;
	}
	fill_buff_image(env);
}

void		change_processor(t_env *env, int key)
{
	if (key == 8 && env->processor != CPU)
	{
		env->processor = CPU;
		fill_buff_image(env);
	}
	else if (key == 5 && env->processor != GPU)
	{
		env->processor = CPU;
		fill_buff_image(env);
	}
}
