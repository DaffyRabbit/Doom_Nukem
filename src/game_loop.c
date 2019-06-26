/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:26:13 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/19 21:26:15 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doomnukem.h"

void				game_loop(t_box *box, int a)
{
	SDL_Event		evnt;

	while (SDL_PollEvent(&evnt))
	{
		ft_shooting(evnt.button.button, box);
		if (evnt.type == SDL_MOUSEMOTION)
		{
			SDL_SetRelativeMouseMode(1);
			mouse_control(evnt.motion.xrel, evnt.motion.yrel, box);
		}
		a = evnt.key.keysym.scancode;
		if (evnt.type == SDL_QUIT || (evnt.type == SDL_KEYDOWN &&
		evnt.key.keysym.sym == SDLK_ESCAPE))
			all_destroy(box);
		if (evnt.type == SDL_KEYDOWN && a < KEY_CODE)
		{
			box->keys[a] = 1;
			hooks(box);
		}
		else if (evnt.type == SDL_KEYUP && a < KEY_CODE)
			box->keys[a] = 0;
		key_push(box);
	}
	ft_hud(box);
	paint_this(box);
}

void				lets_start_game(t_box *box)
{
	int				a;

	a = 0;
	ft_lets_music(box);
	load_wall_textures(box);
	box->main_t = SDL_CreateTexture(box->rend, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING, WIND_W, WIND_H);
	box->pixels = (Uint32 *)malloc(sizeof(Uint32) * WIND_H * WIND_W);
	while (box->dead != 1)
		game_loop(box, a);
}
