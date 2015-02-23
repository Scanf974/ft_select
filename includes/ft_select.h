/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 05:32:58 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 16:45:50 by bsautron         ###   ########.fr       */
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
	struct termios	term;
	char			*name_term;
	int				fd;
	t_lstrep		*list;
	int				width;
	int				height;
	size_t			nb_argv;
	size_t			len_bigger;
	int				col;
	int				raw;
	size_t			pos;
}					t_win;

extern t_win		*g_win;

void				ft_tcg(char f);
int					ft_outc(int c);
void				ft_move(char c);
void				ft_refresh(void);
void				ft_signal_handler(int sig);
void				ft_get_info_for_win(void);
void				ft_make_instruction(char *id, char *aera);
void				ft_print_argv(void);
t_lstdc				*ft_get_link_by_id(size_t id);
void				ft_del_link_by_id(size_t id);
void				ft_select(void);
t_lstrep			*ft_get_argv(char **argv);

#endif

