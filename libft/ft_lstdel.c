/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 20:31:56 by arykov            #+#    #+#             */
/*   Updated: 2017/12/21 20:32:12 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current_lst;
	t_list *tmp;

	current_lst = *alst;
	while (current_lst)
	{
		tmp = current_lst;
		current_lst = current_lst->next;
		ft_lstdelone(&tmp, del);
	}
	*alst = NULL;
}
