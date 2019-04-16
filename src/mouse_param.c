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

void	ft_HUD_param(t_box *box)
{
	int i;
	
	i = 0;
	box->HUD.w_scope = 70;
 	box->HUD.h_scope = 70;	
 	box->HUD.w_bott_bar = WIND_W;
 	box->HUD.h_bott_bar = WIND_H/5;
 	box->HUD.rect_bott_bar.x = 0;
 	box->HUD.rect_bott_bar.y = WIND_H - WIND_H/5;
 	box->HUD.rect_bott_bar.w = box->HUD.w_bott_bar;
 	box->HUD.rect_bott_bar.h = box->HUD.h_bott_bar;
 	box->HUD.rect_scope.x = (WIND_W/2) - (box->HUD.w_scope/2);
 	box->HUD.rect_scope.y = (WIND_H/2) - (box->HUD.h_scope/2);
 	box->HUD.rect_scope.w = box->HUD.w_scope;
 	box->HUD.rect_scope.h = box->HUD.h_scope;
 	while (i < 3)
 	{
 		box->HUD.face[i].w_face = 48;
 		box->HUD.face[i].h_face = 48;
 		box->HUD.face[i].rect_face.x = WIND_W/2 - 63;
 		box->HUD.face[i].rect_face.y = WIND_H - WIND_H/5 + 13;
 		box->HUD.face[i].rect_face.w = 130;
 		box->HUD.face[i].rect_face.h = 130;
 		i++;
 	}
 	box->num_face = 0;
 	box->blok = 0;
 	box->sleep = SDL_GetTicks();
 	box->face_start = 0;
}

void	ft_param(t_box *box)
{
	ft_HUD_param(box);
	close(box->map_fd);
	box->error = 1;	
	box->cam.d.x = 1;
	box->cam.d.y = 0;
	box->cam.p.x = 0;
	box->cam.p.y = 0.6;
	box->go.spd = 0.08;
	box->mouse.rot_spd = 0.002;
	lets_start_game(box);

}

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
			ft_param(box);
	}
	return (0);
}
