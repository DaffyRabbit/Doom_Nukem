/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 20:33:45 by arykov            #+#    #+#             */
/*   Updated: 2017/12/21 20:33:55 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *begin;
	t_list *tmp;
	t_list *current;

	if (!lst)
		return (NULL);
	current = lst;
	tmp = f(current);
	if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	begin = new;
	current = current->next;
	while (current)
	{
		tmp = f(current);
		if (!(new->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		current = current->next;
		new = new->next;
	}
	return (begin);
}
