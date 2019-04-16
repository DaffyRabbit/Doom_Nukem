#include "wolf3d.h"

int		ft_face_start(t_box *box)
{
	box->HUD.face[box->num_face].face_texture = SDL_CreateTextureFromSurface(box->rend,box->HUD.face[box->num_face].face);
 	SDL_FreeSurface(box->HUD.face[box->num_face].face);
 	SDL_RenderClear(box->rend);
	SDL_RenderCopy(box->rend, box->HUD.face[box->num_face].face_texture, NULL, &box->HUD.face[box->num_face].rect_face);
 	if (box->num_face == 2)
	{
		box->blok = 1;
		box->num_face--;
	}
	else
	{
		if(box->num_face == 1 && box->blok == 1)
		{
			box->num_face--;
			box->blok = 0;
		}
		else
		box->num_face++; 		
	}
	return(0);
}

int		ft_face(t_box *box)
{
if(box->sleep < SDL_GetTicks() - 1.0 * 1000)
{
 ft_face_start(box);
 box->sleep = SDL_GetTicks();
}
 return(0);
}

int		ft_HUD_bar(t_box *box)
{
 box->HUD.bott_bar_texture = SDL_CreateTextureFromSurface(box->rend,box->HUD.bott_bar);
 SDL_FreeSurface(box->HUD.bott_bar);
 SDL_RenderClear(box->rend);
 SDL_RenderCopy(box->rend, box->HUD.bott_bar_texture, NULL, &box->HUD.rect_bott_bar);
 return(0);
}

int		ft_scope(t_box *box)
{
 box->HUD.scope_texture = SDL_CreateTextureFromSurface(box->rend,box->HUD.scope);
 SDL_FreeSurface(box->HUD.scope);
 SDL_RenderClear(box->rend);
 SDL_RenderCopy(box->rend, box->HUD.scope_texture, NULL, &box->HUD.rect_scope);
 return(0);
}

int		ft_HUD(t_box *box)
{
	box->HUD.bott_bar = ft_check_png(box,"txtrs/bott_bar.png");
	box->HUD.scope = ft_check_png(box,"txtrs/scope_red.png");
	box->HUD.face[0].face = ft_check_png(box,"txtrs/face_left.png"); 
	box->HUD.face[1].face = ft_check_png(box,"txtrs/face_center.png"); 
	box->HUD.face[2].face = ft_check_png(box,"txtrs/face_right.png"); 
	ft_HUD_bar(box);
	ft_scope(box);
	if(box->face_start < 3)
	{
		ft_face_start(box);
		box->face_start++;
	}
	else
		ft_face(box);
	return(0);
}