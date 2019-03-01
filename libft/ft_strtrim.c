/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:46:48 by arykov            #+#    #+#             */
/*   Updated: 2017/12/21 19:10:57 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	blanc(char const *s)
{
	size_t	a;

	a = 0;
	while (s[a] == ' ' || s[a] == '\n' || s[a] == '\t')
		a++;
	if (a == ft_strlen(s))
		return (1);
	return (0);
}

static int	num_start(char const *s)
{
	size_t	b;

	b = 0;
	while (s[b] == ' ' || s[b] == '\n' || s[b] == '\t')
		b++;
	return (b);
}

static int	num_end(char const *s)
{
	size_t	c;
	size_t	d;

	c = ft_strlen(s) - 1;
	d = 0;
	while (s[c] == ' ' || s[c] == '\n' || s[c] == '\t')
	{
		c--;
		d++;
	}
	return (d);
}

char		*ft_strtrim(char const *s)
{
	char	*str;

	if (!s)
		return (NULL);
	if (blanc(s))
		return (ft_strnew(0));
	str = ft_strsub(s, num_start(s),
	(ft_strlen(s) - num_start(s) - num_end(s)));
	return (str);
}
