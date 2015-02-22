/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 06:49:43 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 03:27:19 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

t_win	win;

void	ft_move(char c)
{
	static int	x;
	static int	y;
	char		*res;

	res = tgetstr("cm", NULL);
	if (c == 'A')
	{
		tputs(tgoto(res, ((win.pos - 1) / win.height) * (win.len_bigger + 1), (win.pos - 1) % win.height), 1, ft_outc);
		ft_make_instruction("ue", NULL);
		ft_putstr(win.list->first->str);
		win.pos--;
		win.list->first = win.list->first->prev;
	}
	else if (c == 'B')
	{
		tputs(tgoto(res, ((win.pos - 1) / win.height) * (win.len_bigger + 1), (win.pos - 1) % win.height), 1, ft_outc);
		ft_putstr("\033[0m");
		ft_putstr(win.list->first->str);
		win.pos++;
		win.list->first = win.list->first->next;
	}
	else if (c == 'C')
		x++;
	else if (c == 'D')
		x--;
	if (win.pos > win.nb_argv)
		win.pos = 1;
	if (win.pos == 0)
		win.pos = win.nb_argv;
	tputs(tgoto(res, ((win.pos - 1) / win.height) * (win.len_bigger + 1), (win.pos - 1) % win.height), 1, ft_outc);
	ft_make_instruction("us", NULL);
	ft_putstr(win.list->first->str);
	ft_make_instruction("ue", NULL);
}
