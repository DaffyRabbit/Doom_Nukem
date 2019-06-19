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

#include "wolf3d.h"

SDL_Texture* renderText_purp(char *message, char *fontFile, int fontSize,
					SDL_Renderer *renderer)
{
	SDL_Color color = {147, 28, 190, 0};

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

SDL_Texture* renderText_red(char *message, char *fontFile, int fontSize,
					SDL_Renderer *renderer)
{
	SDL_Color color = {216, 30, 42, 0};
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

SDL_Texture* renderText_blue(char *message, char *fontFile, int fontSize,
					SDL_Renderer *renderer)
{
	SDL_Color color = {51, 51, 255, 0};
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
