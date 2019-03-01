/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:59:17 by arykov            #+#    #+#             */
/*   Updated: 2017/12/20 17:00:14 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	all_word(const char *haystack, const char *needle)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(needle))
	{
		if (haystack[i] != needle[i])
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	char	*result;

	a = 0;
	result = (char*)haystack;
	if (!needle[0])
		return (result);
	while (a < len && haystack[a])
	{
		if (haystack[a] == needle[0] && all_word(&haystack[a], needle)
		&& (a + ft_strlen(needle) <= len))
		{
			result = (char*)&haystack[a];
			return (result);
		}
		a++;
	}
	return (NULL);
}
