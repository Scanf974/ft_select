/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdc_delfirst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 00:31:22 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/18 12:45:01 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libldc.h"

void	ft_lstdc_delfirst(t_lstrep **rep)
{
	void	*ptr;

	ptr = (*rep)->first->next;
	(*rep)->first->next->prev = (*rep)->last;
	(*rep)->last->next = (*rep)->first->next;
	free((*rep)->first);
	(*rep)->first = ptr;
	(*rep)->len--;
}
