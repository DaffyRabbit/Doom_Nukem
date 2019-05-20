#include "wolf3d.h"

void		paint_HUD(t_box *box)
{
	SDL_RenderCopy(box->rend, box->HUD.bar.bott_bar_texture, NULL, &box->HUD.bar.rect_bott_bar);
	SDL_RenderCopy(box->rend, box->HUD.bar.rad_bar_texture, NULL, &box->HUD.bar.rect_rad_bar);
	SDL_RenderCopy(box->rend, box->HUD.face[box->num_face].face_texture, NULL, &box->HUD.face[box->num_face].rect_face);
	while (box->HUD.hp_i <= 2)
	{
		SDL_RenderCopy(box->rend, box->HUD.heals[box->HUD.hp_i].heals_texture, NULL, &box->HUD.heals[box->HUD.hp_i].rect_heals);
		box->HUD.hp_i++;
	}
	while (box->HUD.rad_i <= 2)
	{
		SDL_RenderCopy(box->rend, box->HUD.rad[box->HUD.rad_i].rad_texture, NULL, &box->HUD.rad[box->HUD.rad_i].rect_rad);
		box->HUD.rad_i++;
	}
	if (box->HUD.time > 100)
		box->HUD.time = 100;
	if (box->HUD.w_start == 0)
	{
		if(box->HUD.time > 0 && box->HUD.time < 15)
			SDL_RenderCopy(box->rend, box->HUD.weapon[0].weapon_texture, NULL, &box->HUD.weapon[0].rect_weapon);
		if(box->HUD.time > 15 && box->HUD.time < 30)
				SDL_RenderCopy(box->rend, box->HUD.weapon[1].weapon_texture, NULL, &box->HUD.weapon[0].rect_weapon);
		if(box->HUD.time > 30 && box->HUD.time < 45)
			SDL_RenderCopy(box->rend, box->HUD.weapon[2].weapon_texture, NULL, &box->HUD.weapon[0].rect_weapon);
		if (box->HUD.time > 45)
		{
			box->HUD.w_start = 1;
			box->HUD.time = 0;			
		}
	}
	else
	{
		if (box->HUD.fire == 1)
		{
			if(box->HUD.w_time >= 0 && box->HUD.w_time <= 10)
				SDL_RenderCopy(box->rend, box->HUD.weapon[4].weapon_texture, NULL, &box->HUD.weapon[0].rect_weapon);
			if(box->HUD.w_time >= 10 && box->HUD.w_time <= 20)
				SDL_RenderCopy(box->rend, box->HUD.weapon[5].weapon_texture, NULL, &box->HUD.weapon[0].rect_weapon);
			if(box->HUD.w_time == 20)
			{
				box->HUD.w_time = 0;
				box->HUD.fire = 0;
			}
			box->HUD.w_time++;
		}
		else
	 		SDL_RenderCopy(box->rend, box->HUD.weapon[3].weapon_texture, NULL, &box->HUD.weapon[0].rect_weapon);
		if(box->HUD.time > 30)
				 box->HUD.time = 0;
	}
	box->HUD.time++;
}

void		ft_load_HUD_tex(t_box *box)
{
	box->HUD.weapon[0].weapon = ft_check_png(box,"txtrs/weapon/w_start1.png");
	box->HUD.weapon[1].weapon = ft_check_png(box,"txtrs/weapon/w_start2.png");
	box->HUD.weapon[2].weapon = ft_check_png(box,"txtrs/weapon/w_start3.png");
	box->HUD.weapon[3].weapon = ft_check_png(box,"txtrs/weapon/w_wait.png");
	box->HUD.weapon[4].weapon = ft_check_png(box,"txtrs/weapon/w_fight1.png");
	box->HUD.weapon[5].weapon = ft_check_png(box,"txtrs/weapon/w_fight2.png");
	box->HUD.bar.bott_bar = ft_check_png(box,"txtrs/bott_bar.png");
	box->HUD.bar.rad_bar = ft_check_png(box,"txtrs/radiation.png");
	box->HUD.face[0].face = ft_check_png(box,"txtrs/face_left.png"); 
	box->HUD.face[1].face = ft_check_png(box,"txtrs/face_center.png"); 
	box->HUD.face[2].face = ft_check_png(box,"txtrs/face_right.png"); 

}

void				ft_shooting(int code, t_box *box)
{
	if (code == SDL_BUTTON_LEFT && box->HUD.weapon[0].usless == 1)
		box->HUD.fire = 1;
	box->HUD.weapon[0].usless = 1;
}