#include "libl.h"

void	ft_lstl_add(t_lstl **begin, char *str)
{
	t_lstl	*new;

	new = ft_lstl_create(str);
	if (!(*begin))
		*begin = new;
	else
	{
		new->next = *begin;
		*begin = new;
	}
}
