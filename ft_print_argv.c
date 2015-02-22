/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 16:28:54 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 15:40:08 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

t_win	*win;

void	ft_print_argv(void)
{
	size_t		i;
	char		*res;
	t_lstdc		*tmp;

	i = 0;
	while (win->list && i < win->list->len)
	{
		tmp = ft_get_link_by_id(i);
		res = tgetstr("cm", NULL);
		tputs(tgoto(res, (i / win->height) * (win->len_bigger + 1), i % win->height), 1, ft_outc);
		if (tmp->selected)
			ft_make_instruction("so", NULL);
		ft_putstr(ft_get_link_by_id(i)->str);
		ft_make_instruction("se", NULL);
		i++;
		if (i > win->nb_argv)
			i = 1;
	}
	tputs(tgoto(res, ((win->pos - 1) / win->height) * (win->len_bigger + 1), (win->pos - 1) % win->height), 1, ft_outc);
	if (tmp->selected)
		ft_make_instruction("so", NULL);
	ft_make_instruction("us", NULL);
	ft_putstr(ft_get_link_by_id(win->pos - 1)->str);
	ft_make_instruction("ue", NULL);
	ft_make_instruction("se", NULL);
}
