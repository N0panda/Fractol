/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:31:51 by ythomas           #+#    #+#             */
/*   Updated: 2020/01/27 17:10:01 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int			get_mouse_event(int key, int x, int y, t_env *env)
{
	if (key == 4)
		zoom((double)x, (double)y, env, 0);
	else if (key == 5)
		zoom((double)x, (double)y, env, 1);
	else if (key == 1 && env->mouse == PENDING && env->freeze == FROZEN)
		freeze_defreeze(env, 0);
	else if (key == 2 && env->mouse == WORKING && env->freeze == DEFROST)
		freeze_defreeze(env, 1);
	return (0);
}

int			get_key_event(int key, t_env *env)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 78)
		modify_max_iter(env, 0);
	else if (key == 69)
		modify_max_iter(env, 1);
	else if (key == 49)
		reset_fractal(env);
	else if (key == 83 || key == 84 || key == 85 || key == 86 || key == 87)
		change_fractal(env, key);
	else if (key == 8 || key == 5)
		change_processor(env, key);
	else if (key == 4 || key == 35)
		deal_with_hidden_menu(env, key);
	else if (key == 123 || key == 124)
		modify_paint_id(env, key);
	else if (key == 125 || key == 126)
		modify_number_of_colours(env, key);
	else if (key == 12 || key == 13 || key == 14)
		modify_uni_color(env, key);
	else if (key == 15)
		random_color(env);
	else if (key == 45 || key == 46)
		negative_and_smooth(env, key);
	return (0);
}

int			julia_position_mouse(int x, int y, t_env *env)
{
	if (env->mouse != WORKING)
		return (0);
	env->c_r = x / W_IMAGE;
	env->c_i = y / W_IMAGE;
	fill_buff_image(env);
	return (0);
}
