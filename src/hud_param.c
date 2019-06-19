/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 22:07:21 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/17 22:07:22 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_heals_bar(t_box *box)
{
	box->hud.heals[0].rect_heals.w = 70;
	box->hud.heals[0].rect_heals.h = 70;
	box->hud.heals[0].rect_heals.x = 720;
	box->hud.heals[0].rect_heals.y = WIND_H - WIND_H / 5 + 25;
	box->hud.heals[1].rect_heals.w = 70;
	box->hud.heals[1].rect_heals.h = 70;
	box->hud.heals[1].rect_heals.x = 790;
	box->hud.heals[1].rect_heals.y = WIND_H - WIND_H / 5 + 25;
	box->hud.heals[2].rect_heals.w = 70;
	box->hud.heals[2].rect_heals.h = 70;
	box->hud.heals[2].rect_heals.x = 860;
	box->hud.heals[2].rect_heals.y = WIND_H - WIND_H / 5 + 25;
	box->hud.hp_val = 100;
}

void	ft_rad_bar(t_box *box)
{
	box->hud.bar.rect_rad_bar.w = 240;
	box->hud.bar.rect_rad_bar.h = 90;
	box->hud.bar.rect_rad_bar.y = 0;
	box->hud.bar.rect_rad_bar.x = 1040;
	box->hud.rad[1].rect_rad.w = 40;
	box->hud.rad[1].rect_rad.h = 40;
	box->hud.rad[1].rect_rad.x = 1190;
	box->hud.rad[1].rect_rad.y = 30;
	box->hud.rad[2].rect_rad.w = 40;
	box->hud.rad[2].rect_rad.h = 40;
	box->hud.rad[2].rect_rad.x = 1230;
	box->hud.rad[2].rect_rad.y = 30;
}

void	ft_weapon_bar(t_box *box)
{
	box->hud.weapon[0].rect_weapon.w = 250;
	box->hud.weapon[0].rect_weapon.h = 290;
	box->hud.weapon[0].rect_weapon.x = WIND_W / 2 + 10;
	box->hud.weapon[0].rect_weapon.y = WIND_H - WIND_H / 5 - 290;
}

void	ft_bar(t_box *box)
{
	box->hud.numb[0] = "txtrs/zero.png";
	box->hud.numb[1] = "txtrs/one.png";
	box->hud.numb[2] = "txtrs/two.png";
	box->hud.numb[3] = "txtrs/three.png";
	box->hud.numb[4] = "txtrs/four.png";
	box->hud.numb[5] = "txtrs/five.png";
	box->hud.numb[6] = "txtrs/six.png";
	box->hud.numb[7] = "txtrs/seven.png";
	box->hud.numb[8] = "txtrs/eight.png";
	box->hud.numb[9] = "txtrs/nine.png";
	box->hud.bar.rect_bott_bar.x = 0;
	box->hud.bar.rect_bott_bar.y = WIND_H - WIND_H / 5;
	box->hud.bar.rect_bott_bar.w = WIND_W;
	box->hud.bar.rect_bott_bar.h = WIND_H / 5;
	ft_heals_bar(box);
	ft_rad_bar(box);
	ft_weapon_bar(box);
}

void	ft_hud_param(t_box *box)
{
	int i;

	i = 0;
	while (i < 3)
	{
		box->hud.face[i].w_face = 48;
		box->hud.face[i].h_face = 48;
		box->hud.face[i].rect_face.x = WIND_W / 2 - 63;
		box->hud.face[i].rect_face.y = WIND_H - WIND_H / 5 + 13;
		box->hud.face[i].rect_face.w = 130;
		box->hud.face[i].rect_face.h = 130;
		i++;
	}
	box->num_face = 0;
	box->blok = 0;
	box->sleep = SDL_GetTicks();
	box->hud.face[0].face_start = 0;
	box->hud.fire = 0;
	box->hud.rad_val = 0;
	box->hud.rad[0].ticks = 0;
	box->hud.time = 5;
	box->hud.w_start = 0;
	box->hud.w_time = 0;
	box->dead = 0;
	ft_bar(box);
}
