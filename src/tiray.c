/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiray.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:00:31 by arykov            #+#    #+#             */
/*   Updated: 2018/11/30 14:00:34 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	this_is_castingray(t_box *box)
{
	while (box->all_map[box->tir.pl.y][box->tir.pl.x] == 0)
	{
		if (box->tir.cast.x < box->tir.cast.y)
		{
			box->tir.cast.x += box->tir.cting.x;
			box->tir.pl.x += box->tir.go.x;
			box->block.bs = 0;
		}
		else
		{
			box->tir.cast.y += box->tir.cting.y;
			box->tir.pl.y += box->tir.go.y;
			box->block.bs = 1;
		}
	}
}

void	ray_start(t_box *box)
{
	box->scene = (double)2 * box->atpos / WIND_W - 1;
	box->tir.fold.x = box->cam.d.x + box->cam.p.x * box->scene;
	box->tir.fold.y = box->cam.d.y + box->cam.p.y * box->scene;
	box->tir.pl.x = (int)box->cam.position.x;
	box->tir.pl.y = (int)box->cam.position.y;
	box->tir.go.x = box->tir.fold.x < 0 ? -1 : 1;
	box->tir.go.y = box->tir.fold.y < 0 ? -1 : 1;
	box->tir.cting.x = fabs(1 / box->tir.fold.x);
	box->tir.cting.y = fabs(1 / box->tir.fold.y);
	box->tir.cast.x = box->tir.fold.x < 0 ?
		(box->cam.position.x - box->tir.pl.x) * box->tir.cting.x :
		(box->tir.pl.x + 1 - box->cam.position.x) * box->tir.cting.x;
	box->tir.cast.y = box->tir.fold.y < 0 ?
		(box->cam.position.y - box->tir.pl.y) * box->tir.cting.y :
		(box->tir.pl.y + 1 - box->cam.position.y) * box->tir.cting.y;
}
