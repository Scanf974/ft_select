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
	t_lstrep	tmp;

	tmp = *rep;
	i = 0;
	if (i < tmp.len && tmp.first->next)
	{
		tmp.first = tmp.first->next;
		while (i < tmp.len)
		{
			ft_putstr(tmp.first->str);
			tmp.first = tmp.first->next;
			i++;
			if (i != tmp.len)
				ft_putchar('\n');
		}
	}
}
