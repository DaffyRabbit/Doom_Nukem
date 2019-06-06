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

void		healt_pickup(t_box *box, double x, double y)
{
	double	a = 0.05; 	
	
	if ((box->all_map[(int)(y + a)][(int)(x - a)]) == 2)
	{
		box->all_map[(int)(y + a)][(int)(x - a)] = 0;
		box->hud.hp_val = box->hud.hp_val < 75 ? box->hud.hp_val + 25 : 100;
		box->hud.rad_val = box->hud.rad_val < 25 ? 0 : box->hud.rad_val - 25;
	}
	else if ((box->all_map[(int)(y + a)][(int)(x + a)]) == 2)
	{
		box->all_map[(int)(y + a)][(int)(x + a)] = 0;
		box->hud.hp_val = box->hud.hp_val < 75 ? box->hud.hp_val + 25 : 100;
		box->hud.rad_val = box->hud.rad_val < 25 ? 0 : box->hud.rad_val - 25;
	}
	else if ((box->all_map[(int)(y - a)][(int)(x - a)]) == 2)
	{
		box->all_map[(int)(y - a)][(int)(x - a)] = 0;
		box->hud.hp_val = box->hud.hp_val < 75 ? box->hud.hp_val + 25 : 100;
		box->hud.rad_val = box->hud.rad_val < 25 ? 0 : box->hud.rad_val - 25;
	}
	else if ((box->all_map[(int)(y - a)][(int)(x + a)]) == 2)
	{
		box->all_map[(int)(y - a)][(int)(x + a)] = 0;
		box->hud.hp_val = box->hud.hp_val < 75 ? box->hud.hp_val + 25 : 100;
		box->hud.rad_val = box->hud.rad_val < 25 ? 0 : box->hud.rad_val - 25;
	}
}

void		door_open_message(t_box *box, double x, double y, double d_x, double d_y)
{
	double	dist_x;
	double	dist_y;

	SDL_Color color = {51, 51, 255, 0};
	dist_x = fabs(d_x) > fabs(d_y) ? d_x : 0;
	dist_y = fabs(d_x) <= fabs(d_y) ? d_y : 0;
	if (box->all_map[(int)(y + dist_y)][(int)(x + dist_x + 0.15)] == 34 &&
		box->bag.Message == NULL)
		box->bag.Message = renderText("Press 'E' to open the doors", 
			"ttf/mainfont.ttf", color, 22, (*box).rend);
	else if (box->all_map[(int)(y + dist_y)][(int)(x + dist_x + 0.15)] != 34)
		box->bag.Message = NULL;
}

void		check_doors(t_box *box, double x, double y, double d_x, double d_y)
{
	double	dist_x;
	double	dist_y;

	healt_pickup(box, x, y);
	SDL_Color color = {216, 30, 42, 0};
	dist_x = fabs(d_x) > fabs(d_y) ? d_x : 0;
	dist_y = fabs(d_x) <= fabs(d_y) ? d_y : 0;
	if (box->keys[SDL_SCANCODE_E] == 1 && box->bag.n_items > 0 &&
		box->all_map[(int)(y + dist_y)][(int)(x + dist_x + 0.15)] == 34)
	{
		box->all_map[(int)(y + dist_y)][(int)(x + dist_x + 0.15)] = 1;
		lost_key(box);
	}
	else if (box->keys[SDL_SCANCODE_E] == 1 && box->bag.n_items <= 0 &&
		box->all_map[(int)(y + dist_y)][(int)(x + dist_x + 0.15)] == 34)
	{
		box->bag.Message = NULL;
		box->bag.Message = renderText("You don't have keys!", 
			"ttf/mainfont.ttf", color, 30, (*box).rend);
		box->bag.time = 1;
	}
	if (box->bag.time == 75)
		box->bag.Message = NULL;
	box->bag.time = (box->bag.time > 90) ? 0 : (box->bag.time + 1);
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
	door_open_message(box, cam_pos_x, cam_pos_y, cam_d_x, cam_d_y);
	check_doors(box, cam_pos_x, cam_pos_y, cam_d_x, cam_d_y);
	some_pthreads(box);
	takeSprite(box, cam_pos_x, cam_pos_y, cam_d_x, cam_d_y);
	just_travel_s(box, cam_pos_x, cam_pos_y, cam_d_x, cam_d_y);
	some_rotation(box);
	SDL_UpdateTexture(box->main_t, NULL, box->pixels, WIND_W * sizeof(Uint32));
	SDL_RenderCopy(box->rend, box->main_t, NULL, NULL );
	paint_hud(box);
	SDL_RenderPresent(box->rend);
	return (0);
}


void		just_travel_w(t_box *box, double x, double y, double d_x, double d_y)
{
	double		a;

	a = 0.15;
	if (box->keys[SDL_SCANCODE_W] == 1)
	{
		ft_check_walk(box);
		if ((box->all_map[(int)(y + a)][(int)(x + d_x * box->go.spd - a)]) < 3 &&
			(box->all_map[(int)(y + a)][(int)(x + d_x * box->go.spd + a)]) < 3 &&
			(box->all_map[(int)(y - a)][(int)(x + d_x * box->go.spd - a)]) < 3 &&
			(box->all_map[(int)(y - a)][(int)(x + d_x * box->go.spd + a)]) < 3)
			box->cam.position.x += box->cam.d.x * box->go.spd;
		if ((box->all_map[(int)(y + d_y * box->go.spd + a)][(int)(x + a)]) < 3 &&
			(box->all_map[(int)(y + d_y * box->go.spd + a)][(int)(x - a)]) < 3 &&
			(box->all_map[(int)(y + d_y * box->go.spd - a)][(int)(x + a)]) < 3 &&
			(box->all_map[(int)(y + d_y * box->go.spd - a)][(int)(x - a)]) < 3)
			box->cam.position.y += box->cam.d.y * box->go.spd;
	}
	return ;
}

void		just_travel_s(t_box *box, double x, double y, double d_x, double d_y)
{
	double a;

	a = 0.15;
	if (box->keys[SDL_SCANCODE_S] == 1)
	{
		ft_check_walk(box);
		if ((box->all_map[(int)(y + a)][(int)(x - d_x * box->go.spd - a)]) < 3 &&
			(box->all_map[(int)(y + a)][(int)(x - d_x * box->go.spd + a)]) < 3 &&
			(box->all_map[(int)(y - a)][(int)(x - d_x * box->go.spd - a)]) < 3 &&
			(box->all_map[(int)(y - a)][(int)(x - d_x * box->go.spd + a)]) < 3)
			box->cam.position.x -= box->cam.d.x * box->go.spd;
		if ((box->all_map[(int)(y - d_y * box->go.spd + a)][(int)(x + a)]) < 3 &&
			(box->all_map[(int)(y - d_y * box->go.spd + a)][(int)(x - a)]) < 3 &&
			(box->all_map[(int)(y - d_y * box->go.spd - a)][(int)(x - a)]) < 3 &&
			(box->all_map[(int)(y - d_y * box->go.spd - a)][(int)(x + a)]) < 3)
			box->cam.position.y -= box->cam.d.y * box->go.spd;
	}
	just_travel_w(box, x, y, d_x, d_y);
	go_and_west(box, x, y, box->cam.p.x, box->cam.p.y);
	if (box->fly_mode == 0)
		ttsky_and_sit(box);
}

void		go_and_west(t_box *box, double x, double y, double p_x, double p_y)
{
	double a;

	a = 0.15;
	if (box->keys[SDL_SCANCODE_A] == 1)
	{
		ft_check_walk(box);
		if ((box->all_map[(int)(y + a)][(int)(x - p_x * box->go.spd + a)]) < 3 &&
			(box->all_map[(int)(y + a)][(int)(x - p_x * box->go.spd - a)]) < 3 &&
			(box->all_map[(int)(y - a)][(int)(x - p_x * box->go.spd + a)]) < 3 &&
			(box->all_map[(int)(y - a)][(int)(x - p_x * box->go.spd - a)]) < 3)
			box->cam.position.x -= box->cam.p.x * box->go.spd;
		if ((box->all_map[(int)(y - p_y * box->go.spd - a)][(int)(x - a)]) < 3 &&
			(box->all_map[(int)(y - p_y * box->go.spd + a)][(int)(x - a)]) < 3 &&
			(box->all_map[(int)(y - p_y * box->go.spd - a)][(int)(x + a)]) < 3 &&
			(box->all_map[(int)(y - p_y * box->go.spd + a)][(int)(x + a)]) < 3)
			box->cam.position.y -= box->cam.p.y * box->go.spd;
	}
	if (box->keys[SDL_SCANCODE_D] == 1)
	{
		ft_check_walk(box);
		if ((box->all_map[(int)(y + a)][(int)(x + p_x * box->go.spd + a)]) < 3 &&
			(box->all_map[(int)(y - a)][(int)(x + p_x * box->go.spd + a)]) < 3 &&
			(box->all_map[(int)(y + a)][(int)(x + p_x * box->go.spd - a)]) < 3 &&
			(box->all_map[(int)(y - a)][(int)(x + p_x * box->go.spd - a)]) < 3)
			box->cam.position.x += box->cam.p.x * box->go.spd;
		if ((box->all_map[(int)(y + p_y * box->go.spd - a)][(int)(x + a)]) < 3 &&
			(box->all_map[(int)(y + p_y * box->go.spd + a)][(int)(x + a)]) < 3 &&
			(box->all_map[(int)(y + p_y * box->go.spd - a)][(int)(x - a)]) < 3 &&
			(box->all_map[(int)(y + p_y * box->go.spd + a)][(int)(x - a)]) < 3)
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
	if (box->keys[SDL_SCANCODE_O] == 1 && box->ogo.lop < WIND_H / 2)
		box->ogo.lop += 20;
	if (box->keys[SDL_SCANCODE_L] == 1 && box->ogo.lop > -WIND_H / 2)
		box->ogo.lop -= 20;
}

void	ttsky_and_sit(t_box *box)
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
