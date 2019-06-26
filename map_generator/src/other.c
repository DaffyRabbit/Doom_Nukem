/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:15:21 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/25 19:15:22 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gen.h"

t_tool_t			*tool_t(t_gen *gen, int bt)
{
	t_list		*tmp;
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

void				chek_gen_surf(t_gen *gen, t_ren_params *qr,
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

void				end_gen_rend(t_gen *gen,
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

void				key_inp_par(t_gen *gen)
{
	t_generator		*e;
	t_tool_t		*select;

	e = &gen->generus;
	select = e->selected_block;
	if (select && gen->generus.hand_tool == tool_block && select >= 0)
	{
		if (e->x_focus >= 0 && e->y_focus >= 0 && e->x_focus < gen->allmap->x
			&& e->y_focus < gen->allmap->y)
		{
			if (select->tool_index != repeat_tool)
			{
				gen->allmap->map[e->x_focus][e->y_focus] =
				e->selected_block->tool_index;
				gen->allmap->event_id[e->x_focus][e->y_focus] = gen->eve_id;
			}
			if (select->tool_index == repeat_tool)
			{
				take_tool_t(gen, tool_t(gen,
					gen->allmap->map[e->x_focus][e->y_focus]));
				gen->eve_id = gen->allmap->event_id[e->x_focus][e->y_focus];
			}
		}
	}
}

void				key_ch_par(t_gen *gen)
{
	t_ren_params	*q;
	int				x;
	int				y;
	SDL_Rect		r;

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
