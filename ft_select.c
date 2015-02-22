/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 08:52:43 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 12:44:28 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_select(void)
{
	t_lstdc		*tmp;

	tmp = ft_get_link_by_id(win->pos - 1);
	tmp->selected = !tmp->selected;
	ft_move('B');
}
