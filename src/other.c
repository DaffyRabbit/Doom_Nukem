#include "gen.h"

t_tool_t	*tool_t(t_gen *gen, int bt)
{
	t_list			*tmp;
	t_tool_t	*tmpbt;

	tmp = gen->toll_code->prev;
	while (tmp)
	{
		tmpbt = tmp->content;
		if (tmpbt->tool_index == bt)
			return (tmpbt);
		tmp = tmp->next;
	}
	return (NULL);
}

void	gen_show_this_for_me(t_gen *gen, t_generator *red)
{
	i_need_tx(gen, red->surf_gen, ft_strjoin_alt("Object ID: ", ft_itoa(gen->eve_id), 0), new_sdlrect(WIN_W - 680, 25, 18, 0));
}

int		wery_i_f(t_gen *gen)
{
	return (gen->ui_ids++);
}

void	how_b_look_like(t_gen *gen, int tool)
{
	gen->generus.tool_block->background_color = tool == tool_block ?
		gen->generus.select_color : gen->generus.base_color;
}

int	ts(t_el_text *text)
{
	return (TTF_SizeUTF8(text->font, text->text, &text->weighu, &text->heighu));
}

t_uid		*get_new_uid(t_gen *gen)
{
	t_uid	*element;

	if (!(element = maloc_alt(sizeof(t_uid))))
		exit(0);
	element->id = wery_i_f(gen);
	element->uix = 0;
	element->uiy = 0;
	element->uiw = 100;
	element->uih = 100;
	return (element);
}

int		r_a_i(int r, int g, int b, int a)
{
	return ((a & 0xff) << 24 | (r & 0xff) << 16 | (g & 0xff) << 8 | (b & 0xff));
}

int		where_b(t_el_key *button, int x, int y)
{
	if (x >= button->real_x && x <= (button->real_x + button->rect.w))
		if (y >= button->real_y && y <= (button->real_y + button->rect.h))
			return (1);
	return (0);
}

void	updait_b(t_el_key *but, int x, int y)
{
	but->real_x += x;
	but->real_y += y;
}

void	last_up_tool(t_gen *gen, t_list *tmp, int x, int y)
{
	t_tool_t	*tmp_bt;

	tmp_bt = (t_tool_t *)tmp->content;
	paint_r_2(gen->generus.gen_s, new_sdlrect(x, y, 170, 70),
		tmp_bt->tool_c, 1);
	gen->tmp_color = new_rgb_mask(0, 0, 0, 255);
	i_need_tx(gen, gen->generus.gen_s,
		tmp_bt->tool_id, new_sdlrect(x + 10, y + 22, 20, 0));
	if (lcm() && where_m(gen->m_x, gen->m_y,
			new_sdlrect(gen->generus.gen_r.x
				+ x, gen->generus.gen_r.y + y, 170, 70)))
		take_tool_t(gen, tmp_bt);
}

void		repeat_tool_t(t_gen *gen, t_tool_t *type, t_strc_type *blk)
{
	gen->generus.selected_block = type;
	gen->generus.foc.bonus_param = blk->tool_t;
	something_new(gen);
}

void		take_tool_t(t_gen *gen, t_tool_t *type)
{
	gen->generus.selected_block = type;
	if (gen->generus.selected_block->tool_index != repeat_tool)
		gen->eve_id = 0;
	gen->generus.foc.bonus_param = type->tool_index;
	something_new(gen);
}

void		something_new(t_gen *gen)
{
	t_generator *e;

	e = &gen->generus;
}

void		for_one_time(t_strc_type *dest, t_strc_type *src, int free2)
{
	dest->tool_t = src->tool_t;
	if (free2)
		free(src);
}

void		reset_tt(t_strc_type *dest)
{
	dest->tool_t = wall_tool;
}

void	gen_update_surf(t_gen *gen)
{
	t_generator	*e;

	e = &gen->generus;
	if (e->selected_block)
	{
		gen->selected_block = ft_strdup(e->selected_block->tool_id);
		free(gen->generus.current_tool->text);
		gen->generus.current_tool->text = ft_strjoin_alt("Tool type : ", gen->selected_block, 0);
		tx_pre(gen, gen->generus.current_tool, 1, 0);
		if (e->selected_block->tool_index != repeat_tool)
			gen_show_this_for_me(gen, e);
	}
}

void	chek_gen_surf(t_gen *gen, t_ren_params *qr,
	SDL_MouseWheelEvent wheel, SDL_Rect rc)
{
	rc = new_sdlrect(qr->pos_x + qr->ge_s->pos.x, qr->pos_y
		+ qr->ge_s->pos.y, qr->ge_s->pos.w, qr->ge_s->pos.h);
	if (where_m(gen->m_x, gen->m_y, rc))
	{
		af_up_bucket(gen, qr->ge_s, wheel.y > 0 ? 1 : -1, 1);
	}
	rc = new_sdlrect(qr->pos_x + qr->ge_h->pos.x, qr->pos_y
		+ qr->ge_h->pos.y, qr->ge_h->pos.w, qr->ge_h->pos.h);
	if (where_m(gen->m_x, gen->m_y, rc))
	{
		af_up_bucket(gen, qr->ge_h, wheel.y > 0 ? 1 : -1, 1);
	}
}

void			end_gen_rend(t_gen *gen,
	int x, SDL_Rect r, t_ren_params *q)
{
	int y;

	y = (int)((gen->m_y - q->pos_y - q->def_y) / q->cam_scale);
	if (gen->m_x - q->pos_x - q->def_x >= 0 && gen->m_y
		- q->pos_y - q->def_y >= 0
		&& where_m(gen->m_x, gen->m_y, gen->generus.r))
	{
		gen->generus.x_focus = x;
		gen->generus.y_focus = y;
		r = new_sdlrect(q->def_x + x * q->cam_scale, q->def_y
		+ y * q->cam_scale, q->cam_scale, q->cam_scale);
		paint_r_2(gen->generus.this_el_par, r, gen->generus.selected_block ?
			gen->generus.selected_block->tool_c : 0xFFFF0000, 0);
	}
}

void	*maloc_alt(size_t size)
{
	void	*element;

	if (!(element = malloc(size)))
		return (NULL);
	ft_bzero(element, size);
	return (element);
}

void			key_inp_par(t_gen *gen)
{
	t_generator		*e;
	t_tool_t	*select;

	e = &gen->generus;
	select = e->selected_block;
	if (select && gen->generus.hand_tool == tool_block && select >= 0)
	{
		if (e->x_focus >= 0 && e->y_focus >= 0 && e->x_focus < gen->allmap->y
			&& e->y_focus < gen->allmap->x)
		{
			if (select->tool_index != repeat_tool)
				{
					gen->allmap->map[e->x_focus][e->y_focus] = e->selected_block->tool_index;
					gen->allmap->event_id[e->x_focus][e->y_focus] = gen->eve_id;
				};
			if (select->tool_index == repeat_tool)
				{
					take_tool_t(gen, tool_t(gen, gen->allmap->map[e->x_focus][e->y_focus]));
					gen->eve_id = gen->allmap->event_id[e->x_focus][e->y_focus];
				}
		}
	}
}

void			key_ch_par(t_gen *gen)
{
	t_ren_params	*q;
	int					x;
	int					y;
	SDL_Rect			r;

	q = &gen->generus.qua;
	y = 0;
	while (y < gen->allmap->y)
	{
		x = 0;
		while (x < gen->allmap->x)
		{
			r = new_sdlrect(q->def_x + x * q->cam_scale, q->def_y +
				y * q->cam_scale, q->cam_scale, q->cam_scale);
			paint_r_2(gen->generus.this_el_par, r, tool_t(gen,
					gen->allmap->map[x][y])->tool_c, 1);
			x++;
		}
		y++;
	}
	gen->generus.x_focus = -1;
	gen->generus.y_focus = -1;
	x = (int)((gen->m_x - q->pos_x - q->def_x) / q->cam_scale);
	end_gen_rend(gen, x, r, q);
}