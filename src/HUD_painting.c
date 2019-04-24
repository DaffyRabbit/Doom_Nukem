#include "wolf3d.h"

int			paint_HUD(t_box *box)
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
	return(0);
}