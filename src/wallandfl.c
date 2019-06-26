/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallandfl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:08:23 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/19 17:08:24 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doomnukem.h"

void		some_blocks(t_box *box)
{
	box->block.bd = (box->block.bs == 0) ?
		(box->tir.pl.x - box->cam.position.x + (1 - box->tir.go.x) /
			2) / box->tir.fold.x :
		(box->tir.pl.y - box->cam.position.y + (1 - box->tir.go.y) /
			2) / box->tir.fold.y;
	box->block.bh = WIND_H / box->block.bd;
	box->block.bt = -box->block.bh / 2;
	box->block.bt -= box->block.bt * box->go.lop;
	box->block.bt += WIND_H / 2 + box->ogo.lop;
	box->block.bb = box->block.bh / 2;
	box->block.bb += box->block.bb * box->go.lop;
	box->block.bb += WIND_H / 2 + box->ogo.lop;
	if (box->block.bt < 0)
		box->block.bt = 0;
	else if (box->block.bt > WIND_H)
		box->block.bt = WIND_H;
	if (box->block.bb > WIND_H)
		box->block.bb = WIND_H;
	else if (box->block.bb < 0)
		box->block.bb = 0;
}

void		add_txtrs(t_box *box, int x, int y)
{
	Uint32		color;
	Uint8		r;
	Uint8		g;
	Uint8		b;
	double		intens;

	if (box->no_shadow == 1 || box->mirror_effect == 1)
		intens = (box->no_shadow == 1) ? 0.68 : 0.8;
	else if (box->block.bd >= 0)
		intens = set_intens(box);
	if ((x >= 0 && x <= 64) && (y >= 0 && y <= 64))
	{
		SDL_GetRGB(((int *)box->txtrs[box->a]->pixels)[y * 64 + x],
			box->txtrs[box->a]->format, &r, &g, &b);
		r = r * intens;
		g = g * intens;
		b = b * intens;
		color = SDL_MapRGB(box->txtrs[box->a]->format, r, g, b);
		if (box->atpos < WIND_W && box->btpos < WIND_H &&
			box->atpos >= 0 && box->btpos >= 0)
			box->pixels[box->btpos * WIND_W + box->atpos] = color;
	}
}

void		choose_side_texture(t_box *box)
{
	if (box->a >= 25 && box->a <= 34)
		box->a -= 25;
	if ((box->block.bs == 0 && box->all_map[box->tir.pl.y]
		[box->tir.pl.x + 1] == 1 && box->tir.fold.x < 0 &&
		(box->all_map[box->tir.pl.y][box->tir.pl.x + 2] > 24 &&
		box->all_map[box->tir.pl.y][box->tir.pl.x + 2] < 35)) ||
		(box->block.bs == 1 && box->all_map[box->tir.pl.y + 1]
		[box->tir.pl.x] == 1 && box->tir.fold.y < 0 &&
		(box->all_map[box->tir.pl.y + 2][box->tir.pl.x] < 35 &&
		box->all_map[box->tir.pl.y + 2][box->tir.pl.x] > 24)))
	{
		box->a = 8;
	}
}

void		print_walls(t_box *box)
{
	box->a = box->all_map[box->tir.pl.y][box->tir.pl.x];
	choose_side_texture(box);
	box->block.btouch = box->block.bs == 0 ?
		box->cam.position.y + box->block.bd * box->tir.fold.y :
		box->cam.position.x + box->block.bd * box->tir.fold.x;
	box->block.btouch -= (box->block.btouch >= 0) ? (int)box->block.btouch :
		((int)box->block.btouch - 1);
	box->paramtext.x = (int)(box->block.btouch * 64);
	box->paramtext.x = 64 - box->paramtext.x - 1;
	box->btpos = box->block.bt;
	while ((box->btpos <= box->block.bb + 1) && (box->btpos < WIND_H))
	{
		box->paramtext.y = box->btpos - WIND_H / 2 +
			(box->block.bh / 2) * (-box->go.lop + 1) - box->ogo.lop;
		box->paramtext.y = (box->paramtext.y * 64 / box->block.bh);
		box->paramtext.y %= 64;
		add_txtrs(box, box->paramtext.x, box->paramtext.y);
		box->btpos++;
	}
	box->btpos = box->btpos - 2;
	box->sprites.zbuffer[box->atpos] = box->block.bd;
	up_and_down(box);
}

void		add_txtrs2(t_box *box, int y, int a)
{
	Uint32	color;
	double	intens;
	Uint8	r;
	Uint8	g;
	Uint8	b;

	intens = intens_calc(box, y, a);
	if (box->mirror_effect == 1)
		intens = mirror_effect(box, a, intens);
	if (box->atpos < WIND_W && box->btpos < WIND_H)
	{
		if ((box->tex_floor_y >= 0 && box->tex_floor_y <= 64) &&
			(box->tex_floor_x >= 0 && box->tex_floor_x <= 64))
		{
			color = ((int *)box->txtrs[a]->pixels)[box->tex_floor_y * 64 +
				box->tex_floor_x];
			SDL_GetRGB(color, box->txtrs[a]->format, &r, &g, &b);
			r *= intens;
			g *= intens;
			b *= intens;
			color = SDL_MapRGB(box->txtrs[a]->format, r, g, b);
			box->pixels[y * WIND_W + box->atpos] = color;
		}
	}
}
