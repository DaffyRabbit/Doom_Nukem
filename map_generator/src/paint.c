/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:01:08 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/25 20:01:17 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gen.h"

SDL_Rect		new_sdlrect(int x, int y, int width, int height)
{
	SDL_Rect	rect;

	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
	return (rect);
}

void			paint_r(SDL_Surface *s, SDL_Rect rect, SDL_Color color,
	int fill_rect)
{
	SDL_Rect	rc;

	if (fill_rect)
		SDL_FillRect(s, &rect, r_a_i(color.r, color.g, color.b, color.a));
	else
	{
		rc = new_sdlrect(rect.x, rect.y, rect.w, 1);
		SDL_FillRect(s, &rc, r_a_i(color.r, color.g, color.b, color.a));
		rc = new_sdlrect(rect.x, rect.y + rect.h - 1, rect.w, 1);
		SDL_FillRect(s, &rc, r_a_i(color.r, color.g, color.b, color.a));
		rc = new_sdlrect(rect.x, rect.y, 1, rect.h);
		SDL_FillRect(s, &rc, r_a_i(color.r, color.g, color.b, color.a));
		rc = new_sdlrect(rect.x + rect.w - 1, rect.y, 1, rect.h);
		SDL_FillRect(s, &rc, r_a_i(color.r, color.g, color.b, color.a));
	}
}

void			paint_r_2(t_gen *gen, SDL_Surface *s, SDL_Rect rect, Uint32 color,
	int fill_rect)
{
	SDL_Rect	rc;

	gen->mx = gen->mx;
	if (fill_rect)
		SDL_FillRect(s, &rect, color);
	else
	{
		rc = new_sdlrect(rect.x, rect.y, rect.w, 1);
		SDL_FillRect(s, &rc, color);
		//i_need_tx(gen, s, "NUM", rc);
		rc = new_sdlrect(rect.x, rect.y + rect.h - 1, rect.w, 1);
		SDL_FillRect(s, &rc, color);
		rc = new_sdlrect(rect.x, rect.y, 1, rect.h);
		SDL_FillRect(s, &rc, color);
		rc = new_sdlrect(rect.x + rect.w - 1, rect.y, 1, rect.h);
		SDL_FillRect(s, &rc, color);
	}
}
