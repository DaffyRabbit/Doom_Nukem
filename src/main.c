/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:42:09 by arykov            #+#    #+#             */
/*   Updated: 2018/11/30 13:42:11 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(void)
{
	t_box	box;
	t_pic	pic;

	box.go.south = 0;
	start_game(&box, &pic, "Doom-Nukem");
	while (box.event.type != SDL_QUIT)
	{
		SDL_WaitEvent(&box.event);
		SDL_UpdateWindowSurface(box.wind);
		if (box.event.type == SDL_QUIT || (box.event.type == SDL_KEYDOWN && box.event.key.keysym.sym == SDLK_ESCAPE))
		{
			exit(0);
			break;
		}
		menu_keys(box.event.key.keysym.sym, &box);
		if (box.event.type == SDL_MOUSEBUTTONDOWN || box.event.type == SDL_MOUSEMOTION)
			menu_mouse(box.event.button.button, box.event.motion.x, box.event.motion.y, &box);
	}
	return (0);
}

