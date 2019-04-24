/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:09:09 by arykov            #+#    #+#             */
/*   Updated: 2018/11/30 14:09:10 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			paint_HUD(t_box *box)
{
	SDL_RenderCopy(box->rend, box->HUD.scope_texture, NULL, &box->HUD.rect_scope);
	SDL_RenderCopy(box->rend, box->HUD.bott_bar_texture, NULL, &box->HUD.rect_bott_bar);
	SDL_RenderCopy(box->rend, box->HUD.face[box->num_face].face_texture, NULL, &box->HUD.face[box->num_face].rect_face);
	while (box->HUD.num_i <= 2)
	{
	SDL_RenderCopy(box->rend, box->HUD.heals[box->HUD.num_i].heals_texture, NULL, &box->HUD.heals[box->HUD.num_i].rect_heals);
	box->HUD.num_i++;
	}
	return(0);
}

int			paint_this(t_box *box)
{
	double 	cam_pos_x;
	double	cam_pos_y;
	double	cam_d_x;
	double	cam_d_y;

	SDL_RenderClear(box->rend);
	cam_pos_y = box->cam.position.y;
	cam_pos_x = box->cam.position.x;
	cam_d_y = box->cam.d.y;
	cam_d_x = box->cam.d.x;
	some_pthreads(box);
	just_travel_s(box, cam_pos_x, cam_pos_y, cam_d_x, cam_d_y);
	some_rotation(box);
	SDL_UpdateTexture(box->main_t, NULL, box->pixels, WIND_W * sizeof(Uint32));
	SDL_RenderCopy(box->rend, box->main_t, NULL, NULL );
	paint_HUD(box);
	SDL_RenderPresent(box->rend);
	return (0);
}

void		just_travel_w(t_box *box, double x, double y, double d_x, double d_y)
{
	if (box->keys[SDL_SCANCODE_W] == 1)
	{
		if (!(box->all_map[(int)(y + 0.15)][(int)(x + d_x * box->go.spd)]) &&
			!(box->all_map[(int)(y - 0.15)][(int)(x + d_x * box->go.spd)]) &&
			!(box->all_map[(int)y][(int)(x + d_x * box->go.spd + 0.15)]) &&
			!(box->all_map[(int)y][(int)(x + d_x * box->go.spd - 0.15)]) &&
			!(box->all_map[(int)(y + 0.15)][(int)(x + d_x * box->go.spd - 0.15)]) &&
			!(box->all_map[(int)(y + 0.15)][(int)(x + d_x * box->go.spd + 0.15)]) &&
			!(box->all_map[(int)(y - 0.15)][(int)(x + d_x * box->go.spd - 0.15)]) &&
			!(box->all_map[(int)(y - 0.15)][(int)(x + d_x * box->go.spd + 0.15)]))
			box->cam.position.x += box->cam.d.x * box->go.spd;
		if (!(box->all_map[(int)(y + d_y * box->go.spd)][(int)(x + 0.15)]) &&
			!(box->all_map[(int)(y + d_y * box->go.spd)][(int)(x - 0.15)]) &&
			!(box->all_map[(int)(y + d_y * box->go.spd + 0.15)][(int)x]) &&
			!(box->all_map[(int)(y + d_y * box->go.spd - 0.15)][(int)x]) &&
			!(box->all_map[(int)(y + d_y * box->go.spd + 0.15)][(int)(x + 0.15)]) &&
			!(box->all_map[(int)(y + d_y * box->go.spd + 0.15)][(int)(x - 0.15)]) &&
			!(box->all_map[(int)(y + d_y * box->go.spd - 0.15)][(int)(x + 0.15)]) &&
			!(box->all_map[(int)(y + d_y * box->go.spd - 0.15)][(int)(x - 0.15)]))
			box->cam.position.y += box->cam.d.y * box->go.spd;
	}
	return ;
}

void		just_travel_s(t_box *box, double x, double y, double d_x, double d_y)
{
	if (box->keys[SDL_SCANCODE_S] == 1)
	{
		if (!(box->all_map[(int)y][(int)(x - d_x * box->go.spd + 0.15)]) &&
			!(box->all_map[(int)y][(int)(x - d_x * box->go.spd - 0.15)]) &&
			!(box->all_map[(int)(y + 0.15)][(int)(x - d_x * box->go.spd)]) &&
			!(box->all_map[(int)(y - 0.15)][(int)(x - d_x * box->go.spd)]) &&
			!(box->all_map[(int)(y + 0.15)][(int)(x - d_x * box->go.spd - 0.15)]) &&
			!(box->all_map[(int)(y + 0.15)][(int)(x - d_x * box->go.spd + 0.15)]) &&
			!(box->all_map[(int)(y - 0.15)][(int)(x - d_x * box->go.spd - 0.15)]) &&
			!(box->all_map[(int)(y - 0.15)][(int)(x - d_x * box->go.spd + 0.15)]))
			box->cam.position.x -= box->cam.d.x * box->go.spd;
		if (!(box->all_map[(int)(y - d_y * box->go.spd + 0.15)][(int)x]) &&
			!(box->all_map[(int)(y - d_y * box->go.spd - 0.15)][(int)x]) &&
			!(box->all_map[(int)(y - d_y * box->go.spd)][(int)(x + 0.15)]) &&
			!(box->all_map[(int)(y - d_y * box->go.spd)][(int)(x - 0.15)]) &&
			!(box->all_map[(int)(y - d_y * box->go.spd + 0.15)][(int)(x + 0.15)]) &&
			!(box->all_map[(int)(y - d_y * box->go.spd + 0.15)][(int)(x - 0.15)]) &&
			!(box->all_map[(int)(y - d_y * box->go.spd - 0.15)][(int)(x - 0.15)]) &&
			!(box->all_map[(int)(y - d_y * box->go.spd - 0.15)][(int)(x + 0.15)]))
			box->cam.position.y -= box->cam.d.y * box->go.spd;
	}
	just_travel_w(box, x, y, d_x, d_y);
	go_and_west(box, x, y, box->cam.p.x, box->cam.p.y);
	ttsky_and_sit(box);
}

void		go_and_west(t_box *box, double x, double y, double p_x, double p_y)
{
	if (box->keys[SDL_SCANCODE_A] == 1)
	{
		if (!(box->all_map[(int)y][(int)(x - p_x * box->go.spd + 0.15)]) &&
			!(box->all_map[(int)y][(int)(x - p_x * box->go.spd + 0.15)]) &&
			!(box->all_map[(int)(y + 0.15)][(int)(x - p_x * box->go.spd)]) &&
			!(box->all_map[(int)(y - 0.15)][(int)(x - p_x * box->go.spd)]) &&
			!(box->all_map[(int)(y + 0.15)][(int)(x - p_x * box->go.spd + 0.15)]) &&
			!(box->all_map[(int)(y + 0.15)][(int)(x - p_x * box->go.spd - 0.15)]) &&
			!(box->all_map[(int)(y - 0.15)][(int)(x - p_x * box->go.spd + 0.15)]) &&
			!(box->all_map[(int)(y - 0.15)][(int)(x - p_x * box->go.spd - 0.15)]))
			box->cam.position.x -= box->cam.p.x * box->go.spd;
		if (!(box->all_map[(int)(y - p_y * box->go.spd + 0.15)][(int)x]) &&
			!(box->all_map[(int)(y - p_y * box->go.spd - 0.15)][(int)x]) &&
			!(box->all_map[(int)(y - p_y * box->go.spd)][(int)(x + 0.15)]) &&
			!(box->all_map[(int)(y - p_y * box->go.spd)][(int)(x - 0.15)]) &&
			!(box->all_map[(int)(y - p_y * box->go.spd - 0.15)][(int)(x - 0.15)]) &&
			!(box->all_map[(int)(y - p_y * box->go.spd + 0.15)][(int)(x - 0.15)]) &&
			!(box->all_map[(int)(y - p_y * box->go.spd - 0.15)][(int)(x + 0.15)]) &&
			!(box->all_map[(int)(y - p_y * box->go.spd + 0.15)][(int)(x + 0.15)]))
			box->cam.position.y -= box->cam.p.y * box->go.spd;
	}
	if (box->keys[SDL_SCANCODE_D] == 1)
	{
		if (!(box->all_map[(int)y][(int)(x + p_x * box->go.spd + 0.15)]) && 
			!(box->all_map[(int)y][(int)(x + p_x * box->go.spd - 0.15)]) &&
			!(box->all_map[(int)(y + 0.15)][(int)(x + p_x * box->go.spd)]) &&
			!(box->all_map[(int)(y - 0.15)][(int)(x + p_x * box->go.spd)]) &&
			!(box->all_map[(int)(y + 0.15)][(int)(x + p_x * box->go.spd + 0.15)]) &&
			!(box->all_map[(int)(y - 0.15)][(int)(x + p_x * box->go.spd + 0.15)]) &&
			!(box->all_map[(int)(y + 0.15)][(int)(x + p_x * box->go.spd - 0.15)]) &&
			!(box->all_map[(int)(y - 0.15)][(int)(x + p_x * box->go.spd - 0.15)]))
			box->cam.position.x += box->cam.p.x * box->go.spd;
		if (!(box->all_map[(int)(y + p_y * box->go.spd)][(int)(x + 0.15)]) &&
			!(box->all_map[(int)(y + p_y * box->go.spd)][(int)(x - 0.15)]) &&
			!(box->all_map[(int)(y + p_y * box->go.spd - 0.15)][(int)(x)]) &&
			!(box->all_map[(int)(y + p_y * box->go.spd + 0.15)][(int)(x)]) &&
			!(box->all_map[(int)(y + p_y * box->go.spd - 0.15)][(int)(x + 0.15)]) &&
			!(box->all_map[(int)(y + p_y * box->go.spd + 0.15)][(int)(x + 0.15)]) &&
			!(box->all_map[(int)(y + p_y * box->go.spd - 0.15)][(int)(x - 0.15)]) &&
			!(box->all_map[(int)(y + p_y * box->go.spd + 0.15)][(int)(x - 0.15)]))
			box->cam.position.y += box->cam.p.y * box->go.spd;
	}
}

void		some_rotation(t_box *box)
{
	double	i;

	box->ogo.rot_spd = 0.025;
	if (box->keys[SDL_SCANCODE_SEMICOLON] == 1 || box->keys[SDL_SCANCODE_K] == 1)
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
	if (box->keys[SDL_SCANCODE_O] == 1 && box->ogo.lop < 600)
		box->ogo.lop += 25;
	if (box->keys[SDL_SCANCODE_L] == 1 && box->ogo.lop > -600)
		box->ogo.lop -= 25;
}

void	ttsky_and_sit(t_box *box)
{
	if (box->ttsky2 == 1 && box->go.lop < 0.7)
		box->go.lop += 0.075;
	if (box->go.lop >= 0.7)
		box->ttsky2 = 0;
	if (box->ttsky2 == 0 && box->go.lop > 0)
		box->go.lop -= 0.075;
	if (box->sitd == 1 && box->go.lop > -0.5)
		box->go.lop -= 0.1;
	if (box->sitd == 0 && box->go.lop < 0)
	{
		box->go.lop += 0.1;
		box->go.lop = box->go.lop > 0 ? 0 : box->go.lop;
	}
}
