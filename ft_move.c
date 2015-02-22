/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 06:49:43 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 17:20:51 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

t_win	*g_win;

void	ft_move(char c)
{
	char		*res;
	t_lstdc		*tmp;

	tmp = ft_get_link_by_id(g_win->pos - 1);
	res = tgetstr("cm", NULL);
	if (c == 'A')
	{
		tputs(tgoto(res, ((g_win->pos - 1) / g_win->height) * (g_win->len_bigger + 1), (g_win->pos - 1) % g_win->height), 1, ft_outc);
		ft_make_instruction("ue", NULL);
		if (tmp->selected == 1)
			ft_make_instruction("so", NULL);
		ft_putstr_fd(ft_get_link_by_id(g_win->pos - 1)->str, g_win->fd);
		ft_make_instruction("se", NULL);
		g_win->pos--;
	}
	else if (c == 'B')
	{
		tputs(tgoto(res, ((g_win->pos - 1) / g_win->height) * (g_win->len_bigger + 1), (g_win->pos - 1) % g_win->height), 1, ft_outc);
		if (tmp->selected == 1)
			ft_make_instruction("so", NULL);
		ft_putstr_fd(ft_get_link_by_id(g_win->pos - 1)->str, g_win->fd);
		ft_make_instruction("se", NULL);
		g_win->pos++;
	}
	else if (c == 'C' && g_win->pos + g_win->raw <= g_win->list->len)
	{
		tputs(tgoto(res, ((g_win->pos - 1) / g_win->height) * (g_win->len_bigger + 1), (g_win->pos - 1) % g_win->height), 1, ft_outc);
		if (tmp->selected == 1)
			ft_make_instruction("so", NULL);
		ft_putstr_fd(ft_get_link_by_id(g_win->pos - 1)->str, g_win->fd);
		ft_make_instruction("se", NULL);
		g_win->pos += g_win->height;
	}
	else if (c == 'D' && g_win->pos - g_win->raw < g_win->raw)
	{
		tputs(tgoto(res, ((g_win->pos - 1) / g_win->height) * (g_win->len_bigger + 1), (g_win->pos - 1) % g_win->height), 1, ft_outc);
		if (tmp->selected == 1)
			ft_make_instruction("so", NULL);
		ft_putstr_fd(ft_get_link_by_id(g_win->pos - 1)->str, g_win->fd);
		ft_make_instruction("se", NULL);
		g_win->pos -= g_win->height;
	}
	if (g_win->pos > g_win->nb_argv)
		g_win->pos = 1;
	if (g_win->pos == 0)
		g_win->pos = g_win->nb_argv;
	tputs(tgoto(res, ((g_win->pos - 1) / g_win->height) * (g_win->len_bigger + 1), (g_win->pos - 1) % g_win->height), 1, ft_outc);
	tmp = ft_get_link_by_id(g_win->pos - 1);

	if (tmp->selected == 1)
		ft_make_instruction("so", NULL);
	ft_make_instruction("us", NULL);
	ft_putstr_fd(ft_get_link_by_id(g_win->pos - 1)->str, g_win->fd);
	ft_make_instruction("ue", NULL);
	ft_make_instruction("se", NULL);
}
