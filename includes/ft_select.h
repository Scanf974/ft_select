/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 05:32:58 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/18 14:56:19 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H


#include <stdio.h> //
# include <termios.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <curses.h>
# include <fcntl.h>
# include <sys/types.h>
# include <signal.h>
# include "libft.h"
# include "libl.h"
# include "libldc.h"

typedef struct		s_win
{
	int			width;
	int			height;
	size_t		nb_argv;
	size_t		len_bigger;
	int			col;
	int			raw;
}					t_win;

void				ft_tcg(char f);
int					ft_outc(int c);
t_win				ft_get_info_for_win(t_lstrep *argv);
void				ft_make_instruction(char *id, char *aera);

#endif

