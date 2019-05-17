/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:57:41 by arykov            #+#    #+#             */
/*   Updated: 2017/12/21 20:37:46 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*a;

	if (!(a = (void*)malloc(size * sizeof(void))))
		return (NULL);
	ft_bzero(a, size);
	return (a);
}
