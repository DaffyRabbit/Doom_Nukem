/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:08:57 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/19 15:08:58 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doomnukem.h"

void		just_travel_w(t_box *box, double x, double y, double a)
{
	double		d_x;
	double		d_y;
	double		speed;

	speed = box->go.spd;
	d_x = box->cam.d.x;
	d_y = box->cam.d.y;
	if (box->keys[SDL_SCANCODE_W] == 1)
	{
		ft_check_walk(box);
		if ((box->all_map[(int)(y + a)][(int)(x + d_x * speed - a)]) < 3 &&
			(box->all_map[(int)(y + a)][(int)(x + d_x * speed + a)]) < 3 &&
			(box->all_map[(int)(y - a)][(int)(x + d_x * speed - a)]) < 3 &&
			(box->all_map[(int)(y - a)][(int)(x + d_x * speed + a)]) < 3)
			box->cam.position.x += box->cam.d.x * speed;
		if ((box->all_map[(int)(y + d_y * speed + a)][(int)(x + a)]) < 3 &&
			(box->all_map[(int)(y + d_y * speed + a)][(int)(x - a)]) < 3 &&
			(box->all_map[(int)(y + d_y * speed - a)][(int)(x + a)]) < 3 &&
			(box->all_map[(int)(y + d_y * speed - a)][(int)(x - a)]) < 3)
			box->cam.position.y += box->cam.d.y * speed;
	}
}

void		just_travel_s(t_box *box, double x, double y, double a)
{
	double	d_x;
	double	d_y;
	double	speed;

	speed = box->go.spd;
	d_x = box->cam.d.x;
	d_y = box->cam.d.y;
	if (box->keys[SDL_SCANCODE_S] == 1)
	{
		ft_check_walk(box);
		if ((box->all_map[(int)(y + a)][(int)(x - d_x * speed - a)]) < 3 &&
			(box->all_map[(int)(y + a)][(int)(x - d_x * speed + a)]) < 3 &&
			(box->all_map[(int)(y - a)][(int)(x - d_x * speed - a)]) < 3 &&
			(box->all_map[(int)(y - a)][(int)(x - d_x * speed + a)]) < 3)
			box->cam.position.x -= box->cam.d.x * speed;
		if ((box->all_map[(int)(y - d_y * speed + a)][(int)(x + a)]) < 3 &&
			(box->all_map[(int)(y - d_y * speed + a)][(int)(x - a)]) < 3 &&
			(box->all_map[(int)(y - d_y * speed - a)][(int)(x - a)]) < 3 &&
			(box->all_map[(int)(y - d_y * speed - a)][(int)(x + a)]) < 3)
			box->cam.position.y -= box->cam.d.y * speed;
	}
	just_travel_w(box, x, y, a);
	go_left(box, x, y, a);
	if (box->fly_mode == 0)
		ttsky_and_sit(box);
}

void		go_right(t_box *box, double x, double y, double a)
{
	double	p_x;
	double	p_y;
	double	speed;

	speed = box->go.spd;
	p_x = box->cam.p.x;
	p_y = box->cam.p.y;
	if (box->keys[SDL_SCANCODE_D] == 1)
	{
		ft_check_walk(box);
		if ((box->all_map[(int)(y + a)][(int)(x + p_x * speed + a)]) < 3 &&
			(box->all_map[(int)(y - a)][(int)(x + p_x * speed + a)]) < 3 &&
			(box->all_map[(int)(y + a)][(int)(x + p_x * speed - a)]) < 3 &&
			(box->all_map[(int)(y - a)][(int)(x + p_x * speed - a)]) < 3)
			box->cam.position.x += box->cam.p.x * speed;
		if ((box->all_map[(int)(y + p_y * speed - a)][(int)(x + a)]) < 3 &&
			(box->all_map[(int)(y + p_y * speed + a)][(int)(x + a)]) < 3 &&
			(box->all_map[(int)(y + p_y * speed - a)][(int)(x - a)]) < 3 &&
			(box->all_map[(int)(y + p_y * speed + a)][(int)(x - a)]) < 3)
			box->cam.position.y += box->cam.p.y * speed;
	}
}

void		go_left(t_box *box, double x, double y, double a)
{
	double	p_x;
	double	p_y;
	double	speed;

	speed = box->go.spd;
	p_x = box->cam.p.x;
	p_y = box->cam.p.y;
	if (box->keys[SDL_SCANCODE_A] == 1)
	{
		ft_check_walk(box);
		if ((box->all_map[(int)(y + a)][(int)(x - p_x * speed + a)]) < 3 &&
			(box->all_map[(int)(y + a)][(int)(x - p_x * speed - a)]) < 3 &&
			(box->all_map[(int)(y - a)][(int)(x - p_x * speed + a)]) < 3 &&
			(box->all_map[(int)(y - a)][(int)(x - p_x * speed - a)]) < 3)
			box->cam.position.x -= box->cam.p.x * speed;
		if ((box->all_map[(int)(y - p_y * speed - a)][(int)(x - a)]) < 3 &&
			(box->all_map[(int)(y - p_y * speed + a)][(int)(x - a)]) < 3 &&
			(box->all_map[(int)(y - p_y * speed - a)][(int)(x + a)]) < 3 &&
			(box->all_map[(int)(y - p_y * speed + a)][(int)(x + a)]) < 3)
			box->cam.position.y -= box->cam.p.y * speed;
	}
	go_right(box, x, y, a);
}
