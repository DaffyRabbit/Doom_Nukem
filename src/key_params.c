/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:48:22 by rhusak            #+#    #+#             */
/*   Updated: 2019/06/25 20:48:31 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen.h"

void						param_keys2(t_gen *gen, SDL_Event sdl_event)
{
	if (sdl_event.key.keysym.scancode == SDL_SCANCODE_UP)
	{
		gen->eve_id_scale++;
		if (gen->eve_id_scale > 3)
			gen->eve_id_scale = 3;
	}
	if (sdl_event.key.keysym.scancode == SDL_SCANCODE_DOWN)
	{
		gen->eve_id_scale--;
		if (gen->eve_id_scale < 1)
			gen->eve_id_scale = 1;
	}
	if (sdl_event.key.keysym.scancode == SDL_SCANCODE_P)
	{
		print_map(gen, 0);
	}
}

int							params_keys(t_gen *gen, SDL_Event sdl_event)
{
	if (sdl_event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		ft_bb(gen);
	if (sdl_event.key.keysym.scancode == SDL_SCANCODE_LEFT)
	{
		gen->eve_id -= gen->eve_id_scale;
		if (gen->eve_id < 0)
			gen->eve_id = 0;
	}
	if (sdl_event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
	{
		gen->eve_id += gen->eve_id_scale;
		if (gen->generus.selected_block->tool_c != wall_tool)
		{
			if (gen->eve_id > 8)
				gen->eve_id = 8;
		}
		else
		{
			if (gen->eve_id > 7)
				gen->eve_id = 7;
		}
	}
	param_keys2(gen, sdl_event);
	return (0);
}

int							m_param_1(t_gen *gen, SDL_Event sdl_event)
{
	SDL_MouseMotionEvent	motion;
	int						m_x;
	int						m_y;

	SDL_GetMouseState(&m_x, &m_y);
	motion = sdl_event.motion;
	if (where_m(m_x, m_y, gen->generus.r) && gen->generus.third_m_click)
	{
		gen->generus.qua.def_x += motion.xrel;
		gen->generus.qua.def_y += motion.yrel;
	}
	return (1);
}

int							m_param_2(t_gen *gen, SDL_Event sdl_event)
{
	SDL_MouseButtonEvent	mouse;
	t_generator				*e;

	e = &gen->generus;
	mouse = sdl_event.button;
	if (mouse.button == SDL_BUTTON_MIDDLE)
	{
		if (mouse.state == SDL_PRESSED)
			gen->generus.third_m_click = 1;
		else
			gen->generus.third_m_click = 0;
	}
	if (mouse.button == SDL_BUTTON_LEFT)
	{
		if (e->c_focus == 1 && e->x_focus >= 0 && e->y_focus >= 0)
			key_inp_par(gen);
	}
	return (0);
}
