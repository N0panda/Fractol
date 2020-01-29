/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:53:05 by ythomas           #+#    #+#             */
/*   Updated: 2020/01/27 16:58:05 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static const char		*g_fractal_names[] = {
	"Mandelbrot",
	"Julia",
	"Burningship",
	"Feigenbaum",
	"Leaf"
};

void					get_params(t_env *env, int ac, char **av)
{
	int i;

	if (ac != 2)
		ft_error(1, NULL);
	i = -1;
	while (g_fractal_names[++i])
		if (ft_strcmp(av[1], g_fractal_names[i]) == 0)
		{
			env->fractal = i;
			return ;
		}
	ft_error(2, av[1]);
}
