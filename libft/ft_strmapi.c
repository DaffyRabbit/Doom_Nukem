/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:38:35 by arykov            #+#    #+#             */
/*   Updated: 2017/12/21 17:39:18 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	a;

	a = 0;
	if (!s || !f)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (a < ft_strlen(s))
	{
		str[a] = f(a, s[a]);
		a++;
	}
	return (str);
}
