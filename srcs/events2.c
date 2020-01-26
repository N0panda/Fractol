/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:22:16 by ythomas           #+#    #+#             */
/*   Updated: 2020/01/26 17:25:55 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		modify_paint_id(t_env *env, int key)
{
	if (key == 123)
	{
		env->id_paint -= 1;
		if (env->id_paint < 0)
			env->id_paint = NB_PALETTE - 2;
	}
	else if (key == 124)
	{
		env->id_paint += 1;
		if (env->id_paint >= NB_PALETTE - 1)
			env->id_paint = 0;
	}
	fill_buff_image(env);
}

void		negative_and_smooth(t_env *env, int key)
{
	if (key == 45)
	{
		if (env->negative == 0)
			env->negative = 1;
		else
			env->negative = 0;
	}
	else
	{
		if (env->smooth == 0)
			env->smooth = 1;
		else
			env->smooth = 0;
	}
	fill_buff_image(env);
}

void		random_color(t_env *env)
{
	int i;

	i = -1;
	while (++i < 6)
		env->paint[NB_PALETTE - 1][i] = rand() % 0xFFFFFF;
	env->red = rand() % 0xFF;
	env->green = rand() % 0xFF;
	env->blue = rand() % 0xFF;
	env->id_paint = NB_PALETTE - 1;
	fill_buff_image(env);
}

void		modify_number_of_colours(t_env *env, int key)
{
	if (key == 126 && env->color_set < COLOR_FUNC - 1)
		env->color_set += 1;
	else if (key == 125 && env->color_set > 0)
		env->color_set -= 1;
	fill_buff_image(env);
}

void		modify_uni_color(t_env *env, int key)
{
	if (key == 12)
	{
		env->red -= 2;
		if (env->red < 0)
			env->red = 255;
	}
	else if (key == 13)
	{
		env->green -= 2;
		if (env->green < 0)
			env->green = 255;
	}
	else
	{
		env->blue -= 2;
		if (env->blue < 0)
			env->blue = 255;
	}
	fill_buff_image(env);
}
