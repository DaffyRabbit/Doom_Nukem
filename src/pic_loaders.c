/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic_loaders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:28:55 by aperesad          #+#    #+#             */
/*   Updated: 2019/05/10 14:28:58 by aperesad         ###   ########.fr       */
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

SDL_Surface		*ft_check_png(t_box *box, char *text)
{
	SDL_Surface *tmp;
	SDL_Surface *png;

	if ((tmp = IMG_Load(text)) == NULL)
 {
 	ft_putendl("Error HUD file\n");
 	all_destroy(box);		
	exit(1);
 }
 else
 {
 	png = tmp;
 }
 return(png);
}

SDL_Texture		*menu_png(char *text, t_box *box)
{
	SDL_Surface *tmp;
	SDL_Surface *surf;
	SDL_Texture *txtr;

	if ( (tmp = IMG_Load(text)) == NULL)
 	{
 		ft_putendl("Error menu file\n");
 		all_destroy(box);		
		exit(1);
 	}
 	else
	{
		surf = SDL_ConvertSurfaceFormat(tmp, SDL_GetWindowPixelFormat(box->wind), 0);
		txtr = SDL_CreateTextureFromSurface(box->rend, surf);
	}
	return(txtr);
}

void				load_menu_txtrs(t_box *box)
{
	box->menu_txtrs[0] = menu_png("txtrs/sys_0_fon.png", box);
	box->menu_txtrs[1] = menu_png("txtrs/sys_1_bunch.png", box);
	box->menu_txtrs[2] = menu_png("txtrs/sys_2_bch.png", box);
	box->menu_txtrs[3] = menu_png("txtrs/sys_3_nunch.png", box);
	box->menu_txtrs[4] = menu_png("txtrs/sys_4_nch.png", box);
	box->menu_txtrs[5] = menu_png("txtrs/sys_5_start.png", box);
	box->menu_txtrs[6] = menu_png("txtrs/sys_6_create.png", box);
	box->menu_txtrs[7] = menu_png("txtrs/sys_7_exit.png", box);
	box->menu_txtrs[8] = menu_png("txtrs/sys_8_exit.png", box);
	box->menu_txtrs[9] = menu_png("txtrs/sys_txerr.png", box);
}

void				load_wall_textures(t_box *box)
{
	box->txtrs[0] = load_texture("txtrs/rock.bmp", box);
	box->txtrs[1] = load_texture("txtrs/mine.bmp", box);
	box->txtrs[2] = load_texture("txtrs/brick.bmp", box);
	box->txtrs[3] = load_texture("txtrs/Door1.bmp", box);
	box->txtrs[4] = load_texture("txtrs/castle.bmp", box);
	box->txtrs[5] = load_texture("txtrs/ceiling_01.bmp", box);
	box->txtrs[6] = load_texture("txtrs/night_r.bmp", box);
	box->txtrs[7] = load_texture("txtrs/Door1.bmp", box);
	box->sprites.tex_sprite[0] = IMG_Load("txtrs/acid_barel.png");
	box->sprites.tex_sprite[1] = IMG_Load("txtrs/acid.png");
	box->sprites.tex_sprite[2] = IMG_Load("txtrs/lamp.png");
	box->sprites.tex_sprite[3] = IMG_Load("txtrs/table-chairs.png");
	box->sprites.tex_sprite[4] = IMG_Load("txtrs/key.png");
	box->sprites.tex_sprite[5] = IMG_Load("txtrs/dog1.png");
	box->sprites.tex_sprite[6] = IMG_Load("txtrs/dog2.png");
	box->sprites.tex_sprite[7] = IMG_Load("txtrs/dog3.png");
	box->sprites.tex_sprite[8] = IMG_Load("txtrs/dog4.png");
	ft_load_hud_tex(box);
}