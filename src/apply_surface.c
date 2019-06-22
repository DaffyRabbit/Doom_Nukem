/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_surface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:27:28 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/19 21:27:30 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			apply_surface(int x, int y,
	SDL_Texture *tex, SDL_Renderer *rend)
{
	SDL_Rect	pos;

	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(rend, tex, NULL, &pos);
}

void			apply_texture(int x, int y, t_box *box)
{
	SDL_Rect	pos;
	int			w;
	int			h;

	SDL_QueryTexture(box->this_txtr, NULL, NULL, &w, &h);
	pos.x = x;
	pos.y = y;
	pos.w = w;
	pos.h = h;
	SDL_RenderCopy((*box).rend, (*box).this_txtr, NULL, &pos);
}
