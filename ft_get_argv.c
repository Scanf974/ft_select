/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 02:47:25 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 06:07:35 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_win		*win;

t_lstrep	*ft_get_argv(char **ar)
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
