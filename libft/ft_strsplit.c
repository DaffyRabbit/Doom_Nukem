/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 19:11:29 by arykov            #+#    #+#             */
/*   Updated: 2017/12/21 19:33:47 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_blanc(char const *s, char c)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	while (a < ft_strlen(s) - 1)
	{
		if ((s[a] == c && s[a + 1] != c) || (a == 0 && s[0] != c))
			b++;
		a++;
	}
	return (b);
}

static char		*next_blanc(char const *s, char c)
{
	int		d;

	d = 0;
	while (s[d] != c)
		d++;
	return (ft_strsub(s, 0, d));
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (!ft_strlen(s))
	{
		tab = ft_memalloc(1);
		tab[0] = 0;
		return (tab);
	}
	if (!(tab = (char**)malloc((num_blanc(s, c) + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	j = 0;
	if (s[0] != c)
		tab[j++] = next_blanc(s, c);
	while (i++ < ft_strlen(s) - 1)
	{
		if ((s[i - 1] == c && s[i] != c))
			tab[j++] = next_blanc(&s[i], c);
	}
	tab[j] = 0;
	return (tab);
}
