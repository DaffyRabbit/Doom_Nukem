/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:41:22 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/25 19:41:23 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gen.h"

void	free_it(char const **s1, char const **s2, size_t free_level)
{
	if (free_level == 1)
		free_alt((char *)(*s1));
	if (free_level == 2)
		free_alt((char *)(*s2));
	if (free_level == 3)
	{
		free_alt((char *)(*s1));
		free_alt((char *)(*s2));
	}
}

char	*ft_strjoin_alt(char const *s1, char const *s2, size_t free_level)
{
	size_t	i;
	char	*nstring;
	size_t	size_s1;
	size_t	size_s2;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if ((nstring = maloc_alt(sizeof(char) * (size_s1 + size_s2 + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < size_s1)
	{
		nstring[i] = s1[i];
		i++;
	}
	while (i < size_s1 + size_s2)
	{
		nstring[i] = s2[i - size_s1];
		i++;
	}
	nstring[i] = '\0';
	free_it(&s1, &s2, free_level);
	return (nstring);
}
