/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_link_by_id.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 06:12:30 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 08:07:46 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_win	*win;

void	ft_del_link_by_id(size_t id)
{
	t_lstdc	*tmp;
	t_lstdc	*prev;
	t_lstdc	*next;
	size_t	i;

	i = 0;
	tmp = win->list->first;
	while (i++ < id)
		tmp = tmp->next;
	prev = tmp->prev;
	next = tmp->next;
	prev->next = next;
	next->prev = prev;
	win->list->len--;
}
