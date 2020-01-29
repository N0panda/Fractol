/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:05:08 by ythomas           #+#    #+#             */
/*   Updated: 2020/01/27 17:44:59 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			push_help(t_env *env)
{
	ft_bzero(env->mlx->img_str, W_IMAGE * H_IMAGE * 4);
	mlx_put_image_to_window(env->mlx->ptr, env->mlx->window,
		env->mlx->img_ptr, 0, 0);
	mlx_put_image_to_window(env->mlx->ptr, env->mlx->window,
		env->mlx->menu_ptr, 1080, 0);
}

static int		display_suite(t_env *env)
{
	mlx_string_put(env->mlx->ptr, env->mlx->window, 50, 310, WHITE,
		"Swap between fractal with :             [1] [2] [3] [4] [5]...");
	mlx_string_put(env->mlx->ptr, env->mlx->window, 50, 340, WHITE,
		"Capture an image on Julia fractal[2] :  [RIGHT CLICK]");
	mlx_string_put(env->mlx->ptr, env->mlx->window, 50, 370, WHITE,
		"Realease a capture :                    [LEFT CLICK]");
	mlx_string_put(env->mlx->ptr, env->mlx->window, 50, 400, WHITE,
		"zoom inside fractal :                   [MOUSE WHEEL]");
	mlx_string_put(env->mlx->ptr, env->mlx->window, 50, 430, WHITE,
		"In one color mod, change RGB values :   [Q] [W] [E]");
	mlx_string_put(env->mlx->ptr, env->mlx->window, 50, 460, WHITE,
		"QUIT :                                  [ESC]");
	mlx_string_put(env->mlx->ptr, env->mlx->window, 50, 490, WHITE,
		"Switch GPU / CPU mod (not done yet) :   [G] [C]");
	mlx_string_put(env->mlx->ptr, env->mlx->window, 485, 580,
		DEEP_RED, "<-----[ Press [p] to close help ]----->");
	return (0);
}

int				display_help(t_env *env)
{
	push_help(env);
	mlx_string_put(env->mlx->ptr, env->mlx->window, 550, 20,
		DEEP_RED, "<-----[ HELP MENU ]----->");
	mlx_string_put(env->mlx->ptr, env->mlx->window, 50, 100, WHITE,
		"Increase or decrease Max iteration :    [+] or [-] (num)");
	mlx_string_put(env->mlx->ptr, env->mlx->window, 50, 130, WHITE,
		"Reset a fractal :                       [SPACE]");
	mlx_string_put(env->mlx->ptr, env->mlx->window, 50, 160, WHITE,
		"Change the color set :                  [LEFT] [RIGHT]");
	mlx_string_put(env->mlx->ptr, env->mlx->window, 50, 190, WHITE,
		"Increase or decrease color amount :     [TOP] [BOT]");
	mlx_string_put(env->mlx->ptr, env->mlx->window, 50, 220, WHITE,
		"Randomize a color set :                 [R]");
	mlx_string_put(env->mlx->ptr, env->mlx->window, 50, 250, WHITE,
		"Switch to negative color mod :          [N]");
	mlx_string_put(env->mlx->ptr, env->mlx->window, 50, 280, WHITE,
		"Switch to Smooth color mod :            [M]");
	display_suite(env);
	return (0);
}
