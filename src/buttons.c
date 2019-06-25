#include "gen.h"

t_el_key	*add_new_b(t_gen *gen, char *string, SDL_Rect rect, void (*pn_callback)(t_gen *gen, t_el_key *b, SDL_MouseButtonEvent event))
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

void		key_parameters(t_gen *gen, t_el_key *button)
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

t_w_strc	*new_bucket(t_gen *gen, SDL_Rect rc, SDL_Rect mmvs)
{
	t_w_strc	*jg;
	char			*s;

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
	if ((jg->txt = add_tx(gen, s, "ttf/mainfont.ttf", 20)))
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

t_echb	*gen_help(t_gen *gen, SDL_Rect pos, int checked)
{
	t_echb	*ck;

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