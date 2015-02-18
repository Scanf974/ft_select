/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 05:34:11 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/18 08:29:43 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

int		ft_outc(int c)
{
	ft_putchar(c);
	return (0);
}

int		main(void)
{
	char			*name_term;
	struct termios	term;
	char			buf[3];
	char			*res;

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == -1)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);

	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);


	while (69)
	{
		read(0, buf, 3);
		if (buf[0] == '\033')
		{
			if (buf[2] == 'A')
			{
				if ((res = tgetstr("cl", NULL)) == NULL)
					return (-1);
				tputs(res, 0, ft_outc);
			}
			if (buf[2] == 'B')
				ft_putendl("fleche du bas");
		}
	}

	return (0);
}
