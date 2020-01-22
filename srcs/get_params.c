/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:53:05 by ythomas           #+#    #+#             */
/*   Updated: 2019/12/04 15:01:41 by ythomas          ###   ########.fr       */
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

int			get_params(t_env *env, int ac, char **av)
{
	int i;

	if (ac != 2)
		return (ft_error(1, NULL));
	i = -1;
	while (g_fractal_names[++i])
		if (ft_strcmp(av[1], g_fractal_names[i]) == 0)
		{
			env->fractal = i;
			return (0);
		}
	return (ft_error(2, av[1]));
}
