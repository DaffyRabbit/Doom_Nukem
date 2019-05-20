/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:00:59 by arykov            #+#    #+#             */
/*   Updated: 2018/11/30 14:13:04 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	change_map(t_box *box)
{
	if (box->start == 1)
		box->pic->this_pic = box->pic->this_picm0;
	else if (box->start == 2)
		box->pic->this_pic = box->pic->this_picm1;
	else if (box->start == 3)
		box->pic->this_pic = box->pic->this_picm2;
	else if (box->start == 0)
		box->pic->this_pic = box->pic->this_picbm;
}

int		menu_mouse(int code, int x, int y, t_box *box)
{
	if (code == SDL_BUTTON_LEFT && box->error == 0)
	{
		if ((x > 1030 && x < 1140) && (y > 62 && y < 105))
		{
			box->start = 1;
			change_map(box);
		}
		else if ((x > 1030 && x < 1140) && (y > 120 && y < 160))
		{
			box->start = 2;
			change_map(box);
		}
		else if ((x > 1030 && x < 1140) && (y > 174 && y < 215))
		{
			box->start = 3;
			change_map(box);
		}
		else if ((x > 565 && x < 710) && (y > 470 && y < 520))
			exit_this();
		menu_mouse_click(x, y, box);
		box->texture = SDL_CreateTextureFromSurface(box->rend, box->pic->this_pic);
	}
	return (0);
}

int		menu_mouse_click(int x, int y, t_box *box)
{
	if ((x > 540 && x < 738) && (y > 365 && y < 417))
	{
		if ((ft_check_all(box)) == -1)
		{
			box->start = 0;
			close(box->map_fd);
			change_map(box);
		}
		else
		{
			ft_HUD_param(box);
			close(box->map_fd);
			box->error = 1;
			box->cam.d.x = 1;
			box->cam.d.y = 0;
			box->cam.p.x = 0;
			box->cam.p.y = 0.66;
			box->go.spd = 0.02;
			box->mouse.rot_spd = 0.002;
			lets_start_game(box);
		}
	}
	return (0);
}
