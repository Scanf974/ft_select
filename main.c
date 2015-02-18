/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 05:34:11 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/18 14:17:57 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

int		ft_outc(int c)
{
	ft_putchar(c);
	return (0);
}
int		main(int argc, char **argv)
{
	t_lstrep	*yo;
	int			i;

	yo = NULL;
	if (argc > 1)
	{
		i = 1;
		while (argv[i])
		{
			ft_lstdc_add(&yo, argv[i]);
			i++;
		}
		ft_lstdc_print(yo);
	}
	/*
	char			*name_term;
	struct termios	term;
	char			buf[3];
	char			*res;
	t_win			win;

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
				res = tgetstr("up", NULL);
			if (buf[2] == 'B')
				res = tgetstr("do", NULL);
			if (buf[2] == 'D')
				res = tgetstr("le", NULL);
			if (buf[2] == 'C')
				res = tgetstr("nd", NULL);
			tputs(res, 0, ft_outc);
		}
		else
		{
			win = ft_get_win_size();
			dprintf(1, "col = %d, haut = %d\n", win.width, win.height);
		}
	}
*/
	return (0);
}
