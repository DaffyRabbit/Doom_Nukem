/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:00:44 by arykov            #+#    #+#             */
/*   Updated: 2017/12/20 17:01:39 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	a;

	a = 0;
	while (s1[a] || s2[a])
	{
		if (s1[a] == s2[a])
			a++;
		else
			break ;
	}
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
