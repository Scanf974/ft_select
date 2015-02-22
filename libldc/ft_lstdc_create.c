/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdc_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 22:31:40 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 04:27:46 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libldc.h"

t_lstdc		*ft_lstdc_create(char *str)
{
	t_lstdc	*new_element;

	new_element = (t_lstdc *)malloc(sizeof(t_lstdc));
	if (!new_element)
		return (NULL);
	new_element->prev = new_element;
	new_element->next = new_element;
	new_element->selected = 0;
	new_element->str = ft_strdup(str);
	return (new_element);
}
