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

SDL_Surface		*load_texture(char *path, t_box *wolf)
{
	SDL_Surface		*tmp;
	SDL_Surface		*image;

	tmp = SDL_LoadBMP(path);
	if (tmp == NULL)
	{
		ft_putendl("Error while loading a texture file\n");
		all_destroy(wolf);
		exit(1);
	}
	else
	{
		image = SDL_ConvertSurfaceFormat(tmp, SDL_PIXELFORMAT_ARGB8888, 0);
		SDL_FreeSurface(tmp);
	}
	return (image);
}

////////////////////////////////////////////////////////
/////////////////////////TESTED/////////////////////////
////////////////////////////////////////////////////////
SDL_Surface		*ft_check_png(t_box *box, char *text)
{
	SDL_Surface *tmp;
	SDL_Surface *png;

	if ( (tmp = IMG_Load(text)) == NULL)
 {
 	ft_putendl("Error HUD file\n");
 	all_destroy(box);		
	exit(1);
 }
 else{
 	png = tmp;
 	//SDL_FreeSurface(tmp);
 	}
 return(png);
}

////////////////////////////////////////////////////////
/////////////////////////TESTED/////////////////////////
////////////////////////////////////////////////////////

void				start_game(t_box *box, t_pic *pic, char *name)
{
	SDL_Event		evnt;

	SDL_Init(SDL_INIT_VIDEO);
	box->wind = SDL_CreateWindow(name, 100, 100, WIND_W, WIND_H, 0);
	box->rend = SDL_CreateRenderer(box->wind, -1, SDL_RENDERER_PRESENTVSYNC);
	pic->this_picm0 = load_texture("txtrs/menu0.bmp", box);
	pic->this_picm1 = load_texture("txtrs/menu1.bmp", box);
	pic->this_picm2 = load_texture("txtrs/menu2.bmp", box);
	pic->this_picbm = load_texture("txtrs/bad_map.bmp", box);
	box->start = 1;
	box->error = 0;
	box->mapx = 0;
	box->mapy = 0;
	box->mirror_effect = 0;
	box->light_power = 1.0;
	box->no_shadow = 0;
	pic->this_pic = pic->this_picm0;
	box->texture = SDL_CreateTextureFromSurface(box->rend, pic->this_pic);
	box->pic = pic;
	while (1)
	{
		SDL_PollEvent(&evnt);
		SDL_RenderClear(box->rend);
		menu_keys(evnt.key.keysym.sym, box);
		if (evnt.type == SDL_MOUSEBUTTONDOWN || evnt.type == SDL_MOUSEMOTION)
			menu_mouse(evnt.button.button, evnt.motion.x, evnt.motion.y, box);
		SDL_RenderCopy(box->rend, box->texture, NULL, NULL );
		SDL_RenderPresent(box->rend);		
	}
}

void				lets_start_game(t_box *box)
{
	int				a;
	SDL_Event		evnt;

	add_textures(box);
	box->main_t = SDL_CreateTexture(box->rend, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIND_W, WIND_H);

	box->pixels = (Uint32 *)malloc(sizeof(Uint32) * WIND_H * WIND_W);
	/////////////////////////TESTED_FPS/////////////////////////
	Uint32 FPS = 0;							  
	Uint32 fps_current;						  
	Uint32 fps_lasttime = SDL_GetTicks();	  
	
	/////////////////////////TESTED_FPS/////////////////////////
	while (1)
	{
		/////////////////////////TESTED_FPS/////////////////////////
		
		if(fps_lasttime < SDL_GetTicks() - 1.0 * 1000)
		{
			fps_lasttime = SDL_GetTicks();
			fps_current = FPS;
			FPS = 0;
			printf("FPS = %d\n", fps_current);
		}
		FPS++;
		/////////////////////////TESTED_FPS/////////////////////////
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
		ft_HUD(box);
		paint_this(box);
	}		
}


void				add_textures(t_box *box)
{
	box->txtrs[0] = load_texture("txtrs/bricks.bmp", box);
	box->txtrs[1] = load_texture("txtrs/stone.bmp", box);
	box->txtrs[2] = load_texture("txtrs/eagle.bmp", box);
	box->txtrs[3] = load_texture("txtrs/boards.bmp", box);
	box->txtrs[4] = load_texture("txtrs/fl.bmp", box);
	box->txtrs[5] = load_texture("txtrs/rf.bmp", box);
	ft_load_HUD_tex(box);
}
