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
	box->block.bd = (box->block.bs == 0) ?
		(box->tir.pl.x - box->cam.position.x + (1 - box->tir.go.x) / 2) / box->tir.fold.x :
		(box->tir.pl.y - box->cam.position.y + (1 - box->tir.go.y) / 2) / box->tir.fold.y;
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
	Uint8		r;
	Uint8		g;
	Uint8		b;
	double		intens;

	if (box->no_shadow == 1 || box->mirror_effect == 1)
		intens = (box->no_shadow == 1) ? 0.68 : 0.8;
	else if (box->block.bd >= 0)
	{
		intens = (box->block.bd < 27) ? (1 / box->block.bd * box->light_power) :
		(0.5 / box->block.bd * box->light_power);
		if (intens > 0.8)
			intens = 0.8;
	}
	if ((x >= 0 && x <= 64) && (y >= 0 && y <= 64))
	{
		SDL_GetRGB(((int *)box->txtrs[box->a]->pixels)[y * 64 + x], box->txtrs[box->a]->format, &r, &g, &b);
		r = r * intens;
		g = g * intens;
		b = b * intens;
		color = SDL_MapRGB(box->txtrs[box->a]->format, r, g, b);
		if (box->atpos < WIND_W && box->btpos < WIND_H && box->atpos >= 0 && box->btpos >= 0)
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
	box->block.btouch -= (box->block.btouch >= 0) ? (int)box->block.btouch :
		((int)box->block.btouch - 1);
	box->paramtext.x = (int)(box->block.btouch * 64);
	box->paramtext.x = 64 - box->paramtext.x - 1;
	box->btpos = box->block.bt;
	while (box->btpos < box->block.bb)
	{
		box->paramtext.y = (box->btpos - WIND_H / 2 + 
			(box->block.bh / 2) * (-box->go.lop + 1)) - box->ogo.lop;
		box->paramtext.y = (box->paramtext.y * 64 / box->block.bh);
		box->paramtext.y = abs(box->paramtext.y) % 64;
		add_txtrs(box, box->paramtext.x, box->paramtext.y);
		box->btpos++;
	}
	up_and_down(box);
}


void		floor_param(t_box *box)
{
	if (box->block.bs == 0 && box->tir.fold.x > 0)
	{
		box->floor_x = box->tir.pl.x;
		box->floor_y = box->tir.pl.y + box->block.btouch;
	}
	else if (box->block.bs == 0 && box->tir.fold.x < 0)
	{
		box->floor_x = box->tir.pl.x + 1.0;
		box->floor_y = box->tir.pl.y + box->block.btouch;
	}
	else if (box->block.bs == 1 && box->tir.fold.y < 0)
	{
		box->floor_x = box->tir.pl.x + box->block.btouch;
		box->floor_y = box->tir.pl.y + 1.0;
	}
	else
	{
		box->floor_x = box->tir.pl.x + box->block.btouch;
		box->floor_y = box->tir.pl.y;
	}
}

double				intens_calc(t_box *box, int y, int a)
{
	double		intens;
	int			tmp_y;

	if (box->no_shadow == 1)
		intens = 0.67;
	else
	{
		if (a == 5)
			tmp_y = y - WIND_H - box->ogo.lop;
		else
			tmp_y = y - box->ogo.lop;
		intens = (1 - (800.0 / abs(tmp_y)) / 2.0) * 1.4 * box->light_power;
		if (intens > 0.8)
			intens = 0.8;
		if (intens < 0)
			intens = 0;
	}
	return (intens);
}

double				mirror_effect(t_box *box, int a, double intens)
{
	if (a == 5)
	{
		intens = 0.85;
		return(intens);
	}
	else
	{
		if (box->dist > 1.0)
			box->dist = 1.0;
		else
		{
			intens = (1 - box->dist);
			if (intens > 0.85)
				intens = 0.85;
		}
	}
	return(intens);
}

void			add_txtrs2(t_box *box, int y, int a)
{
	Uint32		color;
	double		intens;
	Uint8		r;
	Uint8		g;
	Uint8		b;
	
	intens = intens_calc(box, y, a);
	if (box->mirror_effect == 1)
		intens = mirror_effect(box, a, intens);
	if (box->atpos < WIND_W && box->btpos < WIND_H)
	{
		if ((box->tex_floor_y >= 0 && box->tex_floor_y <= 64) && (box->tex_floor_x >= 0 && box->tex_floor_x <= 64))
		{
			color = ((int *)box->txtrs[a]->pixels)[box->tex_floor_y * 64 + box->tex_floor_x];
			SDL_GetRGB(color, box->txtrs[a]->format, &r, &g, &b);
			r *= intens;
			g *= intens;
			b *= intens;
			color = SDL_MapRGB(box->txtrs[a]->format, r, g, b);
			box->pixels[y * WIND_W + box->atpos] = color;
		}
		else
			box->pixels[y * WIND_W + box->atpos] = 0x000000;
	}
}

void		up_and_down(t_box *box)
{
	int			j;
	double		tmp_floor_y;
	double		tmp_floor_x;

	floor_param(box);
	j = 0;
	while (j < box->block.bt) //bt - верхня межа стіни
	{
		box->tmp_dist = WIND_H / (2.0 * j - WIND_H - 2 * box->ogo.lop);
		box->dist = (box->tmp_dist / box->block.bd * (box->go.lop - 1)); // (box->go.lop + 1) ????
		tmp_floor_x = box->dist * box->floor_x +
		(1.0 - box->dist) * box->cam.position.x;
		tmp_floor_y = box->dist * box->floor_y +
		(1.0 - box->dist) * box->cam.position.y;
		box->tex_floor_x = (int)(tmp_floor_x * 64) % 64;
		box->tex_floor_y = (int)(tmp_floor_y * 64) % 64;
		add_txtrs2(box, j, 5);
		j++;
	}
	j = box->block.bb;
	while (j < WIND_H)
	{
		box->tmp_dist = WIND_H / (2.0 * j - WIND_H - 2 * box->ogo.lop);
		box->dist = (box->tmp_dist / box->block.bd * (box->go.lop + 1)); // (box->go.lop + 1) ????
		tmp_floor_x = box->dist * box->floor_x +
		(1.0 - box->dist) * box->cam.position.x;
		tmp_floor_y = box->dist * box->floor_y +
		(1.0 - box->dist) * box->cam.position.y;
		box->tex_floor_x = (int)(tmp_floor_x * 64) % 64;
		box->tex_floor_y = abs((int)(tmp_floor_y * 64) % 64);
		add_txtrs2(box, j, 4);
		j++;
	}
}


/* SAMPLE !!!!! */

// void	ft_apply_shadow_to_cf(t_color *c, int y)
// {
// 	c->r *= (1 - (800. / abs(y)) / 2.);
// 	c->g *= (1 - (800. / abs(y)) / 2.);
// 	c->b *= (1 - (800. / abs(y)) / 2.);
// 	c->r = (c->r < 0) ? 0 : c->r;
// 	c->g = (c->g < 0) ? 0 : c->g;
// 	c->b = (c->b < 0) ? 0 : c->b;
// }

