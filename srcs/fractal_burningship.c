/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_feigenbaum.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:33:54 by ythomas           #+#    #+#             */
/*   Updated: 2019/12/04 17:13:42 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				f_burningship(t_env *env, double x, double y)
{
	double			tmp;
	int				i;
	double			tab[4];

	i = 0;
	tab[0] = x / env->zoom + env->x_min;
	tab[1] = y / env->zoom + env->y_min;
	tab[2] = 0.0;
	tab[3] = 0.0;
	while (tab[2] * tab[2] + tab[3] * tab[3] < 4.0
		&& i < env->max_iter)
	{
		tmp = tab[2] * tab[2] - tab[3] * tab[3] + tab[0];
		tab[3] = ft_abs(2 * tab[2] * tab[3] + tab[1]);
		tab[2] = ft_abs(tmp);
		i++;
	}
	color_functions(env, x, y, i);
}

void				init_burningship(t_env *env)
{
	env->x_min = -2.5;
	env->y_min = -2.0;
	env->max_iter = 10;
	env->mouse = 0;
	env->zoom_menu = 0;
	env->zoom = W_IMAGE / (ft_abs(env->x_min) + ft_abs(env->y_min));
}
