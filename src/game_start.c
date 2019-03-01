/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:45:01 by arykov            #+#    #+#             */
/*   Updated: 2018/11/30 13:45:04 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

SDL_Surface			*load_texture(char *path, t_box *wolf)
{
	SDL_Surface		*tmp;
	SDL_Surface		*image;

	tmp = SDL_LoadBMP(path);
	if (tmp == NULL)
	{
		ft_putendl("Error while loading a texture file\n");
		exit(1);
	}
	else
	{
		image = SDL_ConvertSurfaceFormat(tmp, wolf->surf->format->format, 0);
		SDL_FreeSurface(tmp);
	}
	return (image);
}

void				start_game(t_box *box, t_pic *pic, char *name)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	box->wind = SDL_CreateWindow(name, 100, 100, WIND_W, WIND_H, 0);
	box->surf = SDL_GetWindowSurface(box->wind);
	pic->this_picm0 = load_texture("txtrs/menu0.bmp", box);
	pic->this_picm1 = load_texture("txtrs/menu1.bmp", box);
	pic->this_picm2 = load_texture("txtrs/menu2.bmp", box);
	pic->this_picbm = load_texture("txtrs/bad_map.bmp", box);
	box->start = 1;
	box->error = 0;
	box->mapx = 0;
	box->mapy = 0;
	pic->this_pic = pic->this_picm0;
	SDL_BlitSurface(pic->this_pic, NULL, box->surf, NULL);
	SDL_UpdateWindowSurface(box->wind);
	box->pic = pic;
}

void				lets_start_game(t_box *box)
{
	add_textures(box);
	while (box->event.type != SDL_QUIT)
	{
		SDL_WaitEvent(&box->event);
		SDL_UpdateWindowSurface(box->wind);
		if (box->event.type == SDL_QUIT || (box->event.type == SDL_KEYDOWN
			&& box->event.key.keysym.sym == SDLK_ESCAPE))
		{
			exit(0);
			break ;
		}
		if (box->event.type == SDL_KEYDOWN)
			key_push(box->event.key.keysym.sym, box);
		if (box->event.type == SDL_KEYUP)
			key_rele(box->event.key.keysym.sym, box);
		paint_this(box);
	}
}

void				add_textures(t_box *box)
{
	box->txtrs[0] = load_texture("txtrs/bricks.bmp", box);
	box->txtrs[1] = load_texture("txtrs/stone.bmp", box);
	box->txtrs[3] = load_texture("txtrs/eagle.bmp", box);
	box->txtrs[2] = load_texture("txtrs/boards.bmp", box);
}
