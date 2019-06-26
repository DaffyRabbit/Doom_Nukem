/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:51:48 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/25 19:51:49 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gen.h"

void	editor_win_param(t_gen *gen)
{
	gen->generus.x_gen = 5;
	gen->generus.y_gen = 95;
	gen->generus.w_gen = WIN_W - 10;
	gen->generus.h_gen = WIN_H - 95 - 165;
	gen->generus.cuter_s = 15;
	gen->generus.w_spec = gen->generus.w_gen
	/ 2 - gen->generus.cuter_s / 2;
	gen->generus.h_spec = gen->generus.h_gen
	/ 2 - gen->generus.cuter_s / 2;
}

void	init_all(t_gen *gen)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		ft_bb(gen);
	gen->win = SDL_CreateWindow("Generator", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, 0);
	if (gen->win == NULL)
		ft_bb(gen);
	gen->rend = SDL_CreateRenderer(gen->win, -1, SDL_RENDERER_SOFTWARE);
	if (gen->rend == NULL)
		ft_bb(gen);
}

void	load_some_code(t_gen *gen)
{
	gen->toll_code = lbox_new();
	lbox_add(gen->toll_code, new_tool_t(gen, "Copy Settings", 0xFF47593c,
		repeat_tool));
	lbox_add(gen->toll_code, new_tool_t(gen, "Event", 0xFFff9005, event_tool));
	lbox_add(gen->toll_code, new_tool_t(gen, "Air", 0xFFe5e5e5, air_tool));
	lbox_add(gen->toll_code, new_tool_t(gen, "Wall", 0xFF4c4c4c, wall_tool));
	lbox_add(gen->toll_code, new_tool_t(gen, "Spawn Point", 0xFFa31010,
		startpoint_tool));
	lbox_add(gen->toll_code, new_tool_t(gen, "Door", 0xFF92816d, door_tool));
}

void	check_ev(t_gen *gen, Uint32 type,
	int (*handler)(t_gen *gen, SDL_Event ev))
{
	t_registered_event	*event;

	if ((event = maloc_alt(sizeof(t_registered_event))) == NULL)
		ft_bb(gen);
	event->type = type;
	event->handler = handler;
	event->gamemode = gen->game_mode;
	lbox_add(gen->events, event);
}

void	load_ev(t_gen *gen)
{
	check_ev(gen, SDL_QUIT, this_is_end);
	check_ev(gen, SDL_KEYUP, params_keys);
	check_ev(gen, SDL_MOUSEBUTTONUP, push_keys);
	check_ev(gen, SDL_MOUSEWHEEL, gen_scale_map);
	check_ev(gen, SDL_MOUSEWHEEL, scan_mw_surf);
	check_ev(gen, SDL_MOUSEBUTTONDOWN, m_param_2);
	check_ev(gen, SDL_MOUSEBUTTONUP, m_param_2);
	check_ev(gen, SDL_MOUSEBUTTONUP, scan_mb_surf);
	check_ev(gen, SDL_MOUSEBUTTONUP, scan_m_surf);
	check_ev(gen, SDL_MOUSEMOTION, m_param_1);
}
