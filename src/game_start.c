/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:12:48 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/19 21:12:49 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			lets_begin(t_box *box)
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

void			press_start(t_box *box, t_arg *arg)
{
	if ((box->mousex > 527 && box->mousex < 727) &&
		(box->mousey > 447 && box->mousey < 525) && arg->z != -1)
	{
		if ((ft_check_all(box)) == -1)
		{
			close(box->map_fd);
			all_destroy(box);
		}
		else
			lets_begin(box);
	}
	else if ((box->mousex > 690 && box->mousex < 846) &&
		(box->mousey > 628 && box->mousey < 674))
		all_destroy(box);
	chose_map(box, arg, 1);
	if_b_or_n(box, arg);
}

void			click_to_map(t_box *box, t_arg *arg)
{
	if ((box->mousex > 945 && box->mousex < 1075) &&
		(box->mousey > 640 && box->mousey < 680))
		arg->mnb = 1;
	else if ((box->mousex > 1095 && box->mousex < 1230) &&
		(box->mousey > 640 && box->mousey < 680))
		arg->mnb = 2;
	else if ((box->mousex > 527 && box->mousex < 727) &&
		(box->mousey > 447 && box->mousey < 525))
		arg->mnb = 3;
	else if ((box->mousex > 565 && box->mousex < 764) &&
		(box->mousey > 545 && box->mousey < 620))
		arg->mnb = 4;
	else if ((box->mousex > 690 && box->mousex < 846) &&
		(box->mousey > 628 && box->mousey < 674))
		arg->mnb = 5;
	else
		arg->mnb = 0;
	chose_map(box, arg, 0);
}

void			start_game(t_box *box)
{
	t_arg		arg;
	SDL_Event	event;

	arg.z = -1;
	arg.c = -1;
	arg.mnb = 0;
	ft_init_music(box);
	load_menu_txtrs(box);
	load_maps(&box->map_list, 0);
	while (1)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT || (event.key.keysym.sym ==
				SDLK_ESCAPE && event.key.state == SDL_RELEASED))
				all_destroy(box);
			if (event.type == SDL_MOUSEBUTTONUP && event.button.button ==
				SDL_BUTTON_LEFT && event.button.state == SDL_RELEASED)
				press_start(box, &arg);
			SDL_RenderClear(box->rend);
			SDL_GetMouseState(&box->mousex, &box->mousey);
			click_to_map(box, &arg);
		}
		map_color(box, &arg);
	}
}
