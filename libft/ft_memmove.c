/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:07:21 by arykov            #+#    #+#             */
/*   Updated: 2017/12/21 20:12:37 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			a;
	char			*d;
	const char		*sorc;

	a = 0;
	d = (char*)dst;
	sorc = (char*)src;
	if (d < sorc)
		while (a < len)
		{
			d[a] = sorc[a];
			a++;
		}
	else
		while (len--)
			d[len] = sorc[len];
	return (dst);
}
