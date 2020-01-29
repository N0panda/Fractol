/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:50:12 by ythomas           #+#    #+#             */
/*   Updated: 2020/01/27 17:27:28 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_strerror(char *str)
{
	write(STDERR_FILENO, str, (size_t)ft_strlen(str));
}

void		menu_err(void)
{
	ft_printf("Error occured in texte menu allocation");
	exit(EXIT_FAILURE);
}

void		ft_error(int err, char *type_error)
{
	if (err == 1)
		ft_strerror("Bad Number of Parameters\n");
	else if (err == 2)
	{
		ft_strerror(type_error);
		ft_strerror(" : Is a bad Name of Params\n");
	}
	else if (err == 3)
		ft_strerror("Error occured during a Malloc");
	else if (err == 4)
		ft_strerror("Error with mlx image creation");
	exit(EXIT_FAILURE);
}
