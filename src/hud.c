/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 22:04:08 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/17 22:04:09 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_face_start(t_box *box)
{
	box->hud.face[box->num_face].face_texture =
	SDL_CreateTextureFromSurface(box->rend, box->hud.face[box->num_face].face);
	if (box->num_face == 2)
	{
		box->blok = 1;
		box->num_face--;
	}
	else
	{
		if (box->num_face == 1 && box->blok == 1)
		{
			box->num_face--;
			box->blok = 0;
		}
		else
			box->num_face++;
	}
	return (0);
}

int		ft_face(t_box *box)
{
	if (box->sleep < SDL_GetTicks() - 1.0 * 900)
	{
		ft_face_start(box);
		box->sleep = SDL_GetTicks();
	}
	return (0);
}

int		ft_hud_bar(t_box *box)
{
	box->hud.bar.bott_bar_texture =
	SDL_CreateTextureFromSurface(box->rend, box->hud.bar.bott_bar);
	box->hud.bar.rad_bar_texture =
	SDL_CreateTextureFromSurface(box->rend, box->hud.bar.rad_bar);
	return (0);
}

int		ft_weapon(t_box *box)
{
	int i;

	i = 0;
	while (i < 6)
	{
		box->hud.weapon[i].weapon_texture =
		SDL_CreateTextureFromSurface(box->rend, box->hud.weapon[i].weapon);
		i++;
	}
	return (0);
}

int		ft_hud(t_box *box)
{
	ft_hud_bar(box);
	ft_weapon(box);
	if (box->hud.face[0].face_start < 3)
	{
		ft_face_start(box);
		box->hud.face[0].face_start++;
	}
	else
		ft_face(box);
	ft_all_bars(box);
	return (0);
}
