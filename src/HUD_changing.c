#include "wolf3d.h"

int		ft_check_hp_value(t_box *box)
{
	int n;

	n = 0;
	if (box->HUD.hp_val > 100)
		box->HUD.hp_val = 100;
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

int		ft_check_ar_value(t_box *box)
{
	int n;

	n = 0;
	if (box->HUD.ar_val > 999)
		box->HUD.ar_val = 999;
	if (box->HUD.ar_val >= 0 && box->HUD.ar_val <= 999)
	{
		box->HUD.armor[2].n = box->HUD.ar_val%10;
		box->HUD.armor[1].n = (box->HUD.ar_val/10)%10;
		box->HUD.armor[0].n = (box->HUD.ar_val/100)%10;
		if(box->HUD.ar_val == 100)
			n = 0;
		if(box->HUD.ar_val < 100)
			n = 1;
		if(box->HUD.ar_val < 10)
			n = 2;
	}	
	return(n);
}

int		ft_check_fr_value(t_box *box)
{
	int n;

	n = 0;
	if (box->HUD.fr_val > 99)
		box->HUD.fr_val = 99;
	if (box->HUD.fr_val >= 0 && box->HUD.fr_val <= 99)
	{
		box->HUD.frag[2].n = box->HUD.fr_val%10;
		box->HUD.frag[1].n = (box->HUD.fr_val/10)%10;
		if(box->HUD.fr_val < 100)
			n = 1;
		if(box->HUD.fr_val < 10)
			n = 2;
	}	
	return(n);
}

int		ft_frag(t_box *box)
{
	int n;
	int i;

	i = 2;
	n = ft_check_fr_value(box);
	if (n > 2 || n < 0)
		n = 2;
	box->HUD.fr_i = n;
	while(i >= n)
	{
		box->HUD.frag[i].frag = ft_check_png(box,box->HUD.numb[box->HUD.frag[i].n]);
		box->HUD.frag[i].frag_texture = SDL_CreateTextureFromSurface(box->rend,box->HUD.frag[i].frag);
		//SDL_FreeSurface(box->HUD.frag[i].frag);
		i--;
	}
	return(0);
}

int		ft_heals(t_box *box)
{
	int n;
	int i;

	i = 2;
	n = ft_check_hp_value(box);
	if (n > 2 || n < 0)
		n = 2;
	box->HUD.hp_i = n;
	while(i >= n)
	{
		box->HUD.heals[i].heals = ft_check_png(box,box->HUD.numb[box->HUD.heals[i].n]);
		box->HUD.heals[i].heals_texture = SDL_CreateTextureFromSurface(box->rend,box->HUD.heals[i].heals);
		//SDL_FreeSurface(box->HUD.heals[i].heals);
		i--;
	}
	return(0);
}

int		ft_armor(t_box *box)
{
	int n;
	int i;

	i = 2;
	n = ft_check_ar_value(box);
	if (n > 2 || n < 0)
		n = 2;
	box->HUD.ar_i = n;
	while(i >= n)
	{
		box->HUD.armor[i].armor = ft_check_png(box,box->HUD.numb[box->HUD.armor[i].n]);
		box->HUD.armor[i].armor_texture = SDL_CreateTextureFromSurface(box->rend,box->HUD.armor[i].armor);
		//SDL_FreeSurface(box->HUD.armor[i].armor);
		i--;
	}
	return(0);
}

int		ft_all_bars(t_box *box)
{
	ft_heals(box);
	// ft_ammo(box);
	ft_frag(box);
	ft_armor(box);
	return(0);
}