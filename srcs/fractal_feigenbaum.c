/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_feigenbaum.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:58:36 by ythomas           #+#    #+#             */
/*   Updated: 2020/01/26 17:35:59 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			f_feigenbaum(t_env *env, double x, double y)
{
	double			tmp;
	int				i;
	double			tab[4];
	const double	teta = 1.401155;

	i = 0;
	tab[0] = x / env->zoom + env->x_min;
	tab[1] = y / env->zoom + env->y_min;
	tab[2] = 0.0;
	tab[3] = 0.0;
	while (tab[2] * tab[2] + tab[3] * tab[3] < 4.0
		&& i < env->max_iter)
	{
		tmp = tab[2];
		tab[2] = tab[2] * tab[2] - tab[3] * tab[3] + (tab[0] *
			((tab[0] * tab[0]) - 3 * (tab[1] * tab[1]))) - teta;
		tab[3] = 2.0 * tab[3] * tmp +
			(tab[1] * ((3 * tab[0] * tab[0]) - (tab[1] * tab[1])));
		i++;
	}
	color_functions(env, x, y, i);
}

void			init_feigenbaum(t_env *env)
{
	env->x_min = -2.1;
	env->y_min = -1.2;
	env->max_iter = 10;
	env->mouse = 0;
	env->zoom_menu = 0;
	env->zoom = W_IMAGE / (ft_abs(env->x_min) + ft_abs(env->y_min));
}
