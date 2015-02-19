/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tcg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 14:38:50 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/18 14:59:30 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

void	ft_tcg(char f)
{
	static int				fd;
	static char				*name_term;
	static struct termios	term;

	if (f == 0)
	{
		if ((name_term = getenv("TERM")) == NULL)
			exit(1);
		if (tgetent(NULL, name_term) == -1)
			exit(1);
		if (tcgetattr(0, &term) == -1)
			exit(1);
		term.c_lflag &= ~(ICANON);
		term.c_lflag &= ~(ECHO);
		term.c_cc[VMIN] = 1;
		term.c_cc[VTIME] = 0;
		if (tcsetattr(0, TCSADRAIN, &term) == -1)
			exit(1);
	}
	else
	{
		term.c_lflag = term.c_lflag | ICANON;
		term.c_lflag = term.c_lflag | ECHO;
		tcsetattr(fd, TCSADRAIN, &term);
	}
}
