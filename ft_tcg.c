/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tcg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 14:38:50 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/23 16:38:33 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

static void	ft_attention_a_toi_mec_ne_me_met_pas_zero_stp(void)
{
	if ((g_win->name_term = getenv("TERM")) == NULL)
	{
		ft_putendl_fd("env NULL getenv Failed", 2);
		exit(1);
	}
	if (tgetent(NULL, g_win->name_term) == -1)
	{
		ft_putendl_fd("env NULL tgetent Failed", 2);
		exit(1);
	}
	if ((g_win->fd = open(ttyname(STDIN_FILENO), O_RDWR)) == -1)
	{
		ft_putendl_fd("open tty Failed", 2);
		exit(1);
	}
	if (tcgetattr(g_win->fd, &g_win->term) == -1)
	{
		ft_putendl_fd("tcgetattr Failed", 2);
		exit(1);
	}
}

void		ft_tcg(char f)
{
	if (f == 0)
	{
		ft_attention_a_toi_mec_ne_me_met_pas_zero_stp();
		g_win->term.c_lflag &= ~(ICANON);
		g_win->term.c_lflag &= ~(ECHO);
		g_win->term.c_lflag |= ISIG;
		g_win->term.c_cc[VMIN] = 1;
		g_win->term.c_cc[VTIME] = 0;
		if (tcsetattr(g_win->fd, TCSADRAIN, &g_win->term) == -1)
		{
			ft_putendl_fd("tcsetattr Failed", 2);
			exit(1);
		}
	}
	else
	{
		g_win->term.c_lflag = g_win->term.c_lflag | ICANON;
		g_win->term.c_lflag = g_win->term.c_lflag | ECHO;
		g_win->term.c_lflag = g_win->term.c_lflag | ISIG;
		tcsetattr(g_win->fd, TCSADRAIN, &g_win->term);
		ft_make_instruction("ve", NULL);
	}
}
