/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_animations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 22:04:40 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/17 22:04:42 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_r_bars_face(t_box *box)
{
	SDL_RenderCopy(box->rend, box->hud.bar.bott_bar_texture,
		NULL, &box->hud.bar.rect_bott_bar);
	SDL_RenderCopy(box->rend, box->hud.bar.rad_bar_texture,
		NULL, &box->hud.bar.rect_rad_bar);
	SDL_RenderCopy(box->rend, box->hud.face[box->num_face].face_texture,
		NULL, &box->hud.face[box->num_face].rect_face);
	while (box->hud.hp_i <= 2)
	{
		SDL_RenderCopy(box->rend, box->hud.heals[box->hud.hp_i].heals_texture,
			NULL, &box->hud.heals[box->hud.hp_i].rect_heals);
		box->hud.hp_i++;
	}
	while (box->hud.rad_i <= 2)
	{
		SDL_RenderCopy(box->rend, box->hud.rad[box->hud.rad_i].rad_texture,
			NULL, &box->hud.rad[box->hud.rad_i].rect_rad);
		box->hud.rad_i++;
	}
}

void		ft_start_anim(t_box *box)
{
	if (box->hud.time > 0 && box->hud.time < 10)
		SDL_RenderCopy(box->rend, box->hud.weapon[0].weapon_texture,
			NULL, &box->hud.weapon[0].rect_weapon);
	if (box->hud.time > 10 && box->hud.time < 20)
		SDL_RenderCopy(box->rend, box->hud.weapon[1].weapon_texture,
				NULL, &box->hud.weapon[0].rect_weapon);
	if (box->hud.time > 20 && box->hud.time < 30)
		SDL_RenderCopy(box->rend, box->hud.weapon[2].weapon_texture,
			NULL, &box->hud.weapon[0].rect_weapon);
	if (box->hud.time > 30)
	{
		box->hud.w_start = 1;
		box->hud.time = 0;
	}
}

void		ft_knife_sh(t_box *box)
{
	if (box->hud.fire == 1)
	{
		if (box->hud.w_time >= 0 && box->hud.w_time <= 10)
			SDL_RenderCopy(box->rend, box->hud.weapon[4].weapon_texture,
				NULL, &box->hud.weapon[0].rect_weapon);
		if (box->hud.w_time == 10)
			Mix_PlayChannel(-1, box->music.knife, 0);
		if (box->hud.w_time >= 10 && box->hud.w_time <= 20)
			SDL_RenderCopy(box->rend, box->hud.weapon[5].weapon_texture,
				NULL, &box->hud.weapon[0].rect_weapon);
		if (box->hud.w_time == 20)
		{
			box->hud.w_time = 0;
			box->hud.fire = 0;
		}
		box->hud.w_time++;
	}
	else
		SDL_RenderCopy(box->rend, box->hud.weapon[3].weapon_texture,
			NULL, &box->hud.weapon[0].rect_weapon);
	if (box->hud.time > 30)
		box->hud.time = 0;
}
