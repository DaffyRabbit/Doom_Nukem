/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this_generus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:52:22 by rhusak            #+#    #+#             */
/*   Updated: 2019/06/25 20:52:28 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen.h"

void	key_init(t_gen *gen, t_generator *red)
{
	paint_r_2(red->gen_s, new_sdlrect(0, 0, red->gen_r.w, red->gen_r.h),
		0xFF005582, 1);
	update_all_tools(gen);
	paint_r_2(red->gen_s, new_sdlrect(0, 0, red->gen_r.w, red->gen_r.h),
		0xFF333333, 0);
	SDL_BlitSurface(red->gen_s, NULL, gen->generus.surf_gen, &red->gen_r);
	SDL_BlitSurface(red->more_surf, NULL, gen->generus.surf_gen, &red->more_r);
}

void	this_generus_2(t_gen *gen)
{
	t_generator	*red;

	red = &gen->generus;
	paint_r_2(red->this_el_par, new_sdlrect(0, 0,
		red->r.w, red->r.h), 0xFF336699, 1);
	key_ch_par(gen);
	paint_r_2(red->this_el_par, new_sdlrect(0, 0,
		red->r.w, red->r.h), 0xFF000000, 0);
	SDL_BlitSurface(red->this_el_par, NULL, gen->generus.surf_gen, &red->r);
	if (red->selected_block)
	{
		free(gen->selected_block);
		gen->selected_block = ft_strdup(red->selected_block->tool_id);
		free(gen->generus.current_tool->text);
		gen->generus.current_tool->text = ft_strjoin("Tool type : ",
		gen->selected_block);
		tx_pre(gen, gen->generus.current_tool, 1, 0);
		if (red->selected_block->tool_index != repeat_tool &&
			red->selected_block->tool_index != startpoint_tool &&
			red->selected_block->tool_index != door_tool)
		{
			gen_show_this_for_me(gen, red);
		}
	}
	key_init(gen, red);
}

void	this_generus(t_gen *gen)
{
	t_generator	*red;
	SDL_Rect	m_pos;

	m_pos = m_trak();
	red = &gen->generus;
	SDL_SetRenderDrawColor(gen->rend, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gen->rend);
	if (where_m(m_pos.x, m_pos.y, gen->generus.r))
		gen->generus.c_focus = 1;
	else
		gen->generus.c_focus = -1;
	paint_r_2(red->surf_gen, new_sdlrect(0, 0, WIN_W, 80), 0xFF005582, 1);
	this_generus_2(gen);
	show_k_for_me(gen, red->surf_gen, red->save);
	re_text(gen, red->surf_gen, red->current_tool);
	paint_r(red->surf_gen, new_sdlrect(WIN_W - 710, 0, 3, 80),
		red->base_color, 1);
	paint_r(red->surf_gen, new_sdlrect(WIN_W - 300, 0, 3, 80),
		red->base_color, 1);
	gen->tmp_color = new_rgb_mask(218, 248, 227, 255);
}
