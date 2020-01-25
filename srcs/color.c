/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:58:47 by ythomas           #+#    #+#             */
/*   Updated: 2020/01/25 18:46:29 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_color		color_function[] = {
	color_degrade,
	set_of_two,
	set_of_four,
	set_of_six
};

unsigned int		set_of_two(t_env *env, double x, double y, int i)
{
	unsigned int		color;

	if (i == env->max_iter)
		color = env->paint[env->id_paint][0];
	else
		color = env->paint[env->id_paint][1];
	return (color);
}

unsigned int		set_of_four(t_env *env, double x, double y, int i)
{
	unsigned int		color;

	if (i == env->max_iter)
		color = color_degrade_two(env, i, env->id_paint, 0);
	else if (i  > 0.8 * env->max_iter)
		color = color_degrade_two(env, i, env->id_paint, 1);
	else if (i > 0.5 * env->max_iter)
		color = color_degrade_two(env, i, env->id_paint, 2);
	else
		color = color_degrade_two(env, i, env->id_paint, 3);
	return (color);
}

unsigned int		set_of_six(t_env *env, double x, double y, int i)
{
	unsigned int		color;

	if (i == env->max_iter)
		color = color_degrade_two(env, i, env->id_paint, 0);
	else if (i > 0.95 * env->max_iter)
		color = color_degrade_two(env, i, env->id_paint, 1);
	else if (i > 0.92 * env->max_iter)
		color = color_degrade_two(env, i, env->id_paint, 2);
	else if (i > 0.86 * env->max_iter)
		color = color_degrade_two(env, i, env->id_paint, 3);
	else if (i > 0.8 * env->max_iter)
		color = color_degrade_two(env, i, env->id_paint, 4);
	else if (i > 0.72 * env->max_iter)
		color = color_degrade_two(env, i, env->id_paint, 5);
	else if (i > 0.5 * env->max_iter)
		color = color_degrade_two(env, i, env->id_paint, 1);
	else if (i > 0.2 * env->max_iter)
		color = color_degrade_two(env, i, env->id_paint, 2);
	else if (i > 0.15 * env->max_iter)
		color = color_degrade_two(env, i, env->id_paint, 3);
	else if (i > 0.1 * env->max_iter)
		color = color_degrade_two(env, i, env->id_paint, 4);
	else
		color = color_degrade_two(env, i, env->id_paint, 5);
	return (color);
}

unsigned int		color_degrade(t_env *env, double x, double y, int i)
{
	unsigned int color;

	if (env->max_iter == 0)
		return (BLACK);
	((unsigned char *)&color)[0]= i * env->red / env->max_iter;
	((unsigned char *)&color)[1] = i * env->green / env->max_iter;
	((unsigned char*)&color)[2] = i * env->blue / env->max_iter;

	return (color);
}

void		color_functions(t_env *env, double x, double y, int i)
{
	unsigned int		color;

	color = color_function[env->color_set](env, x, y, i);
	set_pixel(env, x, y, color);
}
