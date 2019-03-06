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

void				lets_start_game(t_box *box)
{
	add_menu(box);
	box->mapx = 0;
	box->mapy = 0;
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
		// >WARNINGS< треба добавити SDL_UpdateTextur але я не встіг з ним розібратись
		SDL_RenderPresent(box->renderer);
	}
}

void	add_menu(t_box *box)
{
	int z = -1;
	int c = -1;
	int l = 0;
	int mnb = 0;
	int q = 0;
	int mousex;
	int mousey;
	SDL_Color color = {245, 58, 6, 0};
	SDL_Texture  *pic;

	while (q == 0)
	{
		while (SDL_PollEvent(&box->event))
		{
			if (box->event.type == SDL_QUIT)
				q = 1;
			if (box->event.type == SDL_KEYUP)
				if (box->event.key.keysym.sym == SDLK_ESCAPE && box->event.key.state == SDL_RELEASED)
					q = 1;
			if (box->event.type == SDL_MOUSEBUTTONUP)
			{
				if (box->event.button.button == SDL_BUTTON_LEFT && box->event.button.state == SDL_RELEASED)
				{
					if ((mousex > 527 && mousex < 727) && (mousey > 447 && mousey < 525) && z != -1)
					{
						printf("%s\n", box->ch_map);
						if ((ft_check_all(box)) == -1)
							close(box->map_fd);
						else
						{
							// Тут краш >WARNINGS<
							box->surf = SDL_GetWindowSurface(box->wind);
							ft_memset(box->surf->pixels, 255, WIND_W * WIND_H * sizeof(int));
							close(box->map_fd);
							box->error = 1;
							box->cam.d.x = 1;
							box->cam.d.y = 0;
							box->cam.p.x = 0;
							box->cam.p.y = 0.6;
							box->go.spd = 0.05;
							q = 2;
						}
					}
					else if ((mousex > 690 && mousex < 846) && (mousey > 628 && mousey < 674))
						q = 1;
					chose_map(mousex, mousey, &z, &c, 1);
				}
			}
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
		box->this_txtr = findeimg(0, box->images);
		ApplyTexture(0, 0, box);
		//back
		if (mnb != 1)
			box->this_txtr = findeimg(1, box->images);
		else
			box->this_txtr = findeimg(2, box->images);
		ApplyTexture(945, 630, box);
		// next
		if (mnb != 2)
			box->this_txtr = findeimg(3, box->images);
		else
			box->this_txtr = findeimg(4, box->images);
		ApplyTexture(1095, 630, box);
		//start
		if (mnb == 3)
		{
			box->this_txtr = findeimg(5, box->images);
			ApplyTexture(519, 468, box);
		}
		// create map
		if (mnb == 4)
		{
			box->this_txtr = findeimg(6, box->images);
			ApplyTexture(555, 538, box);
		}
		//Exit
		if (mnb == 5)
		{
			box->this_txtr = findeimg(8, box->images);
			ApplyTexture(683, 619, box);
		}
		if (box->maplist[0] == NULL)
		{
			pic = renderText("*No any maps*", "ttf/mainfont.ttf", color, 35, box->renderer);
			ApplySurface(944, 412, 0, 0, pic, box->renderer);
		}
		else
			l = add_map_list(&box, l, z, c);
		// pic = renderText("abgfhdrtye...", "ttf/mainfont.ttf", color, 35, box->renderer);
		// ybuf = adfy;
		// while (tsize > 0)
		// {
		// 	ApplySurface(944, ybuf, 0, 0, pic, box->renderer);
		// 	ybuf += 54;
		// 	tsize--;
		// }
		// tsize = 6;
		SDL_RenderPresent(box->renderer);
	}
	if (q == 1)
		fatal_error(7, box);
}

int  add_map_list(t_box **box, int l, int z, int c)
{
	int ch = 0;
	int yb;
	int y = 304;
	int tsize = 6;
	SDL_Texture  *pic;
	SDL_Color color0 = {28, 98, 190, 0};
	SDL_Color color1 = {255, 87, 51, 0};
	SDL_Color color2 = {147, 28, 190, 0};

	while ((**box).maplist[l] && l < (l + 6))
	{
		if (z != ch && c != ch)
			pic = renderText(add_name((**box).maplist[l], '/'), "ttf/mainfont.ttf", color0, 35, (**box).renderer);
		else if (z == ch && c != ch)
		{
			(**box).ch_map = (**box).maplist[l];
			pic = renderText(add_name((**box).maplist[l], '/'), "ttf/mainfont.ttf", color1, 35, (**box).renderer);
		}
		else if (z != ch && c == ch)
			pic = renderText(add_name((**box).maplist[l], '/'), "ttf/mainfont.ttf", color2, 35, (**box).renderer);
		else if (z == ch && c == ch)
			pic = renderText(add_name((**box).maplist[l], '/'), "ttf/mainfont.ttf", color1, 35, (**box).renderer);
		ApplySurface(944, y, 0, 0, pic, (**box).renderer);
		y += 54;
		l++;
		ch++;
	}
	return(0);
}

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
