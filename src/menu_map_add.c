/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_map_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:06:01 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/19 14:06:02 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doomnukem.h"

void				ifc_map_name(t_box *box, t_arg *arg)
{
	int				ch;
	int				y;
	SDL_Texture		*pic;

	ch = 1;
	y = 304;
	while ((ch + box->map_list.c_list - 1) <= box->map_list.max_maps && ch <= 6)
	{
		if (arg->z == ch && arg->c != ch)
		{
			pic = render_text_red(box->map_list.map_name[ch +
				box->map_list.c_list - 1], "ttf/mainfont.ttf", 35, box->rend);
			apply_menu_surface(944, y, pic, box->rend);
			y += 54;
			box->start = ch + box->map_list.c_list - 1;
			ch++;
		}
		else
		{
			y += 54;
			ch++;
		}
	}
}

void				ifp_map_name(t_box *box, t_arg *arg)
{
	int				ch;
	int				y;
	SDL_Texture		*pic;

	ch = 1;
	y = 304;
	while ((ch + box->map_list.c_list - 1) <= box->map_list.max_maps && ch <= 6)
	{
		if (arg->z != ch && arg->c == ch)
		{
			pic = render_text_purp(box->map_list.map_name[ch +
				box->map_list.c_list - 1], "ttf/mainfont.ttf", 35, box->rend);
			apply_menu_surface(944, y, pic, box->rend);
			y += 54;
			ch++;
		}
		else
		{
			y += 54;
			ch++;
		}
	}
}

void				ifcnp_map_name(t_box *box, t_arg *arg)
{
	int				ch;
	int				y;
	SDL_Texture		*pic;

	ch = 1;
	y = 304;
	while ((ch + box->map_list.c_list - 1) <= box->map_list.max_maps && ch <= 6)
	{
		if (arg->z == ch && arg->c == ch)
		{
			pic = render_text_red(box->map_list.map_name[ch +
				box->map_list.c_list - 1], "ttf/mainfont.ttf", 35, box->rend);
			apply_menu_surface(944, y, pic, box->rend);
			y += 54;
			box->start = ch + box->map_list.c_list - 1;
			ch++;
		}
		else
		{
			y += 54;
			ch++;
		}
	}
}

void				if_b_or_n(t_box *box, t_arg *arg)
{
	if ((box->mousex > 945 && box->mousex < 1075) &&
		(box->mousey > 640 && box->mousey < 680))
	{
		if (box->map_list.c_list > 0)
		{
			box->map_list.c_list -= 6;
			arg->z = -1;
			arg->c = -1;
		}
	}
	else if ((box->mousex > 1095 && box->mousex < 1230) &&
		(box->mousey > 640 && box->mousey < 680))
	{
		if (box->map_list.l_f == 0)
		{
			box->map_list.c_list += 6;
			arg->z = -1;
			arg->c = -1;
		}
	}
}
