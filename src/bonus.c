/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:38:05 by arykov            #+#    #+#             */
/*   Updated: 2018/11/30 13:41:04 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			some_pthreads(t_box *box)
{
	t_box		this_is_sheet[8];
	pthread_t	t[8];
	int			i;

	i = 0;
	while (i < 8)
	{
		ft_memcpy((void*)&this_is_sheet[i], (void*)box, sizeof(t_box));
		this_is_sheet[i].atpos = i * (WIND_W / 8 + 1);
		this_is_sheet[i].tpos = (i + 1) * (WIND_W / 8 + 1);
		pthread_create(&t[i], NULL, thi_is_raycast, &this_is_sheet[i]);
		++i;
	}
	i = 0;
	while (i < 8)
	{
		pthread_join(t[i], NULL);
		i++;
	}
}

void			*thi_is_raycast(void *his_is_sheet)
{
	t_box		box;

	box = *(t_box *)his_is_sheet;
	while (box.atpos < box.tpos && box.atpos < WIND_W)
	{
		ray_start(&box);
		this_is_castingray(&box);
		some_blocks(&box);
		print_walls(&box);
		box.atpos++;
	}
	return (0);
}

void			colorize_this(t_box *box)
{
	Uint32		color;
	/*Uint32		black;
	Uint8		r;
	Uint8		g;
	Uint8		b;

	black = 0x000000;
	//////////
	double intens;
	double b_int;
	intens = 0.0;
	if (box->block.bd >= 25)
	{
		intens = 0.0;
		b_int = 1.0;
	}
	else if (box->block.bd >= 0)
	{
		intens = (1 / box->block.bd * 1.5);
		if (intens > 1.0)
			intens = 1.0;
		b_int = 1 - intens;
	}*/
	////////
	color = box->coloriz;
	if (box->atpos < WIND_W && box->btpos < WIND_H)
	{
		// SDL_GetRGB(color, box->txtrs[5]->format, &r, &g, &b);
		// r = r * intens + black + b_int;
		// g = g * intens + black * b_int;
		// b = b * intens + intens + black * b_int;
		// color = SDL_MapRGB(box->txtrs[5]->format, r, g, b);
		box->pixels[box->btpos * WIND_W + box->atpos] = color;
	}
}
