/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libldc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 21:57:44 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 04:08:34 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLDC_H
# define LIBLDC_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_lstdc
{
	char			*str;
	int				selected;
	struct s_lstdc	*prev;
	struct s_lstdc	*next;
}					t_lstdc;

typedef struct		s_lstrep
{
	t_lstdc		*first;
	t_lstdc		*last;
	size_t		len;
}					t_lstrep;

void				ft_lstdc_rinit(t_lstrep **lst);
t_lstdc				*ft_lstdc_create(char *str);
void				ft_lstdc_add(t_lstrep **rep, char *str);
void				ft_lstdc_add_back(t_lstrep **rep, char *str);
void				ft_lstdc_print(t_lstrep *rep);
void				ft_lstdc_delfirst(t_lstrep **rep);

#endif
