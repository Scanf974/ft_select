#ifndef LIBL_H
# define LIBL_H

# include "libft.h"

typedef struct		s_lstl
{
	char			*str;
	struct s_lstl	*next;
}					t_lstl;

t_lstl	*ft_lstl_create(char *str);
void	ft_lstl_add(t_lstl **begin, char *str);
void	ft_lstl_add_back(t_lstl **begin, char *str);
void	ft_lstl_delone(t_lstl **begin, char *str, int (*f)(char const *, char const *));
void	ft_lstl_print(t_lstl *list);

#endif
