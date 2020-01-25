/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:27:46 by ythomas           #+#    #+#             */
/*   Updated: 2020/01/25 18:46:31 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	color_degrade_two(t_env *env, int i, int x, int y)
{
	unsigned int	color;
	if (env->max_iter <= 0)
		return (BLACK);
	((unsigned char *)&color)[0]  = i * ((unsigned char *)&env->paint[x][y])[0] / env->max_iter;
	((unsigned char *)&color)[1]  = i * ((unsigned char *)&env->paint[x][y])[1] / env->max_iter;
	((unsigned char *)&color)[2]  = i * ((unsigned char *)&env->paint[x][y])[2] / env->max_iter;
	return (color);
}

double			ft_abs(double nb)
{
	if (nb < 0.0)
		return (nb * -1.0);
	return (nb);
}
