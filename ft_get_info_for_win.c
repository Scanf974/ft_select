/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info_for_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 04:22:04 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 05:45:57 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_win	*win;

static size_t	ft_get_len_bigger_word(t_lstrep *lst)
{
	size_t		len;
	size_t		i;

	len = ft_strlen(lst->first->str);
	i = 0;
	while (i < lst->len)
	{
		if (len < ft_strlen(lst->first->str))
			len = ft_strlen(lst->first->str);
		lst->first = lst->first->next;
		i++;
	}
	return (len);
}

static int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void			ft_get_info_for_win(void)
{
	struct winsize	winsize;

	ioctl(0, TIOCGWINSZ, &winsize); 
	win->nb_argv = win->list->len;
	win->width = winsize.ws_col;
	win->height = winsize.ws_row;
	win->len_bigger = ft_get_len_bigger_word(win->list);
	win->col = (win->nb_argv - 1) / win->height + 1;
	win->raw = ft_min(win->nb_argv, win->height); 
}
