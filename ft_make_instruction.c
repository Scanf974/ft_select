#include "ft_select.h"
#include <term.h>

void	ft_make_instruction(char *id, char *aera)
{
	char	*res;

	res = tgetstr(id, aera);
	tputs(res, 0, ft_outc);
}
