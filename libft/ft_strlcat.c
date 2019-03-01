/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:50:30 by arykov            #+#    #+#             */
/*   Updated: 2017/12/20 16:52:14 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	dst_len;
	size_t	src_len;

	a = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (src_len + size);
	while (dst[a] && a < size - 1)
		a++;
	while (a < size - 1 && *src)
	{
		dst[a] = *src;
		a++;
		src++;
	}
	dst[a] = '\0';
	return (dst_len + src_len);
}
