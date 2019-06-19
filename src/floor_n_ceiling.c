/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_n_ceiling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:32:41 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/19 17:32:42 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

void		draw_ceiling(t_box *box)
{
	int		j;
	double	tmp_floor_y;
	double	tmp_floor_x;

	j = 0;
	while (j < box->block.bt)
	{
		box->tmp_dist = WIND_H / (2.0 * j - WIND_H - 2 * box->ogo.lop);
		box->dist = (box->tmp_dist / box->block.bd * (box->go.lop - 1));
		tmp_floor_x = box->dist * box->floor_x +
		(1.0 - box->dist) * box->cam.position.x;
		tmp_floor_y = box->dist * box->floor_y +
		(1.0 - box->dist) * box->cam.position.y;
		box->tex_floor_x = (int)(tmp_floor_x * 64) % 64;
		box->tex_floor_y = (int)(tmp_floor_y * 64) % 64;
		add_txtrs2(box, j, 12);
		j++;
	}
}

void		draw_floor(t_box *box)
{
	int		j;
	double	tmp_floor_y;
	double	tmp_floor_x;

	j = box->block.bb - 1;
	while (j < WIND_H)
	{
		box->tmp_dist = WIND_H / (2.0 * j - WIND_H - 2 * box->ogo.lop);
		box->dist = (box->tmp_dist / box->block.bd * (box->go.lop + 1));
		tmp_floor_x = box->dist * box->floor_x +
		(1.0 - box->dist) * box->cam.position.x;
		tmp_floor_y = box->dist * box->floor_y +
		(1.0 - box->dist) * box->cam.position.y;
		box->tex_floor_x = (int)(tmp_floor_x * 64) % 64;
		box->tex_floor_y = abs((int)(tmp_floor_y * 64) % 64);
		add_txtrs2(box, j, 11);
		j++;
	}
}

void		up_and_down(t_box *box)
{
	floor_param(box);
	if (box->sky == 0)
		draw_ceiling(box);
	else
		sky_dome(box);
	draw_floor(box);
}
