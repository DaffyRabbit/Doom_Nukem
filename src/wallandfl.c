/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallandfl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:08:51 by arykov            #+#    #+#             */
/*   Updated: 2018/11/30 14:08:53 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		some_blocks(t_box *box)
{
	box->tir.pl.x += box->tir.fold.x < 0 ? 1 : 0;
	box->tir.pl.y += box->tir.fold.y < 0 ? 1 : 0;
	box->block.bd = box->block.bs == 0 ?
		(box->tir.pl.x - box->cam.position.x) / box->tir.fold.x :
		(box->tir.pl.y - box->cam.position.y) / box->tir.fold.y;
	box->block.bh = WIND_H / box->block.bd;
	box->block.bt = -box->block.bh / 2;
	box->block.bt -= box->block.bt * box->go.lop;
	box->block.bt += WIND_H / 2 + box->ogo.lop;
	box->block.bb = box->block.bh / 2;
	box->block.bb += box->block.bb * box->go.lop;
	box->block.bb += WIND_H / 2 + box->ogo.lop;
	box->block.bt = box->block.bt < 0 ? 0 : box->block.bt;
	box->block.bt = box->block.bt > WIND_H ? WIND_H : box->block.bt;
	box->block.bb = box->block.bb < 0 ? 0 : box->block.bb;
	box->block.bb = box->block.bb > WIND_H ? WIND_H : box->block.bb;
}

void		add_txtrs(t_box *box, int x, int y)
{
	Uint32		color;

	color = 0;
	if (box->atpos < WIND_W && box->btpos < WIND_H)
	{
		color = ((int *)box->txtrs[box->a]->pixels)[y * 64 + x];
		box->pixels[box->btpos * WIND_W + box->atpos] = color;
	}
}

void		print_walls(t_box *box)
{
	if (box->block.bs == 0 && box->tir.fold.x > 0)
		box->a = 0;
	if (box->block.bs == 0 && box->tir.fold.x < 0)
		box->a = 1;
	if (box->block.bs == 1 && box->tir.fold.y > 0)
		box->a = 2;
	if (box->block.bs == 1 && box->tir.fold.y < 0)
		box->a = 3;
	box->block.btouch = box->block.bs == 0 ?
		box->cam.position.y + box->block.bd * box->tir.fold.y :
		box->cam.position.x + box->block.bd * box->tir.fold.x;
	box->block.btouch -= (int)box->block.btouch;
	box->paramtext.x = (int)(box->block.btouch * 64) % 64;
	box->btpos = box->block.bt;
	while (box->btpos < box->block.bb)
	{
		box->paramtext.y = (box->btpos * 256 - WIND_H * 128 + 128 *
			(box->block.bh) * ((-box->go.lop + 1))) - box->ogo.lop * 256;
		box->paramtext.y = ((box->paramtext.y * 64) / box->block.bh) / 256;
		box->paramtext.y = abs(box->paramtext.y) % 64;
		add_txtrs(box, box->paramtext.x, box->paramtext.y);
		box->btpos++;
	}
}

void		up_and_down(t_box *box)
{
	box->coloriz = 0x2F4F4F;
	box->btpos = box->block.bb;
	while (box->btpos < WIND_H)
	{
		colorize_this(box);
		box->btpos++;
	}
	box->coloriz = 0xA9A9A9;
	box->btpos = 0;
	while (box->btpos < box->block.bt)
	{
		colorize_this(box);
		box->btpos++;
	}
}
