#include "ft_select.h"

void	ft_return(void)
{
	t_lstdc	*tmp;
	size_t	i;
	size_t	nb;
	size_t	j;

	i = 0;
	nb = 0;
	j = 0;
	ft_make_instruction("ho", NULL);
	ft_make_instruction("cd", NULL);
	tmp = g_win->list->first;
	while (i < g_win->nb_argv)
	{
		if (tmp->selected)
			nb++;
		tmp = tmp->next;
		i++;
	}
	i = 0;
	while (i < g_win->nb_argv)
	{
		if (tmp->selected)
		{
			j++;
			ft_putstr(tmp->str);
			if (j < nb)
				ft_putchar(' ');
		}
		tmp = tmp->next;
		i++;
	}
	if (nb != 0)
		ft_putchar('\n');
	ft_tcg(1);
	if (close(g_win->fd) == -1)
	{
		ft_putendl_fd("return(): close tty Failed", 2);
		exit(1);
	}
	exit(0);
}
