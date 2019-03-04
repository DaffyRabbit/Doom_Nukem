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

int		key_push(t_box *box)
{
	if (box->keys[SDL_SCANCODE_Q] && box->ttsky == 0)
	{
		box->sitd = 1;
		box->go.spd = 0.007;
		return (0);
	}
	else if (!(box->keys[SDL_SCANCODE_Q]) && !(box->keys[SDL_SCANCODE_LSHIFT]))
	{
		if (box->ttsky == 0)
			box->go.spd = 0.02;
		box->sitd = 0;
	}
	if (box->keys[SDL_SCANCODE_LSHIFT] && box->sitd == 0)
		box->go.spd = 0.033;
	if (box->keys[SDL_SCANCODE_SPACE] && box->ttsky == 0 &&
		box->go.lop <= 0 && box->sitd == 0)
	{
			box->ttsky = 1;
			box->ttsky2 = 1;
	}
	else if (!(box->keys[SDL_SCANCODE_SPACE]))
		box->ttsky = 0;
	return (0);
}
