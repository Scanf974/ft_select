/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 06:49:43 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/23 17:30:34 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

t_win	*g_win;

static void	ft_print_this_shit(t_lstdc *tmp, char *res, char *direction)
{
	tputs(tgoto(res, ((g_win->pos - 1) / g_win->height) *
		(g_win->len_bigger + 1), (g_win->pos - 1) % g_win->height), 1, ft_outc);
	if (tmp->selected == 1)
		ft_make_instruction("so", NULL);
	ft_putstr_fd(ft_get_link_by_id(g_win->pos - 1)->str, g_win->fd);
	ft_make_instruction("se", NULL);
	if (ft_strequ(direction, "haut"))
		g_win->pos--;
	if (ft_strequ(direction, "bas"))
		g_win->pos++;
	if (ft_strequ(direction, "droite"))
		g_win->pos += g_win->height;
	if (ft_strequ(direction, "gauche"))
		g_win->pos -= g_win->height;
}

static void	ft_fin_de_lecriture_du_mot_pd_de_norme_de_merde(void)
{
	ft_make_instruction("ue", NULL);
	ft_make_instruction("se", NULL);
}

void		ft_move(char c)
{
	char		*res;
	t_lstdc		*tmp;

	tmp = ft_get_link_by_id(g_win->pos - 1);
	res = tgetstr("cm", NULL);
	if (c == 'A')
		ft_print_this_shit(tmp, res, "haut");
	else if (c == 'B')
		ft_print_this_shit(tmp, res, "bas");
	else if (c == 'C' && g_win->pos + g_win->raw <= g_win->nb_argv)
		ft_print_this_shit(tmp, res, "droite");
	else if (c == 'D')
		ft_print_this_shit(tmp, res, "gauche");
	if (g_win->pos > g_win->nb_argv)
		g_win->pos = 1;
	if (g_win->pos == 0)
		g_win->pos = g_win->nb_argv;
	tputs(tgoto(res, ((g_win->pos - 1) / g_win->height) *
		(g_win->len_bigger + 1), (g_win->pos - 1) % g_win->height), 1, ft_outc);
	tmp = ft_get_link_by_id(g_win->pos - 1);
	if (tmp->selected == 1)
		ft_make_instruction("so", NULL);
	ft_make_instruction("us", NULL);
	ft_putstr_fd(ft_get_link_by_id(g_win->pos - 1)->str, g_win->fd);
	ft_fin_de_lecriture_du_mot_pd_de_norme_de_merde();
}
