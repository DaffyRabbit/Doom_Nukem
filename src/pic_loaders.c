/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic_loaders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:46:30 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/19 15:46:31 by aperesad         ###   ########.fr       */
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

SDL_Surface			*ft_check_png(t_box *box, char *text)
{
	SDL_Surface		*tmp;
	SDL_Surface		*png;

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
	return (png);
}

SDL_Texture			*menu_png(char *text, t_box *box)
{
	SDL_Surface		*tmp;
	SDL_Surface		*surf;
	SDL_Texture		*txtr;

	if ((tmp = IMG_Load(text)) == NULL)
	{
		ft_putendl("Error menu file\n");
		all_destroy(box);
		exit(1);
	}
	else
	{
		surf = SDL_ConvertSurfaceFormat(tmp,
			SDL_GetWindowPixelFormat(box->wind), 0);
		txtr = SDL_CreateTextureFromSurface(box->rend, surf);
	}
	SDL_FreeSurface(tmp);
	SDL_FreeSurface(surf);
	return (txtr);
}
