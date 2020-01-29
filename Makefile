# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ythomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/01 16:40:09 by ythomas           #+#    #+#              #
#    Updated: 2020/01/29 13:32:17 by ythomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc 

FLAGS = -Wall -Wextra -Werror
FLAGS_LIBX = -lmlx -framework OpenGL -framework AppKit

SRCS = main.c \
	   error.c \
	   get_params.c \
	   run_fractal.c \
	   get_key_mouse.c \
	   manage_image.c \
	   fractal_mandelbrot.c \
	   fractal_julia.c \
	   fractal_burningship.c \
	   fractal_feigenbaum.c \
	   fractal_leaf.c \
	   events.c \
	   events2.c \
	   mouse_event.c \
	   tools.c \
	   color.c \
	   menu.c	\
	   menu2.c \
	   help_menu.c \
	   thread.c \

SRC_PATH = ./srcs/

LIB_DIR = ./ft_printf
HEAD_DIR = ./includes
OBJ_DIR = ./obj/
OBJ_NAME = obj
HEAD_PATH = $(HEAD_DIR)/$(HEAD)
OBJ	= $(SRCS:%c=$(OBJ_DIR)%o)

LIB = $(LIB_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ_DIR) $(SRC) $(OBJ)
	$(CC)$(FLAGS) -o $(NAME) $(OBJ) $(LIB) $(FLAGS_LIBX) -I$(HEAD_PATH)

$(LIB): FORCE
	make -C $(LIB_DIR)

FORCE:

$(OBJ_DIR)%.o: $(SRC_PATH)%.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(HEAD_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all
