/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:46:01 by rhusak            #+#    #+#             */
/*   Updated: 2019/06/25 20:46:09 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen.h"

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
