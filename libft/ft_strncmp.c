/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:01:47 by arykov            #+#    #+#             */
/*   Updated: 2017/12/20 17:02:38 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	size_t	a;

	a = 0;
	while (a < n && (s1[a] || s2[a]))
	{
		if (s1[a] == s2[a])
			a++;
		else
			break ;
	}
	if (a == n)
		return ((unsigned char)s1[a - 1] - (unsigned char)s2[a - 1]);
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
