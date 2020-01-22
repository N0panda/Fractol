/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:58:47 by ythomas           #+#    #+#             */
/*   Updated: 2019/12/04 17:56:22 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_color		color_function[] = {
	color_degrade
};

unsigned int		color_degrade(t_env *env, double x, double y, int i)
{
	unsigned int color;

	if (env->max_iter == 0)
		return (BLACK);
	((unsigned char *)&color)[0]= i * ((unsigned char *)&env->color)[0] / env->max_iter;
	((unsigned char *)&color)[1] = i * ((unsigned char *)&env->color)[1] / env->max_iter;
	((unsigned char*)&color)[2] = i * ((unsigned char *)&env->color)[2] / env->max_iter;

	return (color);
}

void		color_functions(t_env *env, double x, double y, int i)
{
	unsigned int		color;

	color = color_function[env->color_set](env, x, y, i);
	set_pixel(env, x, y, color);
}
