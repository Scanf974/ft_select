#include "libl.h"

void	ft_lstl_print(t_lstl *list)
{
	while (list)
	{
		ft_putstr(list->str);
		list = list->next;
		if (list)
			ft_putchar('\n');
	}
}
