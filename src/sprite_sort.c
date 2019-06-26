/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite-sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:08:40 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/19 16:08:42 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doomnukem.h"

void		comb_sort(t_box *box, int amount)
{
	int		i;
	int		j;

	i = 0;
	while (i < amount - 1)
	{
		j = 0;
		while (j < amount - i - 1)
		{
			if (box->sprites.sprite_distance[j] <
				box->sprites.sprite_distance[j + 1])
			{
				ft_my_swap1(box, j, j + 1);
				ft_my_swap2(box, j, j + 1);
			}
			j++;
		}
		i++;
	}
}

double		set_sprite_intens(t_box *box)
{
	double	intens;

	intens = (box->sprites.sprite_distance[box->dsprite.i] < 27) ?
		(1 / box->sprites.sprite_distance[box->dsprite.i] * box->light_power) :
		(0.5 / box->sprites.sprite_distance[box->dsprite.i] * box->light_power);
	if (intens > 0.8)
		intens = 0.8;
	return (intens);
}

Uint32		get_pixel(t_box *box, SDL_Surface *surface, int x, int y)
{
	Uint32	color;
	Uint8	r;
	Uint8	g;
	Uint8	b;
	double	intens;

	color = 0;
	if (box->no_shadow == 1 || box->mirror_effect == 1 ||
		box->sprites.spt[box->sprites.sprite_order[box->dsprite.i]].n_text == 2)
		intens = (box->no_shadow == 1) ? 0.68 : 0.8;
	else if (box->sprites.sprite_distance[box->dsprite.i] >= 0)
		intens = set_sprite_intens(box);
	if ((x >= 0 && x <= 64) && (y >= 0 && y <= 64))
	{
		SDL_GetRGB(((int *)surface->pixels)[(y * surface->w) + x],
			surface->format, &r, &g, &b);
		if (r == 152 && g == 0 && b == 136)
			return (0);
		r = r * intens;
		g = g * intens;
		b = b * intens;
		color = SDL_MapRGB(surface->format, r, g, b);
	}
	return (color);
}

void		sort_sprits(t_box *box)
{
	int		i;

	i = 0;
	while (i < box->sprites.n_sprites)
	{
		box->sprites.sprite_order[i] = i;
		box->sprites.sprite_distance[i] = ((box->cam.position.x -
		box->sprites.spt[i].x) * (box->cam.position.x -
		box->sprites.spt[i].x) + (box->cam.position.y - box->sprites.spt[i].y) *
		(box->cam.position.y - box->sprites.spt[i].y));
		i++;
	}
	comb_sort(box, box->sprites.n_sprites);
}
