/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 04:09:15 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 17:02:15 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_signal_handler(int sig);

static void        handle_sigtstp(void)
{
	char    cp[2];

	cp[0] = g_win->term.c_cc[VSUSP];
	cp[1] = 0;
	ft_make_instruction("ho", NULL);
	ft_make_instruction("cd", NULL);
	ft_tcg(1);
	signal(SIGTSTP, SIG_DFL);
	ioctl(g_win->fd, TIOCSTI, cp);
}

static void		handle_sigcont(void)
{
	ft_tcg(0);
	ft_refresh();
	signal(SIGTSTP, ft_signal_handler);
}

void	ft_signal_handler(int sig)
{
	int		i;
	void	*save;

	i = 0;
	if (sig == SIGWINCH)
	{
		ft_refresh();
	}
	if (sig == SIGINT || sig == SIGTERM || sig == SIGKILL || sig == SIGQUIT)
	{
		ft_make_instruction("ho", NULL);
		ft_tcg(1);
		exit(1);
	}
	if (sig == SIGTSTP)
	{
		handle_sigtstp();
	}
	if (sig == SIGCONT)
		handle_sigcont();
}
