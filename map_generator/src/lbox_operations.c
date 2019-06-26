/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:43:30 by rhusak            #+#    #+#             */
/*   Updated: 2019/06/25 20:43:43 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gen.h"

t_lbox	*lbox_new(void)
{
	t_lbox	*newcontainer;

	if ((newcontainer = maloc_alt(sizeof(t_lbox))) == NULL)
		return (NULL);
	newcontainer->add = lbox_add;
	newcontainer->remove = lbox_remove;
	newcontainer->size = lbox_size;
	newcontainer->fastsize = lbox_fastsize;
	newcontainer->reindex = lbox_reindex;
	newcontainer->prev = NULL;
	newcontainer->next = NULL;
	return (newcontainer);
}

void	lbox_add(t_lbox *container, void *content)
{
	if (container == NULL)
	{
		container = lbox_new();
	}
	if (container->prev == NULL)
	{
		container->prev = ft_lstnew_alt(content);
		container->next = container->prev;
	}
	else
	{
		container->next = ft_lstadd_alt(container->next,
			ft_lstnew_alt(content));
	}
}

void	lbox_remove(t_lbox *l, t_list *element)
{
	if (element == l->prev && element == l->next)
	{
		l->prev = NULL;
		l->next = NULL;
	}
	if (element == l->prev && element->next == NULL)
		l->prev = NULL;
	if (element == l->next && element->prev == NULL)
		l->next = NULL;
	if (element == l->prev && element->next != NULL)
		l->prev = element->next;
	if (element == l->next && element->prev != NULL)
		l->next = element->prev;
	ft_lstdelone_alt(element);
}

int		lbox_size(t_lbox *list_container)
{
	t_list	*lst;
	int		size;

	size = 0;
	lst = list_container->prev;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

int		lbox_fastsize(t_lbox *container)
{
	if (container->next == NULL)
		return (0);
	return (container->next->content_size + 1);
}
