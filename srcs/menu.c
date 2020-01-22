/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:37:23 by ythomas           #+#    #+#             */
/*   Updated: 2019/12/03 17:24:40 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			menu_max_iter(t_env *env)
{
	char	*str;
	char	*tmp;

	if ((str = ft_itoa(env->max_iter)) == NULL)
		return (0);
	if ((tmp = ft_strjoin("Max_iteration : ", str)) == NULL)
		return (0);
	free(str);
	mlx_string_put(env->mlx->ptr, env->mlx->window, 1200, 100,
		LIGHT_PINK, tmp);
	free(tmp);
	return (0);
}

int			menu_zoom(t_env *env)
{
	char *str;
	char *tmp;

	if ((str = ft_itoa(env->zoom_menu)) == NULL)
		return (0);
	if ((tmp = ft_strjoin("Zoom :  X ", str)) == NULL)
		return (0);
	free(str);
	mlx_string_put(env->mlx->ptr, env->mlx->window, 1200, 150,
		LIGHT_PINK, tmp);
	free(tmp);
	return (0);
}

int			menu_fractal_name(t_env *env)
{
	char *tmp;

	if ((tmp = ft_strjoin("Fractal : ", env->name)) == NULL)
		return (0);
	mlx_string_put(env->mlx->ptr, env->mlx->window, 1200, 20,
		DEEP_RED, tmp);
	free(tmp);
	return (0);
}

int			menu_captured(t_env *env)
{
	mlx_string_put(env->mlx->ptr, env->mlx->window, 1150, 600,
		DARK_PURPLE, "-----[C.A.P.T.U.R.E.D]-----");
	return (0);
}

int			menu_processor(t_env *env)
{
	if (env->processor == CPU)
		mlx_string_put(env->mlx->ptr, env->mlx->window, 1150, 500,
			DARK_PURPLE, "You are processing on : [.CPU.]");
	else
		mlx_string_put(env->mlx->ptr, env->mlx->window, 1150, 500,
			DARK_PURPLE, "You are processing on : [.GPU.]");
	return (0);
}
