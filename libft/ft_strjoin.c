/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:42:40 by arykov            #+#    #+#             */
/*   Updated: 2017/12/21 17:46:23 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	a;

	a = 0;
	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s2 && s1)
		return (ft_strdup(s1));
	else if (!s1 && !s2)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	while (a < (ft_strlen(s1) + ft_strlen(s2)))
	{
		if (a < ft_strlen(s1))
			str[a] = s1[a];
		else
			str[a] = s2[a - ft_strlen(s1)];
		a++;
	}
	return (str);
}
