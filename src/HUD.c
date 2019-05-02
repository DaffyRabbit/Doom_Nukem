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
if(box->sleep < SDL_GetTicks() - 1.0 * 1000)
{
 ft_face_start(box);
//////////////////////////////////////////Chenger
if (box->HUD.hp_val > 0)
box->HUD.hp_val--;
//if (box->HUD.fr_val < 99)
box->HUD.fr_val+=10;
if ( box->HUD.hp_val < 50 && box->HUD.hp_val > 0)
box->HUD.ar_val+=100/box->HUD.hp_val;
//////////////////////////////////////////Chenger
 box->sleep = SDL_GetTicks();
}
 return(0);
}

int		ft_HUD_bar(t_box *box)
{
 box->HUD.bott_bar_texture = SDL_CreateTextureFromSurface(box->rend,box->HUD.bott_bar);
 //SDL_FreeSurface(box->HUD.bott_bar);
 return(0);
}

int		ft_scope(t_box *box)
{
 box->HUD.scope_texture = SDL_CreateTextureFromSurface(box->rend,box->HUD.scope);
 //SDL_FreeSurface(box->HUD.scope); 
 return(0);
}

int		ft_rifle(t_box *box)
{
	int i;

	i = 0;
	while(i < 7)
	{
 		box->HUD.rifle[i].rifle_texture = SDL_CreateTextureFromSurface(box->rend,box->HUD.rifle[i].rifle);
 		//SDL_FreeSurface(box->HUD.rifle[i].rifle);
 		i++;
	} 
 return(0);
}

int		ft_HUD(t_box *box)
{
	ft_HUD_bar(box);
	//ft_scope(box);
	ft_rifle(box);
	if(box->face_start < 3)
	{
		ft_face_start(box);
		box->face_start++;
	}
	else
		ft_face(box);
		ft_all_bars(box);
	return(0);
}