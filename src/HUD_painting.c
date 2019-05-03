#include "wolf3d.h"

void		paint_HUD(t_box *box)
{
	SDL_RenderCopy(box->rend, box->HUD.scope_texture, NULL, &box->HUD.rect_scope);
	SDL_RenderCopy(box->rend, box->HUD.bott_bar_texture, NULL, &box->HUD.rect_bott_bar);
	SDL_RenderCopy(box->rend, box->HUD.face[box->num_face].face_texture, NULL, &box->HUD.face[box->num_face].rect_face);
	while (box->HUD.hp_i <= 2)
	{
		SDL_RenderCopy(box->rend, box->HUD.heals[box->HUD.hp_i].heals_texture, NULL, &box->HUD.heals[box->HUD.hp_i].rect_heals);
		box->HUD.hp_i++;
	}
	while (box->HUD.ar_i <= 2)
	{
		SDL_RenderCopy(box->rend, box->HUD.armor[box->HUD.ar_i].armor_texture, NULL, &box->HUD.armor[box->HUD.ar_i].rect_armor);
		box->HUD.ar_i++;
	}
	while (box->HUD.am_i <= 2)
	{
		SDL_RenderCopy(box->rend, box->HUD.ammo[box->HUD.am_i].ammo_texture, NULL, &box->HUD.ammo[box->HUD.am_i].rect_ammo);
		box->HUD.am_i++;
	}
		while (box->HUD.fr_i <= 2)
	{
		SDL_RenderCopy(box->rend, box->HUD.frag[box->HUD.fr_i].frag_texture, NULL, &box->HUD.frag[box->HUD.fr_i].rect_frag);
		box->HUD.fr_i++;
	}
	if (box->HUD.time > 5)
		box->HUD.time = 5;
	if (box->HUD.fire == 1 && box->HUD.am_val > 0 && box->HUD.time == 5)
	{
		SDL_RenderCopy(box->rend, box->HUD.rifle[0].rifle_texture, NULL, &box->HUD.rifle[0].rect_rifle);
		SDL_RenderCopy(box->rend, box->HUD.rifle[4].rifle_texture, NULL, &box->HUD.rifle[4].rect_rifle);
		SDL_RenderCopy(box->rend, box->HUD.rifle[5].rifle_texture, NULL, &box->HUD.rifle[5].rect_rifle);
		box->HUD.am_val--;
		box->HUD.time = 0;
	}
	else
		SDL_RenderCopy(box->rend, box->HUD.rifle[0].rifle_texture, NULL, &box->HUD.rifle[0].rect_rifle);
	box->HUD.time++;
}

void		ft_load_HUD_tex(t_box *box)
{
	box->HUD.rifle[0].rifle = ft_check_png(box,"txtrs/rifle.png");
	/////////////////reload//////////////
	// box->HUD.rifle[1].rifle = ft_check_png(box,"txtrs/reload1.png");
	// box->HUD.rifle[2].rifle = ft_check_png(box,"txtrs/reload2.png");
	// box->HUD.rifle[3].rifle = ft_check_png(box,"txtrs/reload3.png");
	/////////////////reload//////////////
	box->HUD.rifle[4].rifle = ft_check_png(box,"txtrs/rifle_fire1.png");
	box->HUD.rifle[5].rifle = ft_check_png(box,"txtrs/rifle_fire2.png");
	box->HUD.bott_bar = ft_check_png(box,"txtrs/bott_bar.png");	
	box->HUD.scope = ft_check_png(box,"txtrs/scope_red.png");
	box->HUD.face[0].face = ft_check_png(box,"txtrs/face_left.png"); 
	box->HUD.face[1].face = ft_check_png(box,"txtrs/face_center.png"); 
	box->HUD.face[2].face = ft_check_png(box,"txtrs/face_right.png"); 

}

void				ft_shooting(int code, t_box *box)
{

	if (code == SDL_BUTTON_LEFT && box->HUD.usless != 1)
		box->HUD.fire = 1;
	box->HUD.usless = 0;
}