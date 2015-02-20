/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 04:37:02 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/20 05:31:52 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_win	ft_refresh(void)
{
	t_win	win;

	win = ft_get_info_for_win();
	ft_tcg(0);
	ft_make_instruction("ho", NULL);
	ft_print_argv(win);
	return (win);
}
