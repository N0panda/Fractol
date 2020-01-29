/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:11:14 by ythomas           #+#    #+#             */
/*   Updated: 2020/01/27 17:46:22 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static const t_init_func g_init[] =
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
	if ((env->mlx->ptr = mlx_init()) == NULL)
		return (-1);
	if (!(env->mlx->window = mlx_new_window(env->mlx->ptr, W_SCREEN,
		H_SCREEN, env->name)))
		return (-1);
	g_init[env->fractal](env);
	return (0);
}

void			run_fractal(t_env *env)
{
	if (init_mlx(env) == -1)
		ft_error(4, NULL);
	if ((ft_creat_image(env->mlx)) == -1)
		ft_error(4, NULL);
	fill_buff_image(env);
	mlx_hook(env->mlx->window, 2, (1L << 0), get_key_event, env);
	mlx_hook(env->mlx->window, 4, 0, get_mouse_event, env);
	mlx_hook(env->mlx->window, 6, 0, julia_position_mouse, env);
	mlx_loop(env->mlx->ptr);
}
