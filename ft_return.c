/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 17:31:13 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/23 17:37:56 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	ft_nb_selected(void)
{
	t_lstdc	*tmp;
	size_t	i;
	size_t	nb;

	nb = 0;
	i = 0;
	tmp = g_win->list->first;
	while (i < g_win->nb_argv)
	{
		if (tmp->selected)
			nb++;
		tmp = tmp->next;
		i++;
	}
	return (nb);
}

static void	ft_print_that_return(int nb)
{
	t_lstdc		*tmp;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i < g_win->nb_argv)
	{
		if (tmp->selected)
		{
			j++;
			ft_putstr(tmp->str);
			if (j < nb)
				ft_putchar(' ');
		}
		tmp = tmp->next;
		i++;
	}
	if (nb != 0)
		ft_putchar('\n');
}

void		ft_return(void)
{
	ft_make_instruction("ho", NULL);
	ft_make_instruction("cd", NULL);
	ft_print_that_return(ft_nb_selected());
	ft_tcg(1);
	if (close(g_win->fd) == -1)
	{
		ft_putendl_fd("return(): close tty Failed", 2);
		exit(1);
	}
	exit(0);
}
