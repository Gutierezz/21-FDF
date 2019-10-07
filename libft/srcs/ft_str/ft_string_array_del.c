#include "libft.h"

void    ft_string_array_del(char **arr)
{
	int     i;

	i = -1;
	if (arr)
	{
		while (arr[++i])
			ft_strdel(&arr[i]);
		ft_memdel((void**)&arr);
	}
}
