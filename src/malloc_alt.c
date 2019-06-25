/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_alt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:28:24 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/25 19:28:36 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen.h"

void	*maloc_alt(size_t size)
{
	void	*srcs;

	if (!(srcs = malloc(size)))
		return (NULL);
	ft_bzero(srcs, size);
	return (srcs);
}
