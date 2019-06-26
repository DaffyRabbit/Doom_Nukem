/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:06:10 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/25 20:06:23 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gen.h"

void	show_k_for_me(t_gen *gen, SDL_Surface *surface,
										t_el_key *button)
{
	if (button->is_visible)
	{
		paint_r(surface, button->rect, button->is_disabled ?
			button->background_color_disabled : button->background_color, 1);
		if (button->text)
			re_text(gen, surface, button->text);
	}
}

void	all_s(t_gen *gen)
{
	SDL_Rect	r;
	int			new_w;
	int			new_h;

	new_w = gen->generus.anim_w * 1.15;
	new_h = gen->generus.anim_h * 1.15;
	r = new_sdlrect(WIN_W / 2 - new_w / 2, WIN_H / 2 - new_h / 2, new_w, new_h);
	SDL_SetSurfaceAlphaMod(gen->generus.surf_gen, gen->generus.anim_alpha);
	SDL_BlitScaled(gen->generus.surf_gen, NULL, gen->surface, &r);
	gen->generus.anim_w *= 1.15;
	gen->generus.anim_h *= 1.15;
	if (gen->generus.anim_alpha + 35 > 255)
		gen->generus.anim_alpha = 255;
	else
		gen->generus.anim_alpha += 20;
	if (gen->generus.anim_w >= WIN_W || gen->generus.anim_h >= WIN_H)
	{
		SDL_SetSurfaceAlphaMod(gen->generus.surf_gen, 255);
		gen->generus.separator = 1;
	}
}

void	update_all_tools(t_gen *gen)
{
	t_list			*tmp;
	int				x;
	int				y;

	gen->tmp_color = new_rgb_mask(218, 248, 227, 255);
	i_need_tx(gen, gen->generus.gen_s,
		"Tools", new_sdlrect(20, 10, 25, 0));
	tmp = gen->toll_code->prev;
	x = 10;
	y = 50;
	while (tmp)
	{
		last_up_tool(gen, tmp, x, y);
		x += 180;
		if (x + 180 >= gen->generus.gen_r.w)
		{
			x = 10;
			y += 80;
		}
		tmp = tmp->next;
	}
}

void	loop_gen(t_gen *gen)
{
	SDL_Rect	mouse;

	while (1)
	{
		gen->last_frame = SDL_GetTicks();
		mouse = m_trak();
		gen->m_x = mouse.x;
		gen->m_y = mouse.y;
		if (gen->generus.separator)
		{
			while (SDL_PollEvent(&gen->last_event))
				del_ev(gen, gen->last_event);
			this_generus(gen);
			SDL_BlitSurface(gen->generus.surf_gen, NULL, gen->surface, NULL);
		}
		else
			all_s(gen);
		SDL_UpdateWindowSurface(gen->win);
	}
}
