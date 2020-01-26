/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:38:14 by ythomas           #+#    #+#             */
/*   Updated: 2020/01/26 17:52:17 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static const	t_fractals g_frac[] =
{
	{"Mandelbrot", 0},
	{"Julia", 1},
	{"Burningship", 0},
	{"Feigenbaum", 0},
	{"Leaf", 0}
};

void			setup_color(int **paint)
{
	paint[0][0] = BLACK;
	paint[0][1] = PURPLE;
	paint[0][2] = DARK_PURPLE;
	paint[0][3] = LIGHT_PINK;
	paint[0][4] = BLUE;
	paint[0][5] = PINK_LADY;
	paint[1][0] = 0xFD085A;
	paint[1][1] = 0x9E9D3C;
	paint[1][2] = 0xF3FD1A;
	paint[1][3] = 0xFF0000;
	paint[1][4] = 0x27C4F7;
	paint[1][5] = BLACK;
	paint[2][0] = 0x17ffca;
	paint[2][1] = 0x4b8aec;
	paint[2][2] = 0x701a1a;
	paint[2][3] = 0xce6ae1;
	paint[2][4] = 0xd7a671;
	paint[2][5] = 0xfff800;
}

int				**init_paint_tab(void)
{
	int		**paint;
	int		i;

	if (!(paint = ft_memalloc(sizeof(void *) * NB_PALETTE)))
		return (NULL);
	i = -1;
	while (++i < NB_PALETTE)
		if (!(paint[i] = ft_memalloc(sizeof(int *) * 6)))
			return (NULL);
	setup_color(paint);
	return (paint);
}

int				get_the_right_setup(t_env *env)
{
	env->mouse = g_frac[env->fractal].mouse;
	env->name = ft_strdup(g_frac[env->fractal].name);
	env->processor = CPU;
	env->hidden_menu = VISIBLE;
	env->color_set = 1;
	env->id_paint = 0;
	env->smooth = 0;
	env->negative = 0;
	env->uni_color = WHITE;
	env->help = 0;
	if (((env->paint = init_paint_tab()) == NULL))
		return (-1);
	env->red = ((unsigned char *)&env->uni_color)[0];
	env->green = ((unsigned char *)&env->uni_color)[1];
	env->blue = ((unsigned char *)&env->uni_color)[2];
	if (!(env->start_thr = malloc(sizeof(int) * NB_THREAD)))
		return (-1);
	return (0);
}

int				main(int ac, char **av)
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
