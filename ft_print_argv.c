/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 16:28:54 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 04:20:14 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

t_win	win;

void	ft_print_argv(void)
{
	size_t		i;
	char		*res;

	i = 0;
	while (win.list && win.list->first && i < win.list->len)
	{
		res = tgetstr("cm", NULL);
		tputs(tgoto(res, ((win.pos - 1) / win.height) * (win.len_bigger + 1), (win.pos - 1) % win.height), 1, ft_outc);
		ft_putstr(win.list->first->str);
		win.list->first = win.list->first->next;
		win.pos++;
		if (win.pos > win.nb_argv)
			win.pos = 1;
		i++;
	}
	tputs(tgoto(res, ((win.pos - 1) / win.height) * (win.len_bigger + 1), (win.pos - 1) % win.height), 1, ft_outc);
	ft_make_instruction("us", NULL);
	ft_putstr(win.list->first->str);
	ft_make_instruction("ue", NULL);
}
