/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 20:30:25 by arykov            #+#    #+#             */
/*   Updated: 2017/12/21 20:30:55 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_list_size(t_list *begin)
{
	t_list	*current;
	size_t	a;

	a = 0;
	current = begin;
	while (current)
	{
		current = current->next;
		a++;
	}
	return (a);
}
