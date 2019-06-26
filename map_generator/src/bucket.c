/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:45:09 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/25 19:45:20 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gen.h"

t_w_strc		*new_bucket(t_gen *gen, SDL_Rect rc, SDL_Rect mmvs)
{
	t_w_strc	*jg;
	char		*s;

	if (!(jg = maloc_alt(sizeof(t_w_strc))))
		ft_bb(gen);
	jg->pn = get_new_uid(gen);
	jg->pos = rc;
	jg->min = mmvs.x;
	jg->max = mmvs.y;
	jg->value = mmvs.w;
	jg->step = mmvs.h;
	jg->background = new_rgb_mask(190, 190, 190, 255);
	jg->border = gen->generus.base_color;
	jg->color = gen->generus.select_color;
	jg->unit = "%";
	s = ft_strjoin_alt(ft_itoa(jg->value), jg->unit, 1);
	if ((jg->txt = add_tx(gen, s, "ttf/gener_font.ttf", 20)))
	{
		jg->txt->text_color = new_rgb_mask(0, 0, 0, 255);
		jg->txt->pn->uix = jg->pos.x + jg->pos.w / 2 - jg->txt->weighu / 2;
		jg->txt->pn->uiy = jg->pos.y + jg->pos.h / 2 - jg->txt->heighu / 2;
		tx_pre(gen, jg->txt, 1, 0);
	}
	free(s);
	return (jg);
}

void			up_bucket(t_gen *gen, t_w_strc *jg)
{
	if (jg->txt)
	{
		free(jg->txt->text);
		jg->txt->text = ft_strjoin_alt(ft_itoa(jg->value), jg->unit, 1);
		tx_pre(gen, jg->txt, 1, 0);
		jg->txt->pn->uix = jg->pos.x + jg->pos.w / 2 - jg->txt->weighu / 2;
		jg->txt->pn->uiy = jg->pos.y + jg->pos.h / 2 - jg->txt->heighu / 2;
		tx_pre(gen, jg->txt, 1, 0);
	}
}

void			af_up_bucket(t_gen *gen, t_w_strc *jg, int change,
	int prepare)
{
	com_bucket(gen, jg, jg->value + change * jg->step, prepare);
}

void			com_bucket(t_gen *gen, t_w_strc *jg, int value, int prepare)
{
	jg->value = value;
	if (jg->value > jg->max)
		jg->value = jg->max;
	if (jg->value < jg->min)
		jg->value = jg->min;
	if (prepare)
		up_bucket(gen, jg);
}
