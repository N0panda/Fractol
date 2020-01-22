# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ythomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/01 16:40:09 by ythomas           #+#    #+#              #
#    Updated: 2019/12/04 15:59:10 by ythomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc 

FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
FLAGS =
FLAGS_LIBX = -lmlx -framework OpenGL -framework AppKit

SRCS = main \
	   error \
	   get_params \
	   run_fractal \
	   get_key_mouse \
	   manage_image \
	   fractal_mandelbrot \
	   fractal_julia \
	   fractal_burningship \
	   fractal_feigenbaum \
	   fractal_leaf \
	   events \
	   mouse_event \
	   tools \
	   color \
	   menu	\
	   thread \

SRC_PATH = ./srcs/

LIB_DIR = ./ft_printf
HEAD_DIR = ./includes
OBJ_DIR = ./obj/
OBJ_NAME = obj
HEAD_PATH = $(HEAD_DIR)/$(HEAD)
OBJ	= $(patsubst %,$(OBJ_DIR)%.o,$(SRCS))

LIB = $(LIB_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ) $(MKDIR)
	$(CC)$(FLAGS) -o $(NAME) $(OBJ) $(LIB) $(FLAGS_LIBX) -I$(HEAD_PATH)

$(LIB): FORCE
	make -C $(LIB_DIR)

MKDIR: $(shell mkdir obj)

FORCE:

$(OBJ_DIR)%.o: $(SRC_PATH)%.c $(HEAD_PATH)
	$(CC) $(FLAGS) -c $< -o $@ -I$(HEAD_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all
