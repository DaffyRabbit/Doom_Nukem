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

int		hooks(t_box *box)
{
	if (box->keys[SDL_SCANCODE_V] && box->light_power < 2.0)
			box->light_power += 0.04;
	else if (box->keys[SDL_SCANCODE_C]  && box->light_power >= 0.4)
			box->light_power -= 0.04;
	if (box->keys[SDL_SCANCODE_P] && box->mirror_effect == 0)
		box->no_shadow = (box->no_shadow == 0) ? 1 : 0;
	if (box->keys[SDL_SCANCODE_M] && box->no_shadow == 0 && box->sky == 0)
		box->mirror_effect = (box->mirror_effect == 1) ? 0 : 1;
	if (box->keys[SDL_SCANCODE_RETURN] && box->mirror_effect == 0)
		box->sky = (box->sky == 1) ? 0 : 1;
	if (box->keys[SDL_SCANCODE_F] && box->go.lop == 0)
		box->fly_mode = (box->fly_mode == 1) ? 0 : 1;
	return (0);
}

void	space_push(t_box *box)
{
	if (box->keys[SDL_SCANCODE_Q] && box->go.lop > 0)
	{
		box->go.lop -= 0.008;
		if (box->go.lop < 0)
			box->go.lop = 0;
	}
	if (box->keys[SDL_SCANCODE_SPACE] &&
		box->go.lop < 0.85)
	{
			box->go.lop += 0.008;
	}
	printf("lop = %lf\n", box->go.lop);
}

int		key_push(t_box *box)
{
	if (box->fly_mode == 0)
	{
		if (box->keys[SDL_SCANCODE_Q] && box->ttsky == 0)
		{
			box->sitd = 1;
			box->go.spd = 0.035;
			return (0);
		}
		else if (!(box->keys[SDL_SCANCODE_Q]) && !(box->keys[SDL_SCANCODE_LSHIFT]))
		{
			if (box->ttsky == 0)
				box->go.spd = 0.1;
			box->sitd = 0;
		}
		if (box->keys[SDL_SCANCODE_LSHIFT] && box->sitd == 0)
			box->go.spd = 0.15;
		if (box->keys[SDL_SCANCODE_SPACE] && box->ttsky == 0 &&
			box->go.lop <= 0 && box->sitd == 0)
		{
				box->ttsky = 1;
				box->ttsky2 = 1;
		}
		else if (!(box->keys[SDL_SCANCODE_SPACE]))
			box->ttsky = 0;
	}
	else
		space_push(box);
	return (0);
}
