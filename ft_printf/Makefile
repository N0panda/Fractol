# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ythomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 17:31:24 by ythomas           #+#    #+#              #
#    Updated: 2019/02/05 23:34:25 by ythomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_aff_resultat.c ft_get.c ft_printf.c ft_toa.c ft_flag.c ft_get_type.c \
	  ft_result_1.c ft_result_2.c tools.c ft_flag_2.c base.c ft_precision.c \
	  ft_free.c ft_float.c check_format.c \

DIR_OBJ = obj/

DIR_SRC = src/

LIBFT = libft/

INC = include

INCC = include/ft_printf.h

LIBA = libft/libft.a

FLAG  = -Werror -Wall -Wextra

SRCS = $(addprefix $(DIR_SRC), $(SRC))

OBJS =  $(addprefix $(DIR_OBJ), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIBA)
	@cp $(LIBA) ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(LIBA): FORCE
	@make -C $(LIBFT)

FORCE:

$(DIR_OBJ)%.o: $(DIR_SRC)%.c $(INCC)
	@mkdir -p $(DIR_OBJ)
	@gcc $(FLAG) -I $(INC) -o $@ -c $<

clean:
	@rm -rf $(DIR_OBJ)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

norm:
	snorminette $(SRCS)

re: fclean all

.PHONY : all, re, clean, fclean, norm
