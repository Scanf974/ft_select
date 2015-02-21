/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 05:34:11 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/21 22:22:10 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

char	**ar;
t_win	win;

int		main(int argc, char **argv)
{
	char			*res;
	char			buf[3];

	signal(SIGWINCH, ft_signal_handler);
	signal(SIGTSTP, ft_signal_handler);
	signal(SIGCONT, ft_signal_handler);
	ar = argv;
	if (argc > 1)
	{
		ft_tcg(0);

		//ft_make_instruction("vi", NULL);
		ft_make_instruction("cl", NULL);
		win = ft_refresh();
		res = tgetstr("cm", NULL);
		tputs(tgoto(res, 0, 0), 1, ft_outc);
		ft_make_instruction("us", NULL);
		ft_putstr(win.list->first->str);
		while (1)
		{
			read(0, buf, 3);
			if (buf[0] == '\033')
			{
				if (buf[2] == 'A' || buf[2] == 'B' || buf[2] == 'C' || buf[2] == 'D')
					ft_move(win, buf[2]);
			}
		}
	}
	ft_tcg(1);
	return (0);
}
