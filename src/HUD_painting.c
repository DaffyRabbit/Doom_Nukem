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
		while (box->HUD.fr_i <= 2)
	{
		SDL_RenderCopy(box->rend, box->HUD.frag[box->HUD.fr_i].frag_texture, NULL, &box->HUD.frag[box->HUD.fr_i].rect_frag);
		box->HUD.fr_i++;
	}
	if (box->HUD.fire == 1)
	{
		//box->sleep_rel = SDL_GetTicks();
		//box->sleep_cur = SDL_GetTicks();
		SDL_RenderCopy(box->rend, box->HUD.rifle[0].rifle_texture, NULL, &box->HUD.rifle[0].rect_rifle);
		SDL_RenderCopy(box->rend, box->HUD.rifle[4].rifle_texture, NULL, &box->HUD.rifle[4].rect_rifle);
		SDL_RenderCopy(box->rend, box->HUD.rifle[5].rifle_texture, NULL, &box->HUD.rifle[5].rect_rifle);
		// while((box->sleep_cur - box->sleep_rel) < 100)
		// {
		// 	box->sleep_cur = SDL_GetTicks();
		// }
		// SDL_RenderCopy(box->rend, box->HUD.rifle[1].rifle_texture, NULL, &box->HUD.rifle[1].rect_rifle);
		// SDL_RenderCopy(box->rend, box->HUD.rifle[2].rifle_texture, NULL, &box->HUD.rifle[2].rect_rifle);
		// SDL_RenderCopy(box->rend, box->HUD.rifle[3].rifle_texture, NULL, &box->HUD.rifle[3].rect_rifle);
	}
	else
		SDL_RenderCopy(box->rend, box->HUD.rifle[0].rifle_texture, NULL, &box->HUD.rifle[0].rect_rifle);
}

void		ft_load_HUD_tex(t_box *box)
{
	box->HUD.rifle[0].rifle = ft_check_png(box,"txtrs/rifle.png");
	box->HUD.rifle[1].rifle = ft_check_png(box,"txtrs/reload1.png");
	box->HUD.rifle[2].rifle = ft_check_png(box,"txtrs/reload2.png");
	box->HUD.rifle[3].rifle = ft_check_png(box,"txtrs/reload3.png");
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