/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:47:18 by rhusak            #+#    #+#             */
/*   Updated: 2019/06/25 20:47:29 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen.h"

int							scan_m_surf(t_gen *gen, SDL_Event event)
{
	SDL_MouseButtonEvent	ms;

	ms = event.button;
	add_to_surf(gen, event, ms);
	return (1);
}

int							scan_mb_surf(t_gen *gen, SDL_Event event)
{
	SDL_MouseButtonEvent	ms;
	t_ren_params			*qr;
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

int							scan_mw_surf(t_gen *gen, SDL_Event event)
{
	SDL_MouseWheelEvent		wheel;
	t_ren_params			*qr;
	SDL_Rect				rc;

	wheel = event.wheel;
	qr = &gen->generus.more_qua;
	rc = new_sdlrect(qr->pos_x + qr->h_s->pos.x, qr->pos_y + qr->h_s->pos.y,
		qr->h_s->pos.w, qr->h_s->pos.h);
	if (where_m(gen->m_x, gen->m_y, rc))
	{
		af_up_bucket(gen, qr->h_s, wheel.y > 0 ? 1 : -1, 1);
	}
	rc = new_sdlrect(qr->pos_x + qr->ge_s->pos.x, qr->pos_y + qr->ge_s->pos.y,
		qr->ge_s->pos.w, qr->ge_s->pos.h);
	if (where_m(gen->m_x, gen->m_y, rc))
	{
		af_up_bucket(gen, qr->ge_s, wheel.y > 0 ? 1 : -1, 1);
	}
	rc = new_sdlrect(qr->pos_x + qr->ge_h->pos.x, qr->pos_y + qr->ge_h->pos.y,
		qr->ge_h->pos.w, qr->ge_h->pos.h);
	if (where_m(gen->m_x, gen->m_y, rc))
	{
		af_up_bucket(gen, qr->ge_h, wheel.y > 0 ? 1 : -1, 1);
	}
	return (1);
}