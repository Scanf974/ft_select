/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 06:49:43 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 14:21:46 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

t_win	*win;

void	ft_move(char c)
{
	char		*res;
	t_lstdc		*tmp;

	tmp = ft_get_link_by_id(win->pos - 1);
	res = tgetstr("cm", NULL);
	if (c == 'A')
	{
		tputs(tgoto(res, ((win->pos - 1) / win->height) * (win->len_bigger + 1), (win->pos - 1) % win->height), 1, ft_outc);
		ft_make_instruction("ue", NULL);
		if (tmp->selected == 1)
			ft_make_instruction("so", NULL);
		ft_putstr(ft_get_link_by_id(win->pos - 1)->str);
		ft_make_instruction("se", NULL);
		win->pos--;
	}
	else if (c == 'B')
	{
		tputs(tgoto(res, ((win->pos - 1) / win->height) * (win->len_bigger + 1), (win->pos - 1) % win->height), 1, ft_outc);
		if (tmp->selected == 1)
			ft_make_instruction("so", NULL);
		ft_putstr(ft_get_link_by_id(win->pos - 1)->str);
		ft_make_instruction("se", NULL);
		win->pos++;
	}
	else if (c == 'C' && win->pos + win->raw <= win->list->len)
	{
		tputs(tgoto(res, ((win->pos - 1) / win->height) * (win->len_bigger + 1), (win->pos - 1) % win->height), 1, ft_outc);
		if (tmp->selected == 1)
			ft_make_instruction("so", NULL);
		ft_putstr(ft_get_link_by_id(win->pos - 1)->str);
		ft_make_instruction("se", NULL);
		win->pos += win->height;
	}
	else if (c == 'D' && win->pos - win->raw < win->raw)
	{
		tputs(tgoto(res, ((win->pos - 1) / win->height) * (win->len_bigger + 1), (win->pos - 1) % win->height), 1, ft_outc);
		if (tmp->selected == 1)
			ft_make_instruction("so", NULL);
		ft_putstr(ft_get_link_by_id(win->pos - 1)->str);
		ft_make_instruction("se", NULL);
		win->pos -= win->height;
	}
	if (win->pos > win->nb_argv)
		win->pos = 1;
	if (win->pos == 0)
		win->pos = win->nb_argv;
	tputs(tgoto(res, ((win->pos - 1) / win->height) * (win->len_bigger + 1), (win->pos - 1) % win->height), 1, ft_outc);
	tmp = ft_get_link_by_id(win->pos - 1);

	if (tmp->selected == 1)
		ft_make_instruction("so", NULL);
	ft_make_instruction("us", NULL);
	ft_putstr(ft_get_link_by_id(win->pos - 1)->str);
	ft_make_instruction("ue", NULL);
	ft_make_instruction("se", NULL);
}
