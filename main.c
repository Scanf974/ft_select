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
	t_lstrep		*list;
	char			*res;
	t_win			win;

	if (argc > 1)
	{
		list = ft_getargv(argv);
		win = ft_get_info_for_win(list);
		ft_tcg(0);
		ft_make_instruction("cl", NULL);
		ft_make_instruction("cm", NULL);
		/*
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
		}*/
		ft_tcg(1);
	}
	return (0);
}
