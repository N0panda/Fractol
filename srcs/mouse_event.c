/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:38:02 by ythomas           #+#    #+#             */
/*   Updated: 2019/12/03 17:24:51 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom(double x, double y, t_env *env, int stat)
{
	double rate;

	rate = (stat == 0 ? 1.5 : 0.66);
	env->zoom_menu += (stat == 0 ? 1 : -1);
	env->x_min = (x / env->zoom + env->x_min) - (x / (env->zoom * rate));
	env->y_min = (y / env->zoom + env->y_min) - (y / (env->zoom * rate));
	env->zoom *= rate;
	fill_buff_image(env);
}

void		freeze_defreeze(t_env *env, int stat)
{
	if (stat == 0)
	{
		env->freeze = DEFROST;
		env->mouse = WORKING;
	}
	else
	{
		env->freeze = FROZEN;
		env->mouse = PENDING;
	}
	fill_buff_image(env);
}
