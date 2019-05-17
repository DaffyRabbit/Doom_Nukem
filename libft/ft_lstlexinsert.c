/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlexinsert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 20:33:19 by arykov            #+#    #+#             */
/*   Updated: 2017/12/21 20:33:33 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstlexinsert(t_list **begin, t_list *new)
{
	t_list *prev;
	t_list *current;
	t_list *tmp;

	prev = NULL;
	current = *begin;
	while (current)
	{
		if (ft_strcmp(current->content, new->content) >= 0)
		{
			if (prev != NULL)
			{
				tmp = prev;
				prev->next = new;
				new->next = current;
			}
			else
				ft_lstadd(begin, new);
			return ;
		}
		prev = current;
		current = current->next;
	}
	prev->next = new;
}
