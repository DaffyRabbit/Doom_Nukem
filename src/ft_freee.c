/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freee.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 22:03:03 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/17 22:03:05 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_free_surf(t_box *box)
{
	int i;

	i = 0;
	SDL_FreeSurface(box->hud.bar.bott_bar);
	SDL_FreeSurface(box->hud.bar.rad_bar);
	while (i < 13)
	{
		SDL_FreeSurface(box->txtrs[i]);
		i++;
	}
}

void	ft_freee(t_box *box)
{
	int i;

	i = 0;
	ft_free_surf(box);
	while (i < 3)
	{
		SDL_DestroyTexture(box->hud.rad[i].rad_texture);
		SDL_DestroyTexture(box->hud.weapon[i].weapon_texture);
		SDL_FreeSurface(box->hud.face[i].face);
		SDL_DestroyTexture(box->hud.face[i].face_texture);
		i++;
	}
	i = 0;
	while (i < 6)
	{
		SDL_FreeSurface(box->hud.weapon[i].weapon);
		i++;
	}
}

void	ft_music_free(t_box *box)
{
	Mix_HaltMusic();
	Mix_FreeMusic(box->music.bgm);
	Mix_FreeMusic(box->music.bgm_menu);
	Mix_FreeMusic(box->music.dead_sound);
	Mix_FreeMusic(box->music.gta);
	Mix_FreeChunk(box->music.rad);
	Mix_FreeChunk(box->music.knife);
	Mix_FreeChunk(box->music.walk);
	Mix_FreeChunk(box->music.jet);
	Mix_Quit();
}
