/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:10:05 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/19 16:10:06 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		dog_sprite_side(t_box *box)
{
	double	spr_x;
	double	spr_y;
	double	side_spr_x;
	double	side_spr_y;

	spr_x = box->sprites.spt[box->sprites.sprite_order[box->dsprite.i]].x;
	spr_y = box->sprites.spt[box->sprites.sprite_order[box->dsprite.i]].y;
	side_spr_x = spr_x - box->cam.position.x;
	side_spr_y = spr_y - box->cam.position.y;
	if (side_spr_y > 0 && side_spr_x > 0)
		box->sprites.spt[box->sprites.sprite_order[box->dsprite.i]].n_text = 5;
	else if (side_spr_y < 0 && side_spr_x > 0)
		box->sprites.spt[box->sprites.sprite_order[box->dsprite.i]].n_text = 6;
	else if (side_spr_y < 0 && side_spr_x < 0)
		box->sprites.spt[box->sprites.sprite_order[box->dsprite.i]].n_text = 7;
	else
		box->sprites.spt[box->sprites.sprite_order[box->dsprite.i]].n_text = 8;
}

void		draw_sprites(t_box *box)
{
	box->dsprite.i = 0;
	sort_sprits(box);
	while (box->dsprite.i < box->sprites.n_sprites)
	{
		if (box->sprites.spt[box->sprites.sprite_order
			[box->dsprite.i]].n_text == 5)
			dog_sprite_side(box);
		if (box->sprites.spt[box->sprites.sprite_order
			[box->dsprite.i]].n_text == 2 && box->sky == 1)
			box->dsprite.i++;
		if (box->dsprite.i >= box->sprites.n_sprites)
			return ;
		draw_sprites2(box);
		while (box->dsprite.draw_start_x < box->dsprite.draw_end_x)
		{
			box->dsprite.tex_x = (int)(256 * (box->dsprite.draw_start_x -
			(-box->dsprite.sprite_width / 2 + box->dsprite.sprite_screen_x)) *
			64 / box->dsprite.sprite_width) / 256;
			box->dsprite.tex_x = abs(box->dsprite.tex_x) % 64;
			box->dsprite.color = 0;
			draw_sprites4(box);
			box->dsprite.draw_start_x++;
		}
		box->dsprite.i++;
	}
}

void		draw_sprites2(t_box *box)
{
	box->dsprite.sprite_x = box->sprites.spt[box->sprites.sprite_order
		[box->dsprite.i]].x - box->cam.position.x;
	box->dsprite.sprite_y = box->sprites.spt[box->sprites.sprite_order
		[box->dsprite.i]].y - box->cam.position.y;
	box->dsprite.inv_det = 1.0 / (box->cam.p.x * box->cam.d.y -
		box->cam.d.x * box->cam.p.y);
	box->dsprite.transform_x = box->dsprite.inv_det * (box->cam.d.y *
		box->dsprite.sprite_x - box->cam.d.x * box->dsprite.sprite_y);
	box->dsprite.transform_y = box->dsprite.inv_det * (-box->cam.p.y *
		box->dsprite.sprite_x + box->cam.p.x * box->dsprite.sprite_y);
	box->dsprite.sprite_screen_x = (int)((WIND_W / 2) *
		(1 + box->dsprite.transform_x / box->dsprite.transform_y));
	box->dsprite.sprite_height = abs((int)(WIND_H /
		(box->dsprite.transform_y)));
	box->dsprite.draw_start_y = -box->dsprite.sprite_height / 2;
	box->dsprite.draw_start_y -= box->dsprite.draw_start_y * box->go.lop;
	box->dsprite.draw_start_y += WIND_H / 2 + box->ogo.lop;
	draw_sprites3(box);
}

void		draw_sprites3(t_box *box)
{
	if (box->dsprite.draw_start_y < 0)
		box->dsprite.draw_start_y = 0;
	box->dsprite.draw_end_y = box->dsprite.sprite_height / 2;
	box->dsprite.draw_end_y += box->dsprite.draw_end_y * box->go.lop;
	box->dsprite.draw_end_y += WIND_H / 2 + box->ogo.lop;
	if (box->dsprite.draw_end_y >= WIND_H)
	{
		box->dsprite.draw_end_y = WIND_H - 1;
	}
	box->dsprite.sprite_width = abs((int)(WIND_H / (box->dsprite.transform_y)));
	box->dsprite.draw_start_x = -box->dsprite.sprite_width
	/ 2 + box->dsprite.sprite_screen_x;
	if (box->dsprite.draw_start_x < 0)
	{
		box->dsprite.draw_start_x = 0;
	}
	box->dsprite.draw_end_x = box->dsprite.sprite_width
	/ 2 + box->dsprite.sprite_screen_x;
	if (box->dsprite.draw_end_x >= WIND_W)
	{
		box->dsprite.draw_end_x = WIND_W - 1;
	}
}

void		draw_sprites4(t_box *box)
{
	box->dsprite.d = 0;
	box->dsprite.y = 0;
	if (box->dsprite.transform_y > 0 && box->dsprite.draw_start_x > 0 &&
		box->dsprite.draw_start_x < WIND_W
	&& box->dsprite.transform_y < box->sprites.zbuffer[box->dsprite.
	draw_start_x] && box->sprites.zbuffer[box->dsprite.draw_start_x] < INT_MAX)
	{
		box->dsprite.y = box->dsprite.draw_start_y;
		while (box->dsprite.y < box->dsprite.draw_end_y)
		{
			box->dsprite.d = (box->dsprite.y * 256 - WIND_H *
				128 + box->dsprite.sprite_height * 128 *
				((-box->go.lop + 1))) - box->ogo.lop * 256;
			box->dsprite.tex_y = ((box->dsprite.d * 64) /
				box->dsprite.sprite_height) / 256;
			box->dsprite.tex_y = abs(box->dsprite.tex_y) % 64;
			box->dsprite.color = get_pixel(box, box->sprites.tex_sprite[box->
			sprites.spt[box->sprites.sprite_order[box->dsprite.i]].n_text],
				box->dsprite.tex_x, box->dsprite.tex_y);
			if (box->dsprite.color != 0)
				box->pixels[box->dsprite.y * WIND_W +
					box->dsprite.draw_start_x] = box->dsprite.color;
			box->dsprite.y++;
		}
	}
}
