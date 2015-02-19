#include "libl.h"

void	ft_lstl_delone(t_lstl **begin, char *str, int (*f)(char const *, char const *))
{
	t_lstl	*tmp;

	tmp = *begin;
	if (tmp && f(str, tmp->str))
		*begin = tmp->next;
	while (tmp && tmp->next && !f(str, tmp->next->str))
		tmp = tmp->next;
	if (tmp && tmp->next && tmp->next->next)
		tmp->next = tmp->next->next;
	else if (tmp && tmp->next && f(str, tmp->next->str))
		tmp->next = NULL;
}

