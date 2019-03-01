/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:41:23 by arykov            #+#    #+#             */
/*   Updated: 2018/11/30 13:41:30 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		exit_this(void)
{
	exit(0);
}

void	all_destroy(t_box *box)
{
	SDL_DestroyWindow(box->wind);
}

int		small_map(t_box *box)
{
	if (box->mapx >= 5 && box->mapy >= 5)
		return (0);
	return (box->error = -9);
}
