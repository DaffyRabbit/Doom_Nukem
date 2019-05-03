#include "wolf3d.h"

void	ft_heals_bar(t_box *box)
{
	box->HUD.heals[0].rect_heals.w = 70;
	box->HUD.heals[0].rect_heals.h = 70;
	box->HUD.heals[0].rect_heals.x = 200;
	box->HUD.heals[0].rect_heals.y = WIND_H - WIND_H/5 + 25;
	box->HUD.heals[1].rect_heals.w = 70;
	box->HUD.heals[1].rect_heals.h = 70;
	box->HUD.heals[1].rect_heals.x = 270;
	box->HUD.heals[1].rect_heals.y = WIND_H - WIND_H/5 + 25;
	box->HUD.heals[2].rect_heals.w = 70;
	box->HUD.heals[2].rect_heals.h = 70;
	box->HUD.heals[2].rect_heals.x = 340;
	box->HUD.heals[2].rect_heals.y = WIND_H - WIND_H/5 + 25;
}

void	ft_armor_bar(t_box *box)
{
	box->HUD.armor[0].rect_armor.w = 70;
	box->HUD.armor[0].rect_armor.h = 70;
	box->HUD.armor[0].rect_armor.x = 720;
	box->HUD.armor[0].rect_armor.y = WIND_H - WIND_H/5 + 25;
	box->HUD.armor[1].rect_armor.w = 70;
	box->HUD.armor[1].rect_armor.h = 70;
	box->HUD.armor[1].rect_armor.x = 790;
	box->HUD.armor[1].rect_armor.y = WIND_H - WIND_H/5 + 25;
	box->HUD.armor[2].rect_armor.w = 70;
	box->HUD.armor[2].rect_armor.h = 70;
	box->HUD.armor[2].rect_armor.x = 860;
	box->HUD.armor[2].rect_armor.y = WIND_H - WIND_H/5 + 25;	
}

void	ft_ammo_bar(t_box *box)
{
	box->HUD.ammo[1].rect_ammo.w = 70;
	box->HUD.ammo[1].rect_ammo.h = 70;
	box->HUD.ammo[1].rect_ammo.x = 45;
	box->HUD.ammo[1].rect_ammo.y = WIND_H - WIND_H/5 + 25;
	box->HUD.ammo[2].rect_ammo.w = 70;
	box->HUD.ammo[2].rect_ammo.h = 70;
	box->HUD.ammo[2].rect_ammo.x = 115;
	box->HUD.ammo[2].rect_ammo.y = WIND_H - WIND_H/5 + 25;	
}

void	ft_frag_bar(t_box *box)
{
	box->HUD.frag[1].rect_frag.w = 70;
	box->HUD.frag[1].rect_frag.h = 70;
	box->HUD.frag[1].rect_frag.x = 425;
	box->HUD.frag[1].rect_frag.y = WIND_H - WIND_H/5 + 25;
	box->HUD.frag[2].rect_frag.w = 70;
	box->HUD.frag[2].rect_frag.h = 70;
	box->HUD.frag[2].rect_frag.x = 495;
	box->HUD.frag[2].rect_frag.y = WIND_H - WIND_H/5 + 25;
}

void	ft_rifle_bar(t_box *box)
{
	box->HUD.rifle[0].rect_rifle.w = 200;
	box->HUD.rifle[0].rect_rifle.h = 200;
	box->HUD.rifle[0].rect_rifle.x = WIND_W/2 - 105;
	box->HUD.rifle[0].rect_rifle.y = WIND_H - WIND_H/5 - 200;
	// box->HUD.rifle[1].rect_rifle.w = 200;
	// box->HUD.rifle[1].rect_rifle.h = 200;
	// box->HUD.rifle[1].rect_rifle.x = WIND_W/2 - 105;
	// box->HUD.rifle[1].rect_rifle.y = WIND_H - WIND_H/5 - 200;
	// box->HUD.rifle[2].rect_rifle.w = 200;
	// box->HUD.rifle[2].rect_rifle.h = 250;
	// box->HUD.rifle[2].rect_rifle.x = WIND_W/2 - 105;
	// box->HUD.rifle[2].rect_rifle.y = WIND_H - WIND_H/5 - 250;
	// box->HUD.rifle[3].rect_rifle.w = 200;
	// box->HUD.rifle[3].rect_rifle.h = 250;
	// box->HUD.rifle[3].rect_rifle.x = WIND_W/2 - 105;
	// box->HUD.rifle[3].rect_rifle.y = WIND_H - WIND_H/5 - 250;
	box->HUD.rifle[4].rect_rifle.w = 150;
	box->HUD.rifle[4].rect_rifle.h = 150;
	box->HUD.rifle[4].rect_rifle.x = WIND_W/2 - 75;
	box->HUD.rifle[4].rect_rifle.y = WIND_H - WIND_H/5 - 280;
	box->HUD.rifle[5].rect_rifle.w = 150;
	box->HUD.rifle[5].rect_rifle.h = 150;
	box->HUD.rifle[5].rect_rifle.x = WIND_W/2 - 75;
	box->HUD.rifle[5].rect_rifle.y = WIND_H - WIND_H/5 - 280;
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
 	ft_ammo_bar(box);
 	ft_armor_bar(box);
 	ft_frag_bar(box);
 	ft_rifle_bar(box);
}

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
 	box->HUD.fire = 0;
 	box->HUD.fr_val = 0;
 	box->HUD.hp_val = 100;
 	box->HUD.ar_val = 0;
 	box->HUD.am_val = 110;
 	box->HUD.time = 5;
 	ft_bar(box);
}