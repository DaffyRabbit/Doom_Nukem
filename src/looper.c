#include "gen.h"

void		show_k_for_me(t_gen *gen, SDL_Surface *surface,
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

void	this_generus_2(t_gen *gen)
{
	t_generator	*red;

	red = &gen->generus;
	paint_r_2(red->this_el_par, new_sdlrect(0, 0, red->r.w, red->r.h), 0xFF336699, 1);
	key_ch_par(gen);
	paint_r_2(red->this_el_par, new_sdlrect(0, 0, red->r.w, red->r.h), 0xFF000000, 0);
	SDL_BlitSurface(red->this_el_par, NULL, gen->generus.surf_gen, &red->r);
	if (red->selected_block)
	{
		gen->selected_block = ft_strdup(red->selected_block->tool_id);
		free(gen->generus.current_tool->text);
		gen->generus.current_tool->text = ft_strjoin("Tool type : ",
		gen->selected_block);
		tx_pre(gen, gen->generus.current_tool, 1, 0);
		if (red->selected_block->tool_index != repeat_tool && red->selected_block->tool_index != startpoint_tool && red->selected_block->tool_index != door_tool)
		{
			gen_show_this_for_me(gen, red);
		}
	}
	paint_r_2(red->gen_s, new_sdlrect(0, 0, red->gen_r.w, red->gen_r.h), 0xFF005582, 1);
	update_all_tools(gen);
	paint_r_2(red->gen_s, new_sdlrect(0, 0, red->gen_r.w, red->gen_r.h), 0xFF333333, 0);
	SDL_BlitSurface(red->gen_s, NULL, gen->generus.surf_gen, &red->gen_r);
	SDL_BlitSurface(red->more_surf, NULL, gen->generus.surf_gen, &red->more_r);
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
	paint_r(red->surf_gen, new_sdlrect(WIN_W - 710, 0, 3, 80), red->base_color, 1);
	paint_r(red->surf_gen, new_sdlrect(WIN_W - 300, 0, 3, 80), red->base_color, 1);
	gen->tmp_color = new_rgb_mask(218, 248, 227, 255);
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