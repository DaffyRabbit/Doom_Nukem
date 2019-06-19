/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:25:42 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/19 14:25:43 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		lost_key(t_box *box)
{
	box->bag.n_items--;
	box->bag.posX = box->bag.posX - 50;
	if (box->bag.n_items == 3)
	{
		box->bag.posX = 105;
		box->bag.posY = box->bag.posY - 50;
	}
	box->bag.Message = NULL;
	box->bag.full_message = NULL;
}

void		some_rotation(t_box *box)
{
	double	i;

	box->ogo.rot_spd = 0.025;
	if (box->keys[SDL_SCANCODE_SEMICOLON] == 1 ||
		box->keys[SDL_SCANCODE_K] == 1)
	{
		if (box->keys[SDL_SCANCODE_K] == 1)
			box->ogo.rot_spd = -box->ogo.rot_spd;
		i = box->cam.d.x;
		box->cam.d.x = box->cam.d.x * cos(box->ogo.rot_spd) -
			box->cam.d.y * sin(box->ogo.rot_spd);
		box->cam.d.y = i * sin(box->ogo.rot_spd) +
			box->cam.d.y * cos(box->ogo.rot_spd);
		i = box->cam.p.x;
		box->cam.p.x = box->cam.p.x * cos(box->ogo.rot_spd) -
			box->cam.p.y * sin(box->ogo.rot_spd);
		box->cam.p.y = i * sin(box->ogo.rot_spd) +
			box->cam.p.y * cos(box->ogo.rot_spd);
	}
	if (box->keys[SDL_SCANCODE_O] == 1 && box->ogo.lop < WIND_H / 2)
		box->ogo.lop += 20;
	if (box->keys[SDL_SCANCODE_L] == 1 && box->ogo.lop > -WIND_H / 2)
		box->ogo.lop -= 20;
}

void		ttsky_and_sit(t_box *box)
{
	if (box->ttsky2 == 1 && box->go.lop < 0.55)
		box->go.lop += 0.04;
	if (box->go.lop >= 0.55)
		box->ttsky2 = 0;
	if (box->ttsky2 == 0 && box->go.lop > 0)
		box->go.lop -= 0.04;
	if (box->sitd == 1 && box->go.lop > -0.5)
		box->go.lop -= 0.1;
	if (box->sitd == 0 && box->go.lop < 0)
	{
		box->go.lop += 0.1;
		box->go.lop = box->go.lop > 0 ? 0 : box->go.lop;
	}
}

int			paint_this(t_box *box)
{
	double	cam_pos_x;
	double	cam_pos_y;

	cam_pos_y = box->cam.position.y;
	cam_pos_x = box->cam.position.x;
	SDL_RenderClear(box->rend);
	door_open_message(box, cam_pos_x, cam_pos_y);
	check_doors(box, cam_pos_x, cam_pos_y);
	some_pthreads(box);
	take_sprite(box, cam_pos_x, cam_pos_y);
	just_travel_s(box, cam_pos_x, cam_pos_y, 0.15);
	some_rotation(box);
	SDL_UpdateTexture(box->main_t, NULL, box->pixels, sizeof(Uint32) * WIND_W);
	SDL_RenderCopy(box->rend, box->main_t, NULL, NULL);
	paint_hud(box);
	SDL_RenderPresent(box->rend);
	return (0);
}
