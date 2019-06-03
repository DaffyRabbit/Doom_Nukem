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

void chose_map(int x, int y, int *z, int *c, int f)
{
	if (x > 935 && x < 1244)
	{
		if (y > 297 && y < 345)
		{
			if (f == 1)
				*z = 0;
			*c = 0;
		}
		else if (y > 352 && y < 400)
		{
			if (f == 1)
				*z = 1;
			*c = 1;
		}
		else if (y > 407 && y < 455)
		{
			if (f == 1)
				*z = 2;
			*c = 2;
		}
		else if (y > 462 && y < 510)
		{
			if (f == 1)
				*z = 3;
			*c = 3;
		}
		else if (y > 517 && y < 565)
		{
			if (f == 1)
				*z = 4;
			*c = 4;
		}
		else if (y > 572 && y < 620)
		{
			if (f == 1)
				*z = 5;
			*c = 5;
		}
	}
	else
		*c = -1;
}

void ApplySurface(int x, int y, int w, int h, SDL_Texture *tex, SDL_Renderer *rend)
{
   SDL_Rect pos;
   pos.x = x;
   pos.y = y;
   if (w == 0 || h == 0)
		SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
   else
   {
		pos.w = w;
		pos.h = h;
   }
   SDL_RenderCopy(rend, tex, NULL, &pos);
}

SDL_Texture* renderText(char *message, char *fontFile, SDL_Color color, int fontSize,
					SDL_Renderer *renderer)
{
	TTF_Font *font = TTF_OpenFont(fontFile, fontSize);
	if (font == NULL){
		ft_putendl("error 5\n");
		return NULL;
	}	
	SDL_Surface *surf = TTF_RenderText_Blended(font, message, color);
	if (surf == NULL){
		TTF_CloseFont(font);
		ft_putendl("error 6\n");
		return NULL;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == NULL)
		ft_putendl("error 7\n");
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return texture;
}



void	ApplyTexture(int x, int y, t_box *box)
{
	SDL_Rect pos;
	int		w;
	int		h;

	SDL_QueryTexture(box->this_txtr, NULL, NULL, &w, &h);
	pos.x = x;
	pos.y = y;
	pos.w = w;
	pos.h = h;
	SDL_RenderCopy((*box).rend, (*box).this_txtr, NULL, &pos);
}

void				start_game(t_box *box)
{
	int z = -1;
	int c = -1;
	int mnb = 0;
	int q = 0;
	SDL_Event		event;
	box->fly_mode = 0;
	box->error = 0;
	box->mapx = 0;
	box->mapy = 0;
	box->start = 1;
	box->sky = 0; // 0
	box->mirror_effect = 0;
	box->light_power = 1.0;
	box->no_shadow = 1;
	int mousex;
	int mousey;

	ft_init_music(box);
	load_menu_txtrs(box);
	while (1)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				q = 1;
			if (event.type == SDL_QUIT || (event.key.keysym.sym == SDLK_ESCAPE &&
				event.key.state == SDL_RELEASED))
				all_destroy(box);
			if (event.type == SDL_MOUSEBUTTONUP &&
				event.button.button == SDL_BUTTON_LEFT && event.button.state == SDL_RELEASED)
			{
				if ((mousex > 527 && mousex < 727) && (mousey > 447 && mousey < 525) && z != -1)
				{
					if ((ft_check_all(box)) == -1)
					{
						close(box->map_fd);
						all_destroy(box);
					}
					else
					{
						ft_hud_param(box);
						close(box->map_fd);
						box->error = 1;
						box->cam.d.x = 1;
						box->cam.d.y = 0;
						box->cam.p.x = 0;
						box->cam.p.y = 0.66;
						box->go.spd = 0.05;
						box->go.spd = 0.02;
						box->mouse.rot_spd = 0.002;
						lets_start_game(box);
					}
				}
				else if ((mousex > 690 && mousex < 846) && (mousey > 628 && mousey < 674))
					all_destroy(box);
				chose_map(mousex, mousey, &z, &c, 1);
			}
			SDL_RenderClear(box->rend);
			SDL_GetMouseState(&mousex, &mousey);
			if ((mousex > 945 && mousex < 1075) &&
					(mousey > 640 && mousey < 680))
				mnb = 1;
			else if ((mousex > 1095 && mousex < 1230) &&
					(mousey > 640 && mousey < 680))
				mnb = 2;
			else if ((mousex > 527 && mousex < 727) &&
					(mousey > 447 && mousey < 525))
				mnb = 3;
			else if ((mousex > 565 && mousex < 764) &&
					(mousey > 545 && mousey < 620))
				mnb = 4;
			else if ((mousex > 690 && mousex < 846) &&
					(mousey > 628 && mousey < 674))
				mnb = 5;
			else
				mnb = 0;
			chose_map(mousex, mousey, &z, &c, 0);
		}
		box->this_txtr = box->menu_txtrs[0];
		ApplyTexture(0, 0, box);
		//back
		if (mnb != 1)
			box->this_txtr = box->menu_txtrs[1];
		else
			box->this_txtr = box->menu_txtrs[2];
		ApplyTexture(945, 630, box);
		// next
		if (mnb != 2)
			box->this_txtr = box->menu_txtrs[3];
		else
			box->this_txtr = box->menu_txtrs[4];
		ApplyTexture(1095, 630, box);
		//start
		if (mnb == 3)
		{
			box->this_txtr = box->menu_txtrs[5];
			ApplyTexture(519, 468, box);
		}
		// create map
		if (mnb == 4)
		{
			box->this_txtr = box->menu_txtrs[6];
			ApplyTexture(555, 538, box);
		}
		//Exit
		if (mnb == 5)
		{
			box->this_txtr = box->menu_txtrs[7];
			ApplyTexture(683, 619, box);
		}

		/////////////////////////////////////////////////////
		/////////////////////////////////////////////////////
		int ch = 0;
		int y = 304;
		SDL_Texture  *pic;
		SDL_Color color0 = {28, 98, 190, 0};
		SDL_Color color1 = {255, 87, 51, 0};
		SDL_Color color2 = {147, 28, 190, 0};

		pic = NULL;
		if (z != ch && c != ch)
			pic = renderText("map0", "ttf/mainfont.ttf", color0, 35, (*box).rend);
		else if (z == ch && c != ch)
		{
			pic = renderText("map0", "ttf/mainfont.ttf", color1, 35, (*box).rend);
			box->start = 1;
		}
		else if (z != ch && c == ch)
			pic = renderText("map0", "ttf/mainfont.ttf", color2, 35, (*box).rend);
		else if (z == ch && c == ch)
		{
			pic = renderText("map0", "ttf/mainfont.ttf", color1, 35, (*box).rend);
			box->start = 1;
		}
		ApplySurface(944, y, 0, 0, pic, (*box).rend);
		y += 54;
		ch++;
		if (z != ch && c != ch)
			pic = renderText("map1", "ttf/mainfont.ttf", color0, 35, (*box).rend);
		else if (z == ch && c != ch)
		{
			pic = renderText("map1", "ttf/mainfont.ttf", color1, 35, (*box).rend);
			box->start = 2;
		}
		else if (z != ch && c == ch)
			pic = renderText("map1", "ttf/mainfont.ttf", color2, 35, (*box).rend);
		else if (z == ch && c == ch)
		{
			pic = renderText("map1", "ttf/mainfont.ttf", color1, 35, (*box).rend);
			box->start = 2;
		}
		ApplySurface(944, y, 0, 0, pic, (*box).rend);
		y += 54;
		ch++;
		/////////////////////////////////////////////////////
		/////////////////////////////////////////////////////

		SDL_RenderPresent(box->rend);
	}
}

void				lets_start_game(t_box *box)
{
	int				a;
	SDL_Event		evnt;

	ft_lets_music(box);
	load_wall_textures(box);
	box->main_t = SDL_CreateTexture(box->rend, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIND_W, WIND_H);
	box->pixels = (Uint32 *)malloc(sizeof(Uint32) * WIND_H * WIND_W);
	/////////////////////////TESTED_FPS/////////////////////////
	Uint32 FPS = 0;							  
	Uint32 fps_current;						  
	Uint32 fps_lasttime = SDL_GetTicks();	  
	/////////////////////////TESTED_FPS/////////////////////////
	while (box->dead != 1)
	{
		/////////////////////////TESTED_FPS/////////////////////////
		FPS++;
		if(fps_lasttime < SDL_GetTicks() - 1.0 * 1000)
		{
			fps_lasttime = SDL_GetTicks();
			fps_current = FPS;
			FPS = 0;
			printf("FPS = %d\n", fps_current);
		}
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
		ft_hud(box);
		paint_this(box);
	}
}
