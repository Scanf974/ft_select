/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdc_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 23:21:01 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/18 14:53:44 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libldc.h"
#include <stdio.h>

void	ft_lstdc_print(t_lstrep *rep)
{
	size_t		i;

	i = 0;
	while (rep && rep->first && i < rep->len)
	{
		ft_putstr(rep->first->str);
		rep->first = rep->first->next;
		i++;
		if (i != rep->len)
			ft_putchar('\n');
	}
}
