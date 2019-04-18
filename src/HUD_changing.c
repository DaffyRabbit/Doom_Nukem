#include "wolf3d.h"

int		ft_check_value(t_box *box)
{
	box->HUD.hp_val = 100;
	return(3);

}


int		ft_heals(t_box *box)
{
	int n;

	box->HUD.num_i = 0;
	n = ft_check_value(box);
	// while(box->HUD.num_i > n)
	// {
		box->HUD.heals[box->HUD.num_i].heals = ft_check_png(box,box->HUD.numb[9]);
		box->HUD.heals[box->HUD.num_i].heals_texture = SDL_CreateTextureFromSurface(box->rend,box->HUD.heals[box->HUD.num_i].heals);
		SDL_FreeSurface(box->HUD.heals[box->HUD.num_i].heals);
		//box->HUD.num_i--;
	//}
	return(0);
}






int		ft_all_bars(t_box *box)
{
	ft_heals(box);
	return(0);
}