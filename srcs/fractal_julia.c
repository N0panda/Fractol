/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:25:32 by ythomas           #+#    #+#             */
/*   Updated: 2019/12/04 17:29:10 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			f_julia(t_env *env, double x, double y)
{
	double		tmp;
	int			i;
	double		tab[4];

	i = 0;
	//0 = c reel
	//1 = c imm
	//2 = z reel
	//3 = z imm
	tab[0] = env->c_r;
	tab[1] = env->c_i;
	tab[2] = x / env->zoom + env->x_min;
	tab[3] = y / env->zoom + env->y_min;
	while (tab[2] * tab[2] + tab[3] * tab[3] < 4.0
			&& i < env->max_iter)
	{
		tmp = tab[2];
		tab[2] = tab[2] * tab[2] - tab[3] * tab[3] + tab[0];
		tab[3] = 2.0 * tab[3] * tmp + tab[1];
		i++;
	}
	color_functions(env, x, y, i);
}

void			init_julia(t_env *env)
{
	env->max_iter = 10;
	env->x_min = -4.0;
	env->y_min = -2.5;
	env->zoom_menu = 0;
	env->mouse = WORKING;
	env->freeze = DEFROST;
	env->zoom = (W_IMAGE / (ft_abs(env->x_min)) + (ft_abs(env->y_min))) / 2;
	return ;
}
