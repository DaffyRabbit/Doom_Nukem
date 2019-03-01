/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:42:23 by arykov            #+#    #+#             */
/*   Updated: 2018/11/30 13:42:25 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		menu_keys(int code, t_box *box)
{
	if (code == SDLK_ESCAPE)
	{
		all_destroy(box);
		exit_this();
	}
	return (0);
}

void	for_cam(int code, t_box *box, int i)
{
	if (code == SDLK_l)
		box->ogo.tohell = i;
	else if (code == SDLK_o)
		box->ogo.insky = i;
	else if (code == SDLK_k)
		box->ogo.south = i;
	else if (code == SDLK_SEMICOLON)
		box->ogo.west = i;
}

void	for_go(int code, t_box *box, int i)
{
	if (code == SDLK_a)
		box->go.south = i;
	else if (code == SDLK_s)
		box->go.tohell = i;
	else if (code == SDLK_d)
		box->go.west = i;
	else if (code == SDLK_w)
		box->go.insky = i;
}

int		key_rele(int code, t_box *box)
{
	if (code == SDLK_ESCAPE)
	{
		exit_this();
	}
	for_go(code, box, 0);
	for_cam(code, box, 0);
	if (code == SDLK_LSHIFT && box->sitd == 0)
		box->go.spd = 0.05;
	else if (code == SDLK_SPACE)
		box->ttsky = 0;
	else if (code == SDLK_q)
		box->sitd = 0;
	else if (code == SDLK_q && box->ttsky == 0)
		box->go.spd = 0.05;
	return (0);
}

int		key_push(int code, t_box *box)
{
	for_go(code, box, 1);
	for_cam(code, box, 1);
	if (code == SDLK_LSHIFT && box->sitd == 0)
		box->go.spd = 0.1;
	else if (code == SDLK_SPACE && box->ttsky == 0 &&
				box->go.lop <= 0 && box->sitd == 0)
	{
		box->ttsky = 1;
		box->ttsky2 = 1;
	}
	else if (code == SDLK_q && box->ttsky == 0)
	{
		box->sitd = 1;
		box->go.spd = 0.025;
	}
	return (0);
}
