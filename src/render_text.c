/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 18:07:35 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/19 18:07:36 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doomnukem.h"

SDL_Texture		*render_text_purp(char *message, char *font_file, int font_size,
					SDL_Renderer *renderer)
{
	TTF_Font	*font;
	SDL_Surface	*surf;
	SDL_Texture	*texture;
	SDL_Color	color;

	color.r = 147;
	color.g = 28;
	color.b = 190;
	color.a = 0;
	font = TTF_OpenFont(font_file, font_size);
	surf = TTF_RenderText_Blended(font, message, color);
	if (surf == NULL || font == NULL)
	{
		TTF_CloseFont(font);
		ft_putendl("text_render error\n");
		return (NULL);
	}
	texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == NULL)
		ft_putendl("error 7\n");
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return (texture);
}

SDL_Texture		*render_text_red(char *message, char *font_file, int font_size,
					SDL_Renderer *renderer)
{
	TTF_Font	*font;
	SDL_Surface	*surf;
	SDL_Texture	*texture;
	SDL_Color	color;

	color.r = 216;
	color.g = 30;
	color.b = 42;
	color.a = 0;
	font = TTF_OpenFont(font_file, font_size);
	surf = TTF_RenderText_Blended(font, message, color);
	if (surf == NULL || font == NULL)
	{
		TTF_CloseFont(font);
		ft_putendl("error 6\n");
		return (NULL);
	}
	texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == NULL)
		ft_putendl("error 7\n");
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return (texture);
}

SDL_Texture		*render_text_blue(char *message, char *font_file, int font_size,
					SDL_Renderer *renderer)
{
	TTF_Font	*font;
	SDL_Surface	*surf;
	SDL_Texture	*texture;
	SDL_Color	color;

	color.r = 51;
	color.g = 51;
	color.b = 255;
	color.a = 0;
	font = TTF_OpenFont(font_file, font_size);
	surf = TTF_RenderText_Blended(font, message, color);
	if (surf == NULL || font == NULL)
	{
		TTF_CloseFont(font);
		ft_putendl("error 6\n");
		return (NULL);
	}
	texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == NULL)
		ft_putendl("error 7\n");
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return (texture);
}
