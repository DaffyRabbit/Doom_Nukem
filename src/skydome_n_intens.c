/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skydome_n_intens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:39:23 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/19 17:39:25 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doomnukem.h"

double		mirror_effect(t_box *box, int a, double intens)
{
	if (a == 5)
	{
		intens = 0.85;
		return (intens);
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
	return (intens);
}

double		set_intens(t_box *box)
{
	double	intens;

	intens = (box->block.bd < 27) ? (1 / box->block.bd * box->light_power) :
	(0.5 / box->block.bd * box->light_power);
	if (intens > 0.8)
		intens = 0.8;
	return (intens);
}

double		intens_calc(t_box *box, int y, int a)
{
	double	intens;
	int		tmp_y;

	if (box->no_shadow == 1)
		intens = 0.67;
	else
	{
		if (a == 12)
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

void		dome_image(double angle, t_box *box)
{
	angle += M_PI;
	angle += M_PI * box->atpos / 3 / WIND_H;
	angle -= M_PI / 6;
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	box->tex_floor_x = angle * box->txtrs[10]->w / (2 * M_PI);
}

void		sky_dome(t_box *box)
{
	double	angle;
	int		i;
	Uint32	color;

	i = 0;
	angle = asin(box->cam.d.x);
	if (isnan(angle))
		angle = M_PI;
	if (!(box->cam.d.y < 0))
		angle *= -1;
	dome_image(angle, box);
	while (i < box->block.bt)
	{
		box->tex_floor_y = (WIND_H / 2 + i - box->ogo.lop) *
		box->txtrs[10]->h / WIND_H;
		color = ((int *)box->txtrs[10]->pixels)[box->tex_floor_y *
			box->txtrs[10]->w + box->tex_floor_x];
		box->pixels[i * WIND_W + box->atpos] = color;
		i++;
	}
}
