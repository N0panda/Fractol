/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:50:12 by ythomas           #+#    #+#             */
/*   Updated: 2020/01/26 17:23:28 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_strerror(char *str)
{
	write(STDERR_FILENO, str, (size_t)ft_strlen(str));
}

int			ft_error(int err, char *type_error)
{
	if (err == 1)
		ft_strerror("Bad Number of Parameters\n");
	else if (err == 2)
	{
		ft_strerror(type_error);
		ft_strerror(" : Is a bad Name of Params\n");
	}
	return (-1);
}
