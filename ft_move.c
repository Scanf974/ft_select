/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 06:49:43 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 07:59:30 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

t_win	*win;

void	ft_move(char c)
{
	static int	x;
	static int	y;
	char		*res;

	res = tgetstr("cm", NULL);
	if (c == 'A')
	{
		tputs(tgoto(res, ((win->pos - 1) / win->height) * (win->len_bigger + 1), (win->pos - 1) % win->height), 1, ft_outc);
		ft_make_instruction("ue", NULL);
		ft_putstr(ft_get_link_by_id(win->pos - 1));
		win->pos--;
	}
	else if (c == 'B')
	{
		tputs(tgoto(res, ((win->pos - 1) / win->height) * (win->len_bigger + 1), (win->pos - 1) % win->height), 1, ft_outc);
		ft_putstr("\033[0m");
		ft_putstr(ft_get_link_by_id(win->pos - 1));
		win->pos++;
	}
	else if (c == 'C')
		x++;
	else if (c == 'D')
		x--;
	if (win->pos > win->nb_argv)
		win->pos = 1;
	if (win->pos == 0)
		win->pos = win->nb_argv;
	tputs(tgoto(res, ((win->pos - 1) / win->height) * (win->len_bigger + 1), (win->pos - 1) % win->height), 1, ft_outc);
	ft_make_instruction("us", NULL);
	ft_putstr(ft_get_link_by_id(win->pos - 1));
	ft_make_instruction("ue", NULL);
}
