/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_win_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:23:30 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/18 10:26:12 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_win	ft_get_win_size(void)
{
	struct winsize		win;
	t_win				ret;

	ioctl(0, TIOCGWINSZ, &win); 
	ret.width = win.ws_col;
	ret.height = win.ws_row;
	return (ret);
}


