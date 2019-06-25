/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:04:59 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/25 20:05:00 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen.h"

t_list	*ft_lstgetfirst(t_list *lst)
{
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

void	free_alt(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void		ft_lstdel_alt(t_list *lst, int free_content)
{
	t_list	*element;
	t_list	*next;

	if (lst == NULL)
		return ;
	element = ft_lstgetfirst(lst);
	while (element)
	{
		if (element->content && free_content)
			free_alt(element->content);
		next = element->next;
		free_alt(element);
		element = next;
	}
}

void	ft_lstdelone_alt(t_list *el)
{
	t_list	*tmpelement;

	if (el)
	{
		if (el->prev)
			el->prev->next = el->next ? el->next : NULL;
		if (el->next)
		{
			el->next->prev = el->prev ? el->prev : NULL;
			tmpelement = el->next;
			while (tmpelement)
			{
				tmpelement->content_size--;
				tmpelement = tmpelement->next;
			}
		}
		if (el->content)
		{
			free_alt(el->content);
			el->content = NULL;
		}
		free_alt(el);
		el = NULL;
	}
}

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

t_list	*ft_lstadd_alt(t_list *listelement, t_list *newelement)
{
	if (!newelement || !listelement)
		return (NULL);
	newelement->content_size = (listelement->content_size + 1);
	newelement->prev = listelement;
	newelement->next = NULL;
	listelement->next = newelement;
	return (newelement);
}

t_list	*ft_lstnew_alt(void *content)
{
	t_list		*liste;

	if (!(liste = maloc_alt(sizeof(t_list))))
		return (NULL);
	liste->prev = NULL;
	liste->next = NULL;
	liste->content_size = 0;
	liste->content = content;
	return (liste);
}

void	lbox_reindex(t_lbox *container)
{
	t_list	*element;
	int		i;

	element = container->prev;
	i = 0;
	while (element)
	{
		element->content_size = i;
		element = element->next;
		i++;
	}
}
