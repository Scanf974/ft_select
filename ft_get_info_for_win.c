#include "ft_select.h"

t_win	ft_get_info_for_win(t_lstrep *argv)
{
	t_win	win;

	ft_bzero(&win, sizeof(t_win));
	win.nb_argv = argv->len;
	return (win);
}
