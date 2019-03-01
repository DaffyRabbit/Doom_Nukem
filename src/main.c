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

int				main(void)
{
	t_box		box;
	t_pic		pic;
	SDL_Event	evnt;

	box.go.south = 0;
	start_game(&box, &pic, "Wolf3d");
	evnt = box.event;
	while (evnt.type != SDL_QUIT)
	{
		SDL_WaitEvent(&evnt);
		SDL_UpdateWindowSurface(box.wind);
		if (evnt.type == SDL_QUIT || (evnt.type == SDL_KEYDOWN &&
			evnt.key.keysym.sym == SDLK_ESCAPE))
		{
			exit(0);
			break ;
		}
		menu_keys(evnt.key.keysym.sym, &box);
		if (evnt.type == SDL_MOUSEBUTTONDOWN || evnt.type == SDL_MOUSEMOTION)
			menu_mouse(evnt.button.button, evnt.motion.x, evnt.motion.y, &box);
	}
	return (0);
}
