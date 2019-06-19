/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_n_doors_messages.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:11:08 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/19 15:11:09 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		health_changing(t_box *box, double x, double y)
{
	take4sprite(box, x, y);
	box->hud.hp_val = box->hud.hp_val < 75 ? box->hud.hp_val + 25 : 100;
	box->hud.rad_val = box->hud.rad_val < 20 ? 0 : box->hud.rad_val - 20;
}

void		health_pickup(t_box *box, double x, double y, double a)
{
	double	d_x;
	double	d_y;

	d_x = box->cam.d.x;
	d_y = box->cam.d.y;
	if ((box->all_map[(int)(y)][(int)(x + d_x * box->go.spd - a)]) == 2)
	{
		box->all_map[(int)(y)][(int)(x + d_x * box->go.spd - a)] = 0;
		health_changing(box, x, y);
	}
	else if ((box->all_map[(int)(y + d_y * box->go.spd + a)][(int)(x)]) == 2)
	{
		box->all_map[(int)(y + d_y * box->go.spd + a)][(int)(x)] = 0;
		health_changing(box, x, y);
	}
	else if ((box->all_map[(int)(y + d_y * box->go.spd - a)][(int)(x)]) == 2)
	{
		box->all_map[(int)(y + d_y * box->go.spd - a)][(int)(x)] = 0;
		health_changing(box, x, y);
	}
	else if ((box->all_map[(int)(y)][(int)(x + d_x * box->go.spd + a)]) == 2)
	{
		box->all_map[(int)(y)][(int)(x + d_x * box->go.spd + a)] = 0;
		health_changing(box, x, y);
	}
}

void		graal_message(t_box *box, double x, double y)
{
	double	dist_x;
	double	dist_y;

	dist_x = fabs(box->cam.d.x) > fabs(box->cam.d.y) ? box->cam.d.x : 0;
	dist_y = fabs(box->cam.d.x) <= fabs(box->cam.d.y) ? box->cam.d.y : 0;
	if (box->all_map[(int)(y + dist_y)][(int)(x + dist_x + 0.15)] == 9 &&
		box->bag.Message == NULL)
		box->bag.Message = renderText_blue("Press 'E' to end the level",
			"ttf/mainfont.ttf", 22, (*box).rend);
	else if (box->all_map[(int)(y + dist_y)][(int)(x + dist_x + 0.15)] != 34
		&& box->all_map[(int)(y + dist_y)][(int)(x + dist_x + 0.15)] != 9)
		box->bag.Message = NULL;
	if (box->keys[SDL_SCANCODE_E] == 1 &&
		box->all_map[(int)(y + dist_y)][(int)(x + dist_x + 0.15)] == 9)
		end_level(box);
}

void		door_open_message(t_box *box, double x, double y)
{
	double	dist_x;
	double	dist_y;

	dist_x = fabs(box->cam.d.x) > fabs(box->cam.d.y) ? box->cam.d.x : 0;
	dist_y = fabs(box->cam.d.x) <= fabs(box->cam.d.y) ? box->cam.d.y : 0;
	if (box->all_map[(int)(y + dist_y)][(int)(x + dist_x + 0.15)] == 34 &&
		box->bag.Message == NULL)
		box->bag.Message = renderText_blue("Press 'E' to open the doors",
			"ttf/mainfont.ttf", 22, (*box).rend);
	else if (box->all_map[(int)(y + dist_y)][(int)(x + dist_x + 0.15)] != 34
		&& box->all_map[(int)(y + dist_y)][(int)(x + dist_x + 0.15)] != 9)
		box->bag.Message = NULL;
	graal_message(box, x, y);
}

void		check_doors(t_box *box, double x, double y)
{
	double	dist_x;
	double	dist_y;

	health_pickup(box, x, y, 0.05);
	dist_x = fabs(box->cam.d.x) > fabs(box->cam.d.y) ? box->cam.d.x : 0;
	dist_y = fabs(box->cam.d.x) <= fabs(box->cam.d.y) ? box->cam.d.y : 0;
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
		box->bag.Message = renderText_red("You don't have keys!",
			"ttf/mainfont.ttf", 30, (*box).rend);
		box->bag.time = 1;
	}
	if (box->bag.time == 75)
		box->bag.Message = NULL;
	box->bag.time = (box->bag.time > 90) ? 0 : (box->bag.time + 1);
}
