/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info_for_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 04:22:04 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/21 15:43:42 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char			**ar;

t_lstrep	*ft_get_argv(void)
{
	t_lstrep	*yo;
	int			i;

	yo = NULL;
	i = 1;
	while (ar[i])
	{
		ft_lstdc_add_back(&yo, ar[i]);
		i++;
	}
	return (yo);
}

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

t_win			ft_get_info_for_win(void)
{
	t_win			win;
	struct winsize	winsize;

	ft_bzero(&win, sizeof(t_win));
	win.list = ft_get_argv();
	ioctl(0, TIOCGWINSZ, &winsize); 
	win.nb_argv = win.list->len;
	win.width = winsize.ws_col;
	win.height = winsize.ws_row;
	win.len_bigger = ft_get_len_bigger_word(win.list);
	win.col = (win.nb_argv - 1) / win.height + 1;
	win.raw = ft_min(win.nb_argv, win.height); 
	return (win);
}
