/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:49:23 by arykov            #+#    #+#             */
/*   Updated: 2017/12/20 16:50:06 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	a;
	size_t	s1_len;

	a = 0;
	s1_len = ft_strlen(s1);
	while (a < n && s2[a])
	{
		s1[s1_len + a] = s2[a];
		a++;
	}
	s1[s1_len + a] = '\0';
	return (s1);
}
