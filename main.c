/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 05:34:11 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 12:12:31 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

t_win	*win;

int		main(int argc, char **argv)
{
	char			*res;
	char			buf[4];

	strlen("spoidjf");
	win = (t_win *)malloc(sizeof(t_win));
	signal(SIGWINCH, ft_signal_handler);
	signal(SIGTSTP, ft_signal_handler);
	signal(SIGCONT, ft_signal_handler);
	if (argc > 1)
	{
		win->list = ft_get_argv(argv);
		win->pos = 1;
		ft_get_info_for_win();
		ft_tcg(0);
		//ft_make_instruction("vi", NULL);
		ft_make_instruction("cl", NULL);
		ft_print_argv();
		while (1)
		{
			read(0, buf, 4);
			if (buf[0] == '\033')
			{
				if (buf[2] == 'A' || buf[2] == 'B' || buf[2] == 'C' || buf[2] == 'D')
					ft_move(buf[2]);
			}
			else if (buf[0] == 8 || buf[0] == 127)
			{
				ft_del_link_by_id(win->pos - 1);
				ft_refresh();
			}
			else if (buf[0] == ' ') 
				ft_select();
		}
	}
	ft_tcg(1);
	return (0);
}
