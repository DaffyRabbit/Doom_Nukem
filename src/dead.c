/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 20:34:22 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/17 20:34:24 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	end_level(t_box *box)
{
	SDL_Event		event;

	Mix_HaltMusic();
	Mix_HaltChannel(5);
	Mix_PlayMusic(box->music.gta, -1);
	box->this_txtr = box->texture2;
	while (1)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT || (event.key.keysym.sym == SDLK_ESCAPE &&
			event.key.state == SDL_RELEASED))
			all_destroy(box);
		SDL_RenderClear(box->rend);
		apply_texture(0, 0, box);
		SDL_RenderPresent(box->rend);
	}
}

void	ft_dead(t_box *box)
{
	SDL_Event		event;

	Mix_HaltMusic();
	Mix_HaltChannel(5);
	Mix_PlayMusic(box->music.dead_sound, -1);
	box->this_txtr = box->texture;
	while (1)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT || (event.key.keysym.sym == SDLK_ESCAPE &&
			event.key.state == SDL_RELEASED))
			all_destroy(box);
		SDL_RenderClear(box->rend);
		apply_texture(0, 0, box);
		SDL_RenderPresent(box->rend);
	}
}
