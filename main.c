/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 05:34:11 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 16:47:57 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

t_win	*g_win;

static void	ft_attrape_moi_si_tu_peux(void)
{
	signal(SIGWINCH, ft_signal_handler);
	signal(SIGTSTP, ft_signal_handler);
	signal(SIGINT, ft_signal_handler);
	signal(SIGCONT, ft_signal_handler);
	signal(SIGTERM, ft_signal_handler);
	signal(SIGKILL, ft_signal_handler);
	signal(SIGQUIT, ft_signal_handler);
}

int		main(int argc, char **argv)
{
	char			*res;
	char			buf[4];

	if ((g_win = (t_win *)malloc(sizeof(t_win))) == NULL)
	{
		ft_putendl_fd("Malloc failed for g_win", 2);
		exit(1);
	}

	ft_attrape_moi_si_tu_peux();
	if (argc > 1)
	{
		g_win->list = ft_get_argv(argv);
		g_win->pos = 1;
		ft_get_info_for_win();
		ft_tcg(0);
		ft_make_instruction("vi", NULL);
		ft_make_instruction("cl", NULL);
		ft_print_argv();
		while (1)
		{
			ft_bzero(&buf, sizeof(char *));
			read(0, buf, 4);
			if (buf[0] == '\033')
			{
				if (buf[2] == 'A' || buf[2] == 'B' || buf[2] == 'C' || buf[2] == 'D')
					ft_move(buf[2]);
				if (buf[2] == 0)
				{
					ft_make_instruction("ho", NULL);
					ft_make_instruction("cd", NULL);
					ft_tcg(1);
					exit(0);
				}
			}
			else if (buf[0] == 8 || buf[0] == 127)
			{
				ft_del_link_by_id(g_win->pos - 1);
				ft_refresh();
			}
			else if (buf[0] == ' ') 
				ft_select();
			else if (buf[0] == '\n')
				ft_return();
		}
		if (close(g_win->fd) == -1)
		{
			ft_putendl_fd("main(): close tty failed", 2);
			exit(1);
		}
	}
	ft_tcg(1);
	return (0);
}
