/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:34:42 by ythomas           #+#    #+#             */
/*   Updated: 2019/12/04 17:34:06 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "color_set.h"
# include "../ft_printf/include/ft_printf.h"
# include <pthread.h>
# include <math.h>

# define H_SCREEN		720.0
# define W_SCREEN		1480.0
# define H_IMAGE		720.0
# define W_IMAGE		1080.0
# define H_MENU			720
# define W_MENU			400
# define PIX_IMAGE		W_IMAGE * H_IMAGE

# define GPU			1
# define CPU			0
# define NB_THREAD		8

# define FROZEN			2
# define DEFROST		1
# define WORKING		1
# define PENDING		2
# define VISIBLE		0
# define HIDDEN			1

typedef struct s_env	t_env;
typedef	void (*t_func)(t_env*, double, double);
typedef void (*init_func)(t_env*);
typedef unsigned int (*t_color)(t_env*, double, double, int);

typedef struct		s_mlx
{
	void			*ptr;
	void			*window;
	void			*img_ptr;
	void			*menu_ptr;
	char			*img_str;
	char			*menu_str;
	int				h_screen;
	int				w_screen;
}					t_mlx;

struct				s_env
{
	int				processor;

	int				fractal;
	char			*name;
	int				mouse;
	int				freeze;
	int				color_set;

	int				color;
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;

	double			zoom;
	double			x_min;
	double			y_min;
	double			c_r;
	double			c_i;
	int				zoom_menu;
	int				max_iter;
	int				*start_thr;
	int				hidden_menu;

	t_mlx			*mlx;
};

typedef struct		s_fractals
{
	char			*name;
	int				mouse;
}					t_fractals;

void				thread_test(t_env *env);

int					get_params(t_env *env, int ac, char **av);
int					ft_error(int err, char *type_error);
int					run_fractal(t_env *env);
int					get_key_event(int key, t_env *env);
int					get_mouse_event(int key, int x, int y,t_env *env);
int					julia_position_mouse(int x, int y, t_env *env);

void				modify_max_iter(t_env *env, int stat);
void				reset_fractal(t_env *env);
void				zoom(double x, double y, t_env *env, int stat);
void				freeze_defreeze(t_env *env, int stat);
void				change_fractal(t_env *env, int key);
void				change_processor(t_env *env, int key);
void				deal_with_hidden_menu(t_env *env);

int					menu_max_iter(t_env *env);
int					menu_zoom(t_env *env);
int					menu_fractal_name(t_env *env);
int					menu_captured(t_env *env);
int					menu_processor(t_env *env);

int					ft_creat_image(t_mlx *mlx);
void				push_image(t_env *env);
void				set_pixel(t_env *env, int x, int y, unsigned int color);
int					fill_buff_image_CPU(t_env *env);
int					fill_buff_image(t_env *env);

void				f_mandelbrot(t_env *env, double x, double y);
void				f_julia(t_env *env, double x, double y);
void				f_burningship(t_env *env, double x, double y);
void				f_leaf(t_env *env, double x, double y);
void				f_feigenbaum(t_env *env, double x, double y);
void				init_mandelbrot(t_env *env);
void				init_julia(t_env *env);
void				init_burningship(t_env *env);
void				init_leaf(t_env *env);
void				init_feigenbaum(t_env *env);

void				color_functions(t_env *env, double x, double y, int i);
unsigned int		color_degrade(t_env *env, double x, double y, int i);

double				ft_abs(double nb);
#endif
