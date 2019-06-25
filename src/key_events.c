#include "gen.h"

void	some_usful_ft(t_gen *gen, t_el_key *b, SDL_MouseButtonEvent ev)
{
	(void)b;
	if (ev.button == SDL_BUTTON_LEFT)
	{
		take_new_tool(gen, tool_block);
	}
}

void	add_to_surf(t_gen *gen, SDL_Event event, SDL_MouseButtonEvent ms)
{
	t_ren_params		*qr;
	SDL_Rect				rc;

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

int		scan_m_surf(t_gen *gen, SDL_Event event)
{
	SDL_MouseButtonEvent	ms;

	ms = event.button;
	add_to_surf(gen, event, ms);
	return (1);
}

int		scan_mb_surf(t_gen *gen, SDL_Event event)
{
	SDL_MouseButtonEvent	ms;
	t_ren_params		*qr;
	SDL_Rect				rc;

	ms = event.button;
	qr = &gen->generus.more_qua;
	if (ms.button == SDL_BUTTON_LEFT && gen->generus.selected_block)
	{
		rc = new_sdlrect(qr->pos_x + qr->param_3->pos.x, qr->pos_y
		+ qr->param_3->pos.y, qr->param_3->pos.w, qr->param_3->pos.h);
		if (where_m(gen->m_x, gen->m_y, rc))
		{
			qr->param_3->checked = !qr->param_3->checked;
		}
	}
	return (1);
}

int		scan_mw_surf(t_gen *gen, SDL_Event event)
{
	SDL_MouseWheelEvent	wheel;
	t_ren_params	*qr;
	SDL_Rect			rc;

	wheel = event.wheel;
	qr = &gen->generus.more_qua;
	rc = new_sdlrect(qr->pos_x + qr->h_s->pos.x, qr->pos_y + qr->h_s->pos.y, qr->h_s->pos.w, qr->h_s->pos.h);
	if (where_m(gen->m_x, gen->m_y, rc))
	{
		af_up_bucket(gen, qr->h_s, wheel.y > 0 ? 1 : -1, 1);
	}
	rc = new_sdlrect(qr->pos_x + qr->ge_s->pos.x, qr->pos_y + qr->ge_s->pos.y, qr->ge_s->pos.w, qr->ge_s->pos.h);
	if (where_m(gen->m_x, gen->m_y, rc))
	{
		af_up_bucket(gen, qr->ge_s, wheel.y > 0 ? 1 : -1, 1);
	}
	rc = new_sdlrect(qr->pos_x + qr->ge_h->pos.x, qr->pos_y + qr->ge_h->pos.y, qr->ge_h->pos.w, qr->ge_h->pos.h);
	if (where_m(gen->m_x, gen->m_y, rc))
	{
		af_up_bucket(gen, qr->ge_h, wheel.y > 0 ? 1 : -1, 1);
	}
	return (1);
}

int		push_keys(t_gen *gen, SDL_Event sdl_event)
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

int		m_param_1(t_gen *gen, SDL_Event sdl_event)
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

int		m_param_2(t_gen *gen, SDL_Event sdl_event)
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

int		gen_scale_map(t_gen *gen, SDL_Event sdl_event)
{
	SDL_MouseWheelEvent	wheel;

	wheel = sdl_event.wheel;
	if (where_m(gen->m_x, gen->m_y, gen->generus.r))
		gen->generus.qua.cam_scale += wheel.y > 0 ? 1 : -1;
	if (gen->generus.qua.cam_scale <= 0)
		gen->generus.qua.cam_scale = 1;
	return (1);
}

int		this_is_end(t_gen *gen, SDL_Event sdl_event)
{
	(void)sdl_event;
	ft_bb(gen);
	return (0);
}

int		params_keys(t_gen *gen, SDL_Event sdl_event)
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
		if(gen->generus.selected_block->tool_c != wall_tool)
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
		print_map(gen);
	}
	return (0);
}