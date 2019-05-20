#include "wolf3d.h"

int		ft_face_start(t_box *box)
{
	box->HUD.face[box->num_face].face_texture = SDL_CreateTextureFromSurface(box->rend,box->HUD.face[box->num_face].face);
 	//SDL_FreeSurface(box->HUD.face[box->num_face].face);
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
if(box->sleep < SDL_GetTicks() - 1.0 * 900)
{
 ft_face_start(box);
 box->sleep = SDL_GetTicks();
}
 return(0);
}

int		ft_HUD_bar(t_box *box)
{
 box->HUD.bar.bott_bar_texture = SDL_CreateTextureFromSurface(box->rend,box->HUD.bar.bott_bar);
 box->HUD.bar.rad_bar_texture = SDL_CreateTextureFromSurface(box->rend,box->HUD.bar.rad_bar);
 //SDL_FreeSurface(box->HUD.bott_bar);
 return(0);
}

int		ft_weapon(t_box *box)
{
	int i;

	i = 0;
	while(i < 6)
	{
 		box->HUD.weapon[i].weapon_texture = SDL_CreateTextureFromSurface(box->rend,box->HUD.weapon[i].weapon);
 		//SDL_FreeSurface(box->HUD.rifle[i].rifle);
 		i++;
	} 
 return(0);
}

int		ft_HUD(t_box *box)
{
	ft_HUD_bar(box);
	ft_weapon(box);
	if(box->HUD.face[0].face_start < 3)
	{
		ft_face_start(box);
		box->HUD.face[0].face_start++;
	}
	else
		ft_face(box);
		ft_all_bars(box);
	return(0);
}