/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:11:14 by ythomas           #+#    #+#             */
/*   Updated: 2020/01/25 13:08:04 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static const t_func g_func[] =
{
	f_mandelbrot,
	f_julia,
	f_burningship,
	f_feigenbaum,
	f_leaf
};

static const init_func g_init[] =
{
	init_mandelbrot,
	init_julia,
	init_burningship,
	init_feigenbaum,
	init_leaf
};

int				init_mlx(t_env *env)
{
	if (!(env->mlx = ft_memalloc(sizeof(t_mlx))))
		return (-1);
	env->mlx->ptr = mlx_init();
	env->mlx->window = mlx_new_window(env->mlx->ptr, W_SCREEN, H_SCREEN, env->name);
	g_init[env->fractal](env);
	return (0);
}

int				run_fractal(t_env *env)
{
	init_mlx(env);
	ft_creat_image(env->mlx);
	fill_buff_image(env);
	mlx_hook(env->mlx->window, 2, (1L << 0), get_key_event, env);
	mlx_hook(env->mlx->window, 4, 0, get_mouse_event, env);
	mlx_hook(env->mlx->window, 6, 0, julia_position_mouse, env);
	mlx_loop(env->mlx->ptr);
	return (0);
}
