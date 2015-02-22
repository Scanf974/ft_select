/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tcg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 14:38:50 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 15:34:21 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

t_win	*win;

void	ft_tcg(char f)
{
	if (f == 0)
	{
		if ((win->name_term = getenv("TERM")) == NULL)
			exit(1);
		if (tgetent(NULL, win->name_term) == -1)
			exit(1);
		if (tcgetattr(0, &win->term) == -1)
			exit(1);
		win->term.c_lflag &= ~(ICANON);
		win->term.c_lflag &= ~(ECHO);
		win->term.c_lflag |= ISIG;
		win->term.c_cc[VMIN] = 1;
		win->term.c_cc[VTIME] = 0;
		if (tcsetattr(0, TCSADRAIN, &win->term) == -1)
			exit(1);
	}
	else
	{
		win->term.c_lflag = win->term.c_lflag | ICANON;
		win->term.c_lflag = win->term.c_lflag | ECHO;
		win->term.c_lflag = win->term.c_lflag | ISIG;
		tcsetattr(0, TCSADRAIN, &win->term);
		ft_make_instruction("ve", NULL);
	}
}
