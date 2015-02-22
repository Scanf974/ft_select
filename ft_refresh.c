/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 04:37:02 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 12:40:28 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

void	ft_refresh(void)
{
	ft_get_info_for_win();
	ft_tcg(0);
	//ft_make_instruction("ho", NULL);
	ft_make_instruction("cl", NULL);
	ft_print_argv();
}
