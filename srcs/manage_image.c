/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:46:33 by ythomas           #+#    #+#             */
/*   Updated: 2020/01/26 17:43:44 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_creat_image(t_mlx *mlx)
{
	int endian;
	int size_line;
	int bpp;
	int	size_menu;

	bpp = 32;
	endian = 0;
	size_line = 4 * W_IMAGE;
	size_menu = 4 * W_MENU;
	mlx->img_ptr = mlx_new_image(mlx->ptr, W_IMAGE, H_IMAGE);
	mlx->img_str = mlx_get_data_addr(mlx->img_ptr, &bpp,
		&size_line, &endian);
	mlx->menu_ptr = mlx_new_image(mlx->ptr, W_MENU, H_MENU);
	mlx->menu_str = mlx_get_data_addr(mlx->menu_ptr, &bpp, &size_menu, &endian);
	return (0);
}

void		put_menu(t_env *env)
{
	menu_fractal_name(env);
	menu_max_iter(env);
	menu_zoom(env);
	menu_negative_smooth(env);
	if (env->color_set == 0)
		menu_uni_color(env);
	if (env->mouse == 2)
		menu_captured(env);
	menu_processor(env);
}

void		push_image(t_env *env)
{
	mlx_put_image_to_window(env->mlx->ptr, env->mlx->window,
		env->mlx->img_ptr, 0, 0);
	mlx_put_image_to_window(env->mlx->ptr, env->mlx->window,
		env->mlx->menu_ptr, 1080, 0);
	if (env->hidden_menu == VISIBLE)
		put_menu(env);
}

void		set_pixel(t_env *env, int x, int y, unsigned int color)
{
	int	px;
	int py;
	int pos;

	px = x * 4;
	py = y * 4 * W_IMAGE;
	pos = px + py;
	env->mlx->img_str[pos] = ((unsigned char *)&color)[0];
	env->mlx->img_str[pos + 1] = ((unsigned char *)&color)[1];
	env->mlx->img_str[pos + 2] = ((unsigned char *)&color)[2];
}

int			fill_buff_image(t_env *env)
{
	if (env->help == 1)
	{
		display_help(env);
		return (0);
	}
	if (env->processor == CPU)
		fill_buff_image_cpu(env);
	else
		return (0);
	return (0);
}
