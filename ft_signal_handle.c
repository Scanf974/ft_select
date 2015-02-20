/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 04:09:15 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/20 05:32:30 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
struct termios	*g_dat;
void	ft_signal_handler(int sig);

static void        handle_sigtstp(void)
{
	char    cp[2] ={g_dat->c_cc[VSUSP], 0};
	dprintf(1, "Stopping...\n");
	ft_tcg(1);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

static void		handle_sigcont(void)
{
	ft_tcg(0);
	signal(SIGTSTP, ft_signal_handler);
}

void	ft_signal_handler(int sig)
{
	if (sig == SIGWINCH)
	{
		ft_refresh();
	}
	if (sig == SIGTSTP)
		handle_sigtstp();
	if (sig == SIGCONT)
		handle_sigcont();
}
