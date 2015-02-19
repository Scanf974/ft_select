#include "ft_select.h"

static size_t	ft_get_len_bigger_word(t_lstrep *argv)
{
	size_t		len;
	size_t		i;

	len = ft_strlen(argv->first->str);
	i = 0;
	while (i < argv->len)
	{
		if (len < ft_strlen(argv->first->str))
			len = ft_strlen(argv->first->str);
		argv->first = argv->first->next;
		i++;
	}
	return (len);
}

static int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

t_win			ft_get_info_for_win(t_lstrep *argv)
{
	t_win			win;
	struct winsize	winsize;

	ft_bzero(&win, sizeof(t_win));
	ioctl(0, TIOCGWINSZ, &winsize); 
	win.nb_argv = argv->len;
	win.width = winsize.ws_col;
	win.height = winsize.ws_row;
	win.len_bigger = ft_get_len_bigger_word(argv);
	win.col = (win.nb_argv - 1) / win.height + 1;
	win.raw = ft_min(win.nb_argv, win.height); 
	return (win);
}
