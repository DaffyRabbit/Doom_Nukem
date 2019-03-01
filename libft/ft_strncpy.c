/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:16:02 by arykov            #+#    #+#             */
/*   Updated: 2017/12/20 16:46:13 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	a;

	a = 0;
	while (a < len)
	{
		if (a < ft_strlen(src))
			dst[a] = src[a];
		else
			dst[a] = '\0';
		a++;
	}
	return (dst);
}
