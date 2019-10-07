/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:55:48 by ttroll            #+#    #+#             */
/*   Updated: 2018/12/12 14:31:37 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;
	t_list *new_ptr;
	t_list *res;

	new_list = NULL;
	new_ptr = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		res = f(lst);
		if (new_ptr && (new_ptr->next = \
					ft_lstnew(res->content, res->content_size)))
			new_ptr = new_ptr->next;
		else if (!new_ptr && (new_ptr = \
					ft_lstnew(res->content, res->content_size)))
			new_list = new_ptr;
		else
			ft_lstdel(&new_list, &ft_bzero);
		lst = lst->next;
	}
	return (new_list);
}
