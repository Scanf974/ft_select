/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 06:49:43 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/20 06:59:00 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

void	ft_move(t_win win, char c)
{
	static int	x;
	static int	y;
	char		*res;

	if (c == 'A')
		y--;
	else if (c == 'B')
		y++;
	else if (c == 'C')
		x++;
	else if (c == 'D')
		x--;
	if (x < 0)
		x = 0;
	res = tgetstr("cm", NULL);
	tputs(tgoto(res, x * (win.len_bigger + 1), y), 1, ft_outc);
}
