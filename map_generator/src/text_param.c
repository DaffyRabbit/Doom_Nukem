/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:48:55 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/25 19:49:05 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gen.h"

Uint32		c_in_u(SDL_Color color)
{
	return (Uint32)((color.r << 16) + (color.g << 8) + (color.b << 0));
}

int			where_m(int m_x, int m_y, SDL_Rect rect)
{
	if (m_x >= rect.x && m_x < rect.x + rect.w)
		if (m_y >= rect.y && m_y < rect.y + rect.h)
			return (1);
	return (0);
}

int			lcm(void)
{
	return (SDL_GetMouseState(NULL, NULL) == SDL_BUTTON_LMASK);
}

int			lrm(void)
{
	return (SDL_GetMouseState(NULL, NULL) == SDL_BUTTON_RMASK);
}

SDL_Rect	m_trak(void)
{
	int	x;
	int	y;

	SDL_GetMouseState(&x, &y);
	return (new_sdlrect(x, y, 0, 0));
}
