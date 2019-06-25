/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:47:22 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/25 19:47:24 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen.h"

t_el_key		*add_new_b(t_gen *gen, char *string, SDL_Rect rect,
	void (*pn_callback)(t_gen *gen, t_el_key *b, SDL_MouseButtonEvent event))
{
	t_el_key	*but;

	if (!(but = maloc_alt(sizeof(t_el_key))))
		ft_bb(gen);
	but->pn = get_new_uid(gen);
	if ((but->text = add_tx(gen, string, "ttf/mainfont.ttf", 20)))
		but->text->text_color = new_rgb_mask(0, 0, 0, 255);
	but->background_color = new_rgb_mask(57, 114, 206, 255);
	but->background_color_disabled = new_rgb_mask(96, 136, 201, 255);
	but->pn_callback = pn_callback;
	but->is_visible = 1;
	but->is_disabled = 0;
	but->rect = rect;
	but->real_x = rect.x;
	but->real_y = rect.y;
	lbox_add(gen->buttons, but);
	return (but);
}

void			key_parameters(t_gen *gen, t_el_key *button)
{
	if (button->text)
	{
		button->text->pn->uix =
			button->rect.x + button->rect.w / 2 - button->text->weighu / 2;
		button->text->pn->uiy =
			button->rect.y + button->rect.h / 2 - button->text->heighu / 2;
		tx_pre(gen, button->text, 1, 0);
	}
}

t_echb			*gen_help(t_gen *gen, SDL_Rect pos, int checked)
{
	t_echb		*ck;

	(void)checked;
	if (!(ck = maloc_alt(sizeof(t_echb))))
		ft_bb(gen);
	ck->pos = pos;
	ck->falsc = new_rgb_mask(50, 50, 50, 255);
	ck->background = new_rgb_mask(190, 190, 190, 255);
	ck->border = gen->generus.base_color;
	ck->color = gen->generus.select_color;
	ck->checked = 0;
	ck->disabled = 0;
	return (ck);
}

void			ren_gen_help(t_gen *gen, SDL_Surface *s, t_echb *ck)
{
	(void)gen;
	paint_r(s, ck->pos, ck->disabled ? ck->falsc : ck->background, 1);
	if (ck->checked)
		paint_r(s, new_sdlrect(ck->pos.x + ck->pos.w / 4, ck->pos.y + ck->pos.w
				/ 4, ck->pos.w - ck->pos.w / 2, ck->pos.h - ck->pos.w / 2),
			ck->color, 1);
	paint_r(s, ck->pos, ck->border, 0);
}
