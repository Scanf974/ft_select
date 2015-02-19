#include "ft_select.h"
#include <term.h>

void	ft_print_argv(t_lstrep *rep, t_win win)
{
	size_t		i;
	char		*res;
	int			col;
	int			raw;

	i = 0;
	col = 0;
	raw = 0;
	while (rep && rep->first && i < rep->len)
	{
		res = tgetstr("cm", NULL);
		tputs(tgoto(res, col * (win.len_bigger + 1), raw), 1, ft_outc);
		ft_putstr(rep->first->str);
		rep->first = rep->first->next;
		raw++;
		if (raw == win.height)
		{
			raw = 0;
			col++;
		}
		i++;
	}
}
