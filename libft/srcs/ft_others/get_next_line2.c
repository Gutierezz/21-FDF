/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 13:55:03 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/19 16:14:42 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*get_node(t_list **head, int fd)
{
	t_list	*ptr;

	if (!head)
		return (NULL);
	ptr = *head;
	while (ptr)
	{
		if ((int)ptr->content_size == fd)
			return (ptr);
		ptr = ptr->next;
	}
	if (!(ptr = ft_lstnew(NULL, 0)))
		return (NULL);
	ptr->content_size = fd;
	ft_lstadd(head, ptr);
	ptr = *head;
	return (ptr);
}

static void		del_node(t_list **node, t_list **head)
{
	t_list *ptr;

	ptr = NULL;
	if (*head == *node)
		*head = (*node)->next;
	else
	{
		ptr = *head;
		while (ptr && ptr->next != *node)
			ptr = ptr->next;
		if (ptr)
			ptr->next = (*node)->next;
	}
	ft_strdel((char**)&((*node)->content));
	(*node)->content_size = 0;
	(*node)->next = NULL;
	ft_memdel((void**)node);
	*node = NULL;
}

static int		ft_getline(t_list **node, char **line)
{
	int		len;
	char	*temp;
	char	*str;

	str = (char*)(*node)->content;
	temp = NULL;
	len = 0;
	while (*(str + len) != '\n' && *(str + len) != '\0')
		len++;
	ALLOC((*line = ft_strsub(str, 0, len)));
	if (*(str + len) == '\n')
	{
		ALLOC((temp = ft_strdup(str + len + 1)));
		ft_strdel((char**)&((*node)->content));
		(*node)->content = temp;
		if (!((*node)->content))
			return (-1);
	}
	else
		ft_strdel((char**)&((*node)->content));
	return (1);
}

static char		*ft_safejoin(char **str, char *buf)
{
	char *tmp;

	if (!*str)
		*str = ft_strnew(0);
	if (!(tmp = ft_strjoin(*str, buf)))
		return (NULL);
	ft_strdel(str);
	return (tmp);
}

int				get_next_line2(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				brd;
	static	t_list	*head;
	t_list			*node;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	ALLOC((node = get_node(&head, fd)));
	while ((brd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[brd] = '\0';
		ALLOC((node->content = ft_safejoin((char**)&(node->content), buf)));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (brd == 0 && (node->content == NULL || !*(char*)(node->content)))
	{
		del_node(&node, &head);
		return (0);
	}
	if (brd < 0)
		return (-1);
	return (ft_getline(&node, line));
}
