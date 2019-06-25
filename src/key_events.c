/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:02:06 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/25 20:02:07 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen.h"

void					some_usful_ft(t_gen *gen, t_el_key *b,
	SDL_MouseButtonEvent ev)
{
	(void)b;
	if (ev.button == SDL_BUTTON_LEFT)
	{
		take_new_tool(gen, tool_block);
	}
}

void					add_to_surf(t_gen *gen, SDL_Event event,
	SDL_MouseButtonEvent ms)
{
	t_ren_params		*qr;
	SDL_Rect			rc;

	qr = &gen->generus.more_qua;
	(void)event;
	if (ms.button == SDL_BUTTON_LEFT)
	{
		rc = new_sdlrect(qr->pos_x + qr->param1->pos.x, qr->pos_y
			+ qr->param1->pos.y, qr->param1->pos.w,
			qr->param1->pos.h);
		if (where_m(gen->m_x, gen->m_y, rc))
		{
			qr->param1->checked = !qr->param1->checked;
			gen->generus.foc_s.bonus_col = qr->param1->checked;
		}
		rc = new_sdlrect(qr->pos_x + qr->param2->pos.x, qr->pos_y
			+ qr->param2->pos.y, qr->param2->pos.w,
			qr->param2->pos.h);
		if (where_m(gen->m_x, gen->m_y, rc))
		{
			qr->param2->checked = !qr->param2->checked;
			gen->generus.foc_s.bonus_ob = qr->param2->checked;
		}
	}
}

int							push_keys(t_gen *gen, SDL_Event sdl_event)
{
	t_list					*tmp;
	t_el_key				*tmp_button;
	SDL_MouseButtonEvent	event;

	if (sdl_event.type != SDL_MOUSEBUTTONUP)
		return (0);
	event = sdl_event.button;
	tmp = gen->buttons->prev;
	while (tmp)
	{
		tmp_button = (t_el_key *)tmp->content;
		if (tmp_button->is_visible && !tmp_button->is_disabled)
			if (where_b(tmp_button, event.x, event.y))
			{
				tmp_button->pn_callback(gen, tmp_button, event);
				return (1);
			}
		tmp = tmp->next;
	}
	return (1);
}

int							gen_scale_map(t_gen *gen, SDL_Event sdl_event)
{
	SDL_MouseWheelEvent		wheel;

	wheel = sdl_event.wheel;
	if (where_m(gen->m_x, gen->m_y, gen->generus.r))
		gen->generus.qua.cam_scale += wheel.y > 0 ? 1 : -1;
	if (gen->generus.qua.cam_scale <= 0)
		gen->generus.qua.cam_scale = 1;
	return (1);
}

int							this_is_end(t_gen *gen, SDL_Event sdl_event)
{
	(void)sdl_event;
	ft_bb(gen);
	return (0);
}


