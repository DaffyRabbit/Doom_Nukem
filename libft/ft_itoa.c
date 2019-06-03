/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 19:34:27 by arykov            #+#    #+#             */
/*   Updated: 2017/12/21 19:42:05 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	char	*tmp;
	long	a;

	if (!(str = ft_strnew(0)))
		return (NULL);
	if (!(tmp = ft_strnew(1)))
		return (NULL);
	a = (long)n;
	a = a < 0 ? -a : a;
	if (a == 0)
		str[0] = '0';
	while (a)
	{
		tmp[0] = (char)(a % 10) + 48;
		if (!(str = ft_strjoin(tmp, str)))
			return (NULL);
		a = a / 10;
	}
	if (n < 0)
	{
		if (!(str = ft_strjoin((char*)"-", str)))
			return (NULL);
	}
	return (str);
}
