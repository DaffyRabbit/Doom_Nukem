/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:28:37 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/19 21:28:38 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			map_color2(t_box *box, t_arg *arg)
{
	if (arg->mnb == 4)
	{
		box->this_txtr = box->menu_txtrs[6];
		apply_texture(555, 538, box);
	}
	if (arg->mnb == 5)
	{
		box->this_txtr = box->menu_txtrs[7];
		apply_texture(683, 619, box);
	}
	show_map_name(box, arg, 1);
	ifc_map_name(box, arg);
	ifp_map_name(box, arg);
	ifcnp_map_name(box, arg);
	SDL_RenderPresent(box->rend);
}

void			map_color(t_box *box, t_arg *arg)
{
	box->this_txtr = box->menu_txtrs[0];
	apply_texture(0, 0, box);
	if (arg->mnb != 1)
		box->this_txtr = box->menu_txtrs[1];
	else
		box->this_txtr = box->menu_txtrs[2];
	apply_texture(945, 630, box);
	if (arg->mnb != 2)
		box->this_txtr = box->menu_txtrs[3];
	else
		box->this_txtr = box->menu_txtrs[4];
	apply_texture(1095, 630, box);
	if (arg->mnb == 3)
	{
		box->this_txtr = box->menu_txtrs[5];
		apply_texture(519, 468, box);
	}
	map_color2(box, arg);
}

void	choose_map2(t_box *box, t_arg *arg, int f)
{
	if (box->mousey > 462 && box->mousey < 510)
	{
		if (f == 1)
			arg->z = 4;
		arg->c = 4;
	}
	else if (box->mousey > 517 && box->mousey < 565)
	{
		if (f == 1)
			arg->z = 5;
		arg->c = 5;
	}
	else if (box->mousey > 572 && box->mousey < 620)
	{
		if (f == 1)
			arg->z = 6;
		arg->c = 6;
	}
}

void	chose_map(t_box *box, t_arg *arg, int f)
{
	if (box->mousex > 935 && box->mousex < 1244)
	{
		if (box->mousey > 297 && box->mousey < 345)
		{
			if (f == 1)
				arg->z = 1;
			arg->c = 1;
		}
		else if (box->mousey > 352 && box->mousey < 400)
		{
			if (f == 1)
				arg->z = 2;
			arg->c = 2;
		}
		else if (box->mousey > 407 && box->mousey < 455)
		{
			if (f == 1)
				arg->z = 3;
			arg->c = 3;
		}
		else
			choose_map2(box, arg, f);
	}
	else
		arg->c = -1;
}
