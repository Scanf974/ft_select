/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 15:42:25 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/23 17:10:06 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

void	ft_make_instruction(char *id, char *aera)
{
	char	*res;

	if ((res = tgetstr(id, &aera)) == NULL)
	{
		ft_tcg(1);
		exit(1);
	}
	tputs(res, 0, ft_outc);
}
