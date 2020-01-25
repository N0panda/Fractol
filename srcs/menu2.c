/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 17:28:36 by ythomas           #+#    #+#             */
/*   Updated: 2020/01/25 18:20:46 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			menu_uni_color(t_env *env)
{
	char	*red;
	char	*green;
	char	*blue;

	if (!(red = ft_itoa(env->red)))
		return (-1);
	if (!(green = ft_itoa(env->green)))
		return (-1);
	if (!(blue = ft_itoa(env->blue)))
		return (-1);
	mlx_string_put(env->mlx->ptr, env->mlx->window, 1200, 230, WHITE, "RGB for one color mod");
	mlx_string_put(env->mlx->ptr, env->mlx->window, 1250, 250, RED, red);
	mlx_string_put(env->mlx->ptr, env->mlx->window, 1250, 265, GREEN, green);
	mlx_string_put(env->mlx->ptr, env->mlx->window, 1250, 280, BLUE, blue);
	free(red);
	free(green);
	free(blue);
	return (0);
}
