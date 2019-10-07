#include "fdf.h"

t_pointlst 	*new_node(char *line)
{
	char		**arr;
	t_pointlst	*point;
	int			err;

	err = 0;
	if (!(point = (t_pointlst*)ft_memalloc(sizeof(t_pointlst))))
		return (NULL);
	if (!(arr = ft_strsplit(line, ',')))
	{
		ft_memdel((void**)&point);
		return (NULL);
	}
	(ft_check_base(arr[0], 10)) ? point->z = ft_atoi(arr[0]) : err++;
	if (arr[1])
		(ft_check_base(arr[1], 16)) ? point->color = ft_atoi_base(arr[1], 16) : err++;
	else
		point->color = -1;
	ft_string_array_del(arr);
	if (err)
		ft_memdel((void**)&point);
	return (point);
}

void	pointlist_add(t_pointlst **head, t_pointlst *new)
{
	t_pointlst	*tmp;

	if (!(*head))
		*head = new;
	else
	{
		tmp = *head;
		*head = new;
		(*head)->next = tmp;
	}
}

void	pointlist_clear(t_pointlst **head)
{
	t_pointlst *tmp;

	if (!head || !*head)
		return ;
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		ft_memdel((void**)&tmp);
	}
}
