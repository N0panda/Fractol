/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:37:35 by ythomas           #+#    #+#             */
/*   Updated: 2019/01/30 15:37:38 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free_list(t_param *list)
{
	if (list->next != NULL)
		ft_free_list(list->next);
	free(list->result);
	free(list->flag);
	free(list);
}
