/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_link_by_id.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 06:12:30 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 16:50:51 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_win	*g_win;

void	ft_del_link_by_id(size_t id)
{
	t_lstdc	*tmp;
	t_lstdc	*prev;
	t_lstdc	*next;
	size_t	i;

	i = 0;
	tmp = g_win->list->first;
	while (i++ < id)
		tmp = tmp->next;
	prev = tmp->prev;
	next = tmp->next;
	prev->next = next;
	next->prev = prev;
	g_win->list->len--;
}
