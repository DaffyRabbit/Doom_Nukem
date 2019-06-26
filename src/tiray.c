/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiray.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:05:25 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/19 17:05:26 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doomnukem.h"

void	this_is_castingray(t_box *box)
{
	while (box->all_map[box->tir.pl.y][box->tir.pl.x] < 25 ||
		box->all_map[box->tir.pl.y][box->tir.pl.x] > 34)
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
