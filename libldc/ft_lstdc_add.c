/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdc_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 22:24:34 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/18 13:44:02 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libldc.h"

void	ft_lstdc_add(t_lstrep **rep, char *str)
{
	t_lstdc		*new;

	if (*rep == NULL)
	{
		*rep = (t_lstrep *)malloc(sizeof(t_lstrep));
		ft_lstdc_rinit(rep);
	}
	new = ft_lstdc_create(str);
	if ((*rep)->len == 0)
	{
		(*rep)->first = new;
		(*rep)->last = new;
	}
	else
	{
		new->next = (*rep)->first;
		new->prev = (*rep)->last;
		(*rep)->first->prev = new;
		(*rep)->last->next = new;
		(*rep)->first = new;
	}
	((*rep)->len)++;
}
