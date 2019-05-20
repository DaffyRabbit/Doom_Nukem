#include "wolf3d.h"

void	ft_heals_bar(t_box *box)
{
	box->HUD.heals[0].rect_heals.w = 70;
	box->HUD.heals[0].rect_heals.h = 70;
	box->HUD.heals[0].rect_heals.x = 720;
	box->HUD.heals[0].rect_heals.y = WIND_H - WIND_H/5 + 25;
	box->HUD.heals[1].rect_heals.w = 70;
	box->HUD.heals[1].rect_heals.h = 70;
	box->HUD.heals[1].rect_heals.x = 790;
	box->HUD.heals[1].rect_heals.y = WIND_H - WIND_H/5 + 25;
	box->HUD.heals[2].rect_heals.w = 70;
	box->HUD.heals[2].rect_heals.h = 70;
	box->HUD.heals[2].rect_heals.x = 860;
	box->HUD.heals[2].rect_heals.y = WIND_H - WIND_H/5 + 25;
}

void	ft_rad_bar(t_box *box)
{
	
 	box->HUD.bar.rect_rad_bar.y = WIND_H - WIND_H/2;
 	box->HUD.bar.rect_rad_bar.w = 180;
 	box->HUD.bar.rect_rad_bar.h = 80;
 	box->HUD.bar.rect_rad_bar.y = 0;
 	box->HUD.bar.rect_rad_bar.x = 1100;
	box->HUD.rad[1].rect_rad.w = 50;
	box->HUD.rad[1].rect_rad.h = 50;
	box->HUD.rad[1].rect_rad.x = 1135;
	box->HUD.rad[1].rect_rad.y = 30;
	box->HUD.rad[2].rect_rad.w = 50;
	box->HUD.rad[2].rect_rad.h = 50;
	box->HUD.rad[2].rect_rad.x = 1200;
	box->HUD.rad[2].rect_rad.y = 30;	
}

void	ft_weapon_bar(t_box *box)
{
	box->HUD.weapon[0].rect_weapon.w = 250;
	box->HUD.weapon[0].rect_weapon.h = 290;
	box->HUD.weapon[0].rect_weapon.x = WIND_W/2 + 10;
	box->HUD.weapon[0].rect_weapon.y = WIND_H - WIND_H/5 - 290;
}

void	ft_bar(t_box *box)
{
	box->HUD.numb[0] = "txtrs/zero.png";
 	box->HUD.numb[1] = "txtrs/one.png";
 	box->HUD.numb[2] = "txtrs/two.png";
 	box->HUD.numb[3] = "txtrs/three.png";
 	box->HUD.numb[4] = "txtrs/four.png";
 	box->HUD.numb[5] = "txtrs/five.png";
 	box->HUD.numb[6] = "txtrs/six.png";
 	box->HUD.numb[7] = "txtrs/seven.png";
 	box->HUD.numb[8] = "txtrs/eight.png";
 	box->HUD.numb[9] = "txtrs/nine.png";
 	ft_heals_bar(box);
 	ft_rad_bar(box);
 	ft_weapon_bar(box);
}

void	ft_HUD_param(t_box *box)
{
	int i;
	
	i = 0;
 	box->HUD.bar.w_bott_bar = WIND_W;
 	box->HUD.bar.h_bott_bar = WIND_H/5;
 	box->HUD.bar.rect_bott_bar.x = 0;
 	box->HUD.bar.rect_bott_bar.y = WIND_H - WIND_H/5;
 	box->HUD.bar.rect_bott_bar.w = box->HUD.bar.w_bott_bar;
 	box->HUD.bar.rect_bott_bar.h = box->HUD.bar.h_bott_bar;
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
 	box->HUD.face[0].face_start = 0;
 	box->HUD.fire = 0;
 	box->HUD.hp_val = 100;
 	box->HUD.rad_val = 100;
 	box->HUD.time = 5;
 	box->HUD.w_start = 0;
 	box->HUD.w_time = 0;
 	ft_bar(box);
}