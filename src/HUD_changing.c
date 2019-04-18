#include "wolf3d.h"

int		ft_check_value(t_box *box)
{
	int n;

	n = 0;
	if (box->HUD.hp_val >= 0 && box->HUD.hp_val <= 100)
	{
		box->HUD.heals[2].n = box->HUD.hp_val%10;
		box->HUD.heals[1].n = (box->HUD.hp_val/10)%10;
		box->HUD.heals[0].n = (box->HUD.hp_val/100)%10;
		if(box->HUD.hp_val == 100)
			n = 0;
		if(box->HUD.hp_val < 100)
			n = 1;
		if(box->HUD.hp_val < 10)
			n = 2;
	}	
	return(n);
}


int		ft_heals(t_box *box)
{
	int n;
	int i;

	i = 2;
	n = ft_check_value(box);
	if (n > 2 || n < 0)
		n = 2;
	box->HUD.num_i = n;
	while(i >= n)
	{
		box->HUD.heals[i].heals = ft_check_png(box,box->HUD.numb[box->HUD.heals[i].n]);
		box->HUD.heals[i].heals_texture = SDL_CreateTextureFromSurface(box->rend,box->HUD.heals[i].heals);
		SDL_FreeSurface(box->HUD.heals[i].heals);
		i--;
	}
	return(0);
}






int		ft_all_bars(t_box *box)
{
	ft_heals(box);
	return(0);
}