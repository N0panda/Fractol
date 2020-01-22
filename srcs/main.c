/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:38:14 by ythomas           #+#    #+#             */
/*   Updated: 2019/12/04 18:04:06 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static const	t_fractals frac[] =
{
	{"Mandelbrot", 0},
	{"Julia", 1},
	{"Burningship", 0},
	{"Feigenbaum", 0},
	{"Leaf", 0}
};

int			get_the_right_setup(t_env *env)
{
	int i;

	env->mouse = frac[env->fractal].mouse;
	env->name = ft_strdup(frac[env->fractal].name);
	env->processor = CPU;
	env->hidden_menu = VISIBLE;
	env->color_set = 0;
	env->color = BLUE;
	env->red = ((unsigned char *)&env->color)[0];
	env->green = ((unsigned char *)&env->color)[1];
	env->blue = ((unsigned char *)&env->color)[2];
	if (!(env->start_thr = malloc(sizeof(int) * NB_THREAD)))
		return (-1);
	return (0);
}

int			main(int ac, char **av)
{
	t_env env;

	if (get_params(&env, ac, av) == -1)
		return (-1);
	if (get_the_right_setup(&env) == -1)
		return (-1);
	if (run_fractal(&env) == -1)
		return (-1);
	return (0);
}
