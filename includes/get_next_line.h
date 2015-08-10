/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 18:09:12 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/23 18:09:13 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE			4096

# define FT_SWAP(x, y, z) {z = x; x = y; if (z != x) {free(z);}}

# include "libft.h"

typedef struct				s_buff
{
	int						read;
	int						last_line;
	char					*buff;
	int						len;
}							t_buff;

int							get_next_line(int const fd, char **line);

#endif
