/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 06:49:43 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/20 07:53:23 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

void	ft_move(t_win win, char c)
{
	static int	x;
	static int	y;
	char		*res;

	res = tgetstr("cm", NULL);
	if (c == 'A')
	{
		tputs(tgoto(res, x * (win.len_bigger + 1), y), 1, ft_outc);
		ft_putstr("\033[0m");
		ft_putstr(win.list->first->str);
		y--;
		win.list->first = win.list->first->prev;
	}
	else if (c == 'B')
	{
		tputs(tgoto(res, x * (win.len_bigger + 1), y), 1, ft_outc);
		ft_putstr("\033[0m");
		ft_putstr(win.list->first->str);
		y++;
		win.list->first = win.list->first->next;
	}
	else if (c == 'C')
		x++;
	else if (c == 'D')
		x--;
	if (x < 0)
		x = 0;
	if (y < 0 && x <= 0)
	{
		x = win.nb_argv / win.height;
		y = win.nb_argv % win.height - 1;
	}
	if (y < 0)
	{
		y = win.height - 1;
		x--;
	}
	if (y >= win.height)
	{
		x++;
		y = 0;
	}
	if (x * win.height + y + 1 > win.nb_argv)
	{
		x = 0;
		y = 0;
	}
	tputs(tgoto(res, x * (win.len_bigger + 1), y), 1, ft_outc);
	ft_putstr("\033[37;0;4m");
	ft_putstr(win.list->first->str);
	ft_putstr("\033[0m");
}
