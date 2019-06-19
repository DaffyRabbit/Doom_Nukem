/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_changing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 22:05:19 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/17 22:05:21 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_check_hp_value(t_box *box)
{
	int n;

	n = 0;
	if (box->hud.hp_val <= 0)
		ft_dead(box);
	if (box->hud.hp_val > 100)
		box->hud.hp_val = 100;
	if (box->hud.hp_val >= 0 && box->hud.hp_val <= 100)
	{
		box->hud.heals[2].n = box->hud.hp_val % 10;
		box->hud.heals[1].n = (box->hud.hp_val / 10) % 10;
		box->hud.heals[0].n = (box->hud.hp_val / 100) % 10;
		if (box->hud.hp_val == 100)
			n = 0;
		if (box->hud.hp_val < 100)
			n = 1;
		if (box->hud.hp_val < 10)
			n = 2;
	}
	return (n);
}

int		ft_check_rad_value(t_box *box)
{
	int n;

	n = 0;
	if (box->hud.rad_val > 99)
		box->hud.rad_val = 99;
	if (box->hud.rad_val >= 0 && box->hud.rad_val <= 99)
	{
		box->hud.rad[2].n = box->hud.rad_val % 10;
		box->hud.rad[1].n = (box->hud.rad_val / 10) % 10;
		if (box->hud.rad_val < 100)
			n = 1;
		if (box->hud.rad_val < 10)
			n = 2;
	}
	return (n);
}

int		ft_rad(t_box *box, int i)
{
	int n;

	box->hud.rad[0].ticks++;
	if (box->hud.rad[0].ticks == 40)
	{
		box->hud.rad_val++;
		box->hud.rad[0].ticks = 0;
		box->hud.hp_val = box->hud.hp_val - (box->hud.rad_val /
			(3 + box->hud.hp_val * 0.1));
	}
	n = ft_check_rad_value(box);
	if (n > 2 || n < 0)
		n = 2;
	box->hud.rad_i = n;
	while (i >= n)
	{
		box->hud.rad[i].rad =
		ft_check_png(box, box->hud.numb[box->hud.rad[i].n]);
		box->hud.rad[i].rad_texture =
		SDL_CreateTextureFromSurface(box->rend, box->hud.rad[i].rad);
		SDL_FreeSurface(box->hud.rad[i].rad);
		i--;
	}
	return (0);
}

int		ft_heals(t_box *box)
{
	int n;
	int i;

	i = 2;
	n = ft_check_hp_value(box);
	if (n > 2 || n < 0)
		n = 2;
	box->hud.hp_i = n;
	while (i >= n)
	{
		box->hud.heals[i].heals =
		ft_check_png(box, box->hud.numb[box->hud.heals[i].n]);
		box->hud.heals[i].heals_texture =
		SDL_CreateTextureFromSurface(box->rend, box->hud.heals[i].heals);
		SDL_FreeSurface(box->hud.heals[i].heals);
		i--;
	}
	return (0);
}

int		ft_all_bars(t_box *box)
{
	ft_rad(box, 2);
	ft_heals(box);
	return (0);
}
