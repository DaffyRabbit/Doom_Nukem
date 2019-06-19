/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 20:36:42 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/17 20:36:44 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		take3sprite(t_box *box, int j)
{
	int k;
	int l;

	k = 0;
	l = 0;
	box->sprites.n_sprites--;
	while (k < box->sprites.n_sprites)
	{
		if (l != j)
		{
			box->sprites.spt[k] = box->sprites.spt[l];
			k++;
		}
		l++;
	}
}

void		take4sprite(t_box *box, double x, double y)
{
	int		j;
	double	d_x;
	double	d_y;

	d_x = box->cam.d.x;
	d_y = box->cam.d.y;
	j = 0;
	while (j < box->sprites.n_sprites)
	{
		if ((box->sprites.spt[j].x == ((int)x + 0.5) && box->sprites.
			spt[j].y == ((int)(y + d_y * box->go.spd + 0.15) + 0.5)))
			take3sprite(box, j);
		else if ((box->sprites.spt[j].x == ((int)x + 0.5) && box->sprites.
			spt[j].y == ((int)(y + d_y * box->go.spd - 0.15) + 0.5)))
			take3sprite(box, j);
		else if ((box->sprites.spt[j].x == ((int)(x + d_x * box->go.spd +
			0.15) + 0.5) && box->sprites.spt[j].y == ((int)y + 0.5)))
			take3sprite(box, j);
		else if ((box->sprites.spt[j].x == ((int)(x + d_x * box->go.spd -
			0.15) + 0.5) && box->sprites.spt[j].y == ((int)y + 0.5)))
			take3sprite(box, j);
		j++;
	}
}

void		take2sprite(t_box *box, double x, double y)
{
	if (box->bag.n_items == 3)
	{
		box->bag.posX = 5;
		box->bag.posY = box->bag.posY + 50;
	}
	box->bag.items[box->bag.n_items] = 6;
	box->bag.rect[box->bag.n_items].rect_items.x = box->bag.posX;
	box->bag.rect[box->bag.n_items].rect_items.y = box->bag.posY;
	box->bag.rect[box->bag.n_items].rect_items.h = 50;
	box->bag.rect[box->bag.n_items].rect_items.w = 50;
	box->bag.posX = box->bag.posX + 50;
	take4sprite(box, x, y);
	box->bag.n_items++;
}

void		key_cheker(t_box *box, double x, double y)
{
	if ((box->all_map[(int)y][(int)(x + box->cam.d.x * box->go.spd
		+ 0.15)] == 6) && (box->keys[SDL_SCANCODE_E] == 1))
	{
		box->all_map[(int)y][(int)(x + box->cam.d.x * box->go.spd + 0.15)] = 0;
		take2sprite(box, x, y);
	}
	else if ((box->all_map[(int)(y + box->cam.d.y * box->go.spd +
		0.15)][(int)x] == 6) && (box->keys[SDL_SCANCODE_E] == 1))
	{
		box->all_map[(int)(y + box->cam.d.y * box->go.spd + 0.15)][(int)x] = 0;
		take2sprite(box, x, y);
	}
	else if ((box->all_map[(int)y][(int)(x + box->cam.d.x * box->go.spd -
		0.15)] == 6) && (box->keys[SDL_SCANCODE_E] == 1))
	{
		box->all_map[(int)y][(int)(x + box->cam.d.x * box->go.spd - 0.15)] = 0;
		take2sprite(box, x, y);
	}
	else if ((box->all_map[(int)(y + box->cam.d.y * box->go.spd -
		0.15)][(int)x] == 6) && (box->keys[SDL_SCANCODE_E] == 1))
	{
		box->all_map[(int)(y + box->cam.d.y * box->go.spd - 0.15)][(int)x] = 0;
		take2sprite(box, x, y);
	}
}

int			take_sprite(t_box *box, double x, double y)
{
	if (box->bag.n_items == 6)
	{
		box->bag.full_message = renderText_red("Your bag is full!",
			"ttf/mainfont.ttf", 20, (*box).rend);
		return (0);
	}
	SDL_RenderClear(box->rend);
	box->bag.text_item = SDL_CreateTextureFromSurface(box->rend,
		box->sprites.tex_sprite[10]);
	key_cheker(box, x, y);
	return (1);
}
