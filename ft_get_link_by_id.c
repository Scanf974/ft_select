/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_link_by_id.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 05:21:16 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 07:38:12 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_win	*win;

char	*ft_get_link_by_id(size_t id)
{
	size_t	i;
	t_lstdc	*tmp;

	i = 0;
	tmp = win->list->first;
	while (i++ < id)
		tmp = tmp->next;
	return (tmp->str);
}
