/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 05:34:11 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/18 14:55:37 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

int		ft_outc(int c)
{
	ft_putchar(c);
	return (0);
}

t_lstrep	*ft_getargv(char **argv)
{
	t_lstrep	*yo;
	int			i;

	yo = NULL;
	i = 1;
	while (argv[i])
	{
		ft_lstdc_add(&yo, argv[i]);
		i++;
	}
	return (yo);
}



int		main(int argc, char **argv)
{
	t_lstrep	*list;


	char			*name_term;
	struct termios	term;
	char			buf[3];
	char			*res;
	t_win			win;

	if (argc > 1)
	{
		list = ft_getargv(argv);
		ft_tcg(0);
		res = tgetstr("cl", NULL);
		tputs(res, 0, ft_outc);
		ft_lstdc_print(list);
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
		}
	}
	return (0);
}
