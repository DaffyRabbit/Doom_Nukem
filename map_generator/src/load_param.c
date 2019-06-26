/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:59:03 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/25 19:59:16 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gen.h"

SDL_Color		new_rgb_mask(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_Color color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

t_el_text		*add_tx(t_gen *gen, char *string, char *font_path, int size)
{
	t_el_text	*text;

	if (!(text = maloc_alt(sizeof(t_el_text))))
		ft_bb(gen);
	lbox_add(gen->texts, text);
	text->surface = NULL;
	text->list_id = gen->texts->next->content_size;
	text->pn = get_new_uid(gen);
	text->text_color.r = 218;
	text->text_color.g = 248;
	text->text_color.b = 227;
	text->text_color.a = 255;
	if (!(text->font = gen_ttf(gen, font_path, size)))
	{
		free(text->pn);
		free(text);
		return (NULL);
	}
	text->text = ft_strdup(string);
	ts(text);
	text->pn->uiw = text->weighu;
	text->pn->uih = text->heighu;
	return (text);
}

void			load_generus_pls_third(t_gen *gen, t_generator *red)
{
	red->more_qua.h_s->unit = "%";
	up_bucket(gen, red->more_qua.h_s);
	red->more_qua.ge_s = new_bucket(gen, new_sdlrect(15, 380, 270, 30),
		new_sdlrect(0, 100, 50, 5));
	red->more_qua.ge_s->unit = "%";
	up_bucket(gen, red->more_qua.ge_s);
	red->more_qua.ge_h = new_bucket(gen, new_sdlrect(15, 455, 270, 30),
		new_sdlrect(0, 100, 50, 5));
	red->more_qua.ge_h->unit = "%";
	up_bucket(gen, red->more_qua.ge_h);
	red->more_qua.param_3 = gen_help(gen, new_sdlrect(256, 310, 29, 29), 0);
	red->more_qua.param1 = gen_help(gen, new_sdlrect(256, 50, 29, 29), 0);
	red->more_qua.param2 = gen_help(gen, new_sdlrect(256, 90, 29, 29), 0);
	take_new_tool(gen, tool_block);
	paint_r_2(gen, red->surf_gen, new_sdlrect(0, 0, WIN_W, WIN_H), 0xFF00C2C7, 1);
}

void			load_generus_pls_sec(t_gen *gen, t_generator *red)
{
	red->gen_qua.pos_x = red->gen_r.x;
	red->gen_qua.pos_y = red->gen_r.y;
	red->tool_block = add_new_b(gen, "SYS", new_sdlrect(10, 195, 60, 60),
		some_usful_ft);
	red->tool_block->background_color = new_rgb_mask(145, 145, 145, 255);
	key_parameters(gen, red->tool_block);
	red->save = add_new_b(gen, "Save to file",
		new_sdlrect(WIN_W - 250, 10, 200, 60), save_this);
	red->save->background_color = red->select_color;
	red->save->background_color_disabled = new_rgb_mask(145, 145, 145, 255);
	key_parameters(gen, red->save);
	red->current_tool = add_tx(gen, "Tool type : none", "ttf/gener_font.ttf", 30);
	red->current_tool->pn->uix = 90;
	red->current_tool->pn->uiy = 20;
	red->more_qua.this_ind = new_bucket(gen, new_sdlrect(15, 190, 270, 30),
		new_sdlrect(0, 1000, 50, 1));
	red->more_qua.this_ind->unit = "";
	up_bucket(gen, red->more_qua.this_ind);
	red->more_qua.h_s = new_bucket(gen, new_sdlrect(15, 265, 270, 30),
		new_sdlrect(0, 1000, 50, 10));
	load_generus_pls_third(gen, red);
}

void			load_generus_pls(t_gen *gen)
{
	t_generator	*red;

	red = &gen->generus;
	red->separator = 1;
	red->surf_gen = SDL_CreateRGBSurfaceWithFormat(0, WIN_W, WIN_H, 32,
		gen->surface->format->format);
	editor_win_param(gen);
	red->base_color = new_rgb_mask(0, 194, 199, 255);
	red->select_color = new_rgb_mask(0, 194, 199, 255);
	load_ev(gen);
	red->selected_block = NULL;
	red->r = new_sdlrect(red->x_gen, red->y_gen, red->w_gen, red->h_gen);
	red->this_el_par = SDL_CreateRGBSurfaceWithFormat(0, red->w_gen, red->h_gen,
		32, gen->surface->format->format);
	red->qua.cam_scale = red->r.h / gen->allmap->y * 0.9;
	red->qua.def_x = red->r.w / 2 - gen->allmap->x * red->qua.cam_scale / 2;
	red->qua.def_y = red->r.h / 2 - gen->allmap->y * red->qua.cam_scale / 2;
	red->qua.pos_x = red->r.x;
	red->qua.pos_y = red->r.y;
	red->gen_r = new_sdlrect(0, WIN_H - 150, WIN_W, 300);
	red->gen_s = SDL_CreateRGBSurfaceWithFormat(0, red->gen_r.w, red->gen_r.h,
		32, gen->surface->format->format);
	load_generus_pls_sec(gen, red);
}
