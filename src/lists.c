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

t_list		*ft_lstgetfirst(t_list *lst)
{
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

void		lbox_reindex(t_lbox *container)
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
