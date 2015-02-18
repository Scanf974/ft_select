/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdc_rinit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 22:31:07 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/18 12:45:30 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libldc.h"

void	ft_lstdc_rinit(t_lstrep **lst)
{
	if (*lst == NULL)
		*lst = (t_lstrep *)malloc(sizeof(t_lstrep));
	(*lst)->first = NULL;
	(*lst)->last = NULL;
	(*lst)->len = 0;
}
