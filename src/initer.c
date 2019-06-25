#include "gen.h"

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

void init_all(t_gen *gen)
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

TTF_Font	*gen_ttf(t_gen *gen, char *font_path, int size)
{
	t_list	*tmp;
	t_font	*tmp_font;
	t_font	*font;

	tmp = gen->fonts->prev;
	while (tmp)
	{
		tmp_font = (t_font *)tmp->content;
		if (ft_strcmp(font_path, tmp_font->font_path) == 0
			&& size == tmp_font->size)
			return (tmp_font->font);
		tmp = tmp->next;
	}
	if (!(font = maloc_alt(sizeof(t_font))))
		ft_bb(gen);
	font->font = TTF_OpenFont(font_path, size);
	font->font_path = font_path;
	font->size = size;
	lbox_add(gen->fonts, font);
	return (font->font);
}

void		load_ttf(t_gen *gen)
{
	if (!(gen->texts = lbox_new()))
		ft_bb(gen);
	if (!(gen->fonts = lbox_new()))
		ft_bb(gen);
	TTF_Init();
	gen_ttf(gen, "ttf/mainfont.ttf", 20);
}

void		del_ttf(t_gen *gen)
{
	t_list	*tmp;
	t_font	*tmp_font;

	tmp = gen->fonts->prev;
	while (tmp)
	{
		tmp_font = (t_font *)tmp->content;
		TTF_CloseFont(tmp_font->font);
		tmp = tmp->next;
	}
	ft_lstdel_alt(gen->fonts->prev, 0);
	free(gen->fonts);
	TTF_Quit();
}

t_tool_t	*new_tool_t(t_gen *gen, char *bn, Uint32 bc, int bt)
{
	t_tool_t	*tool_t;

	if (!(tool_t = maloc_alt(sizeof(t_tool_t))))
		ft_bb(gen);
	
	tool_t->tool_id = ft_strdup(bn);
	tool_t->tool_c = bc;
	tool_t->tool_index = bt;
	return (tool_t);
}

void	load_some_code(t_gen *gen)
{
	gen->toll_code = lbox_new();
	lbox_add(gen->toll_code, new_tool_t(gen, "Copy Settings", 0xFF47593c, repeat_tool));
	lbox_add(gen->toll_code, new_tool_t(gen, "Event", 0xFFe5e5e5, event_tool));
	lbox_add(gen->toll_code, new_tool_t(gen, "Wall", 0xFF4c4c4c, wall_tool));
	lbox_add(gen->toll_code, new_tool_t(gen, "Spawn Point", 0xFFa31010, startpoint_tool));
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

SDL_Rect	new_sdlrect(int x, int y, int width, int height)
{
	SDL_Rect	rect;

	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
	return (rect);
}

void		paint_r(SDL_Surface *s, SDL_Rect rect, SDL_Color color,
													int fill_rect)
{
	SDL_Rect rc;

	if (fill_rect)
		SDL_FillRect(s, &rect, r_a_i(color.r, color.g, color.b, color.a));
	else
	{
		rc = new_sdlrect(rect.x, rect.y, rect.w, 1);
		SDL_FillRect(s, &rc, r_a_i(color.r, color.g, color.b, color.a));
		rc = new_sdlrect(rect.x, rect.y + rect.h - 1, rect.w, 1);
		SDL_FillRect(s, &rc, r_a_i(color.r, color.g, color.b, color.a));
		rc = new_sdlrect(rect.x, rect.y, 1, rect.h);
		SDL_FillRect(s, &rc, r_a_i(color.r, color.g, color.b, color.a));
		rc = new_sdlrect(rect.x + rect.w - 1, rect.y, 1, rect.h);
		SDL_FillRect(s, &rc, r_a_i(color.r, color.g, color.b, color.a));
	}
}

void		paint_r_2(SDL_Surface *s, SDL_Rect rect, Uint32 color,
														int fill_rect)
{
	SDL_Rect rc;

	if (fill_rect)
		SDL_FillRect(s, &rect, color);
	else
	{
		rc = new_sdlrect(rect.x, rect.y, rect.w, 1);
		SDL_FillRect(s, &rc, color);
		rc = new_sdlrect(rect.x, rect.y + rect.h - 1, rect.w, 1);
		SDL_FillRect(s, &rc, color);
		rc = new_sdlrect(rect.x, rect.y, 1, rect.h);
		SDL_FillRect(s, &rc, color);
		rc = new_sdlrect(rect.x + rect.w - 1, rect.y, 1, rect.h);
		SDL_FillRect(s, &rc, color);
	}
}

SDL_Color	new_rgb_mask(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_Color color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

t_el_text	*add_tx(t_gen *gen, char *string, char *font_path, int size)
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

void 	load_generus_pls(t_gen *gen)
{
	t_generator	*red;

	red = &gen->generus;
	red->separator = 1;
	red->surf_gen = SDL_CreateRGBSurfaceWithFormat(0, WIN_W, WIN_H, 32, gen->surface->format->format);
	editor_win_param(gen);
	red->base_color = new_rgb_mask(0, 194, 199, 255);
	red->select_color = new_rgb_mask(0, 194, 199, 255);
	load_ev(gen);
	red->selected_block = NULL;
	red->r = new_sdlrect(red->x_gen, red->y_gen, red->w_gen, red->h_gen);
	red->this_el_par = SDL_CreateRGBSurfaceWithFormat(0, red->w_gen, red->h_gen, 32, gen->surface->format->format);
	red->qua.cam_scale = red->r.h / gen->allmap->y * 0.9;
	red->qua.def_x = red->r.w / 2 - gen->allmap->x * red->qua.cam_scale / 2;
	red->qua.def_y = red->r.h / 2 - gen->allmap->y * red->qua.cam_scale / 2;
	red->qua.pos_x = red->r.x;
	red->qua.pos_y = red->r.y;
	red->gen_r = new_sdlrect(0, WIN_H - 150, WIN_W, 300);
	red->gen_s = SDL_CreateRGBSurfaceWithFormat(0, red->gen_r.w, red->gen_r.h, 32, gen->surface->format->format);
	red->gen_qua.pos_x = red->gen_r.x;
	red->gen_qua.pos_y = red->gen_r.y;
	red->tool_block = add_new_b(gen, "SYS", new_sdlrect(10, 195, 60, 60), some_usful_ft);
	red->tool_block->background_color = new_rgb_mask(145, 145, 145, 255);
	key_parameters(gen, red->tool_block);
	red->save = add_new_b(gen, "Save to file", new_sdlrect(WIN_W - 250, 10, 200, 60), save_this);
	red->save->background_color = red->select_color;
	red->save->background_color_disabled = new_rgb_mask(145, 145, 145, 255);
	key_parameters(gen, red->save);
	red->current_tool = add_tx(gen, "Tool type : none", "ttf/mainfont.ttf", 30);
	red->current_tool->pn->uix = 90;
	red->current_tool->pn->uiy = 20;
	red->more_qua.this_ind = new_bucket(gen, new_sdlrect(15, 190, 270, 30), new_sdlrect(0, 1000, 50, 1));
	red->more_qua.this_ind->unit = "";
	up_bucket(gen, red->more_qua.this_ind);
	red->more_qua.h_s = new_bucket(gen, new_sdlrect(15, 265, 270, 30), new_sdlrect(0, 1000, 50, 10));
	red->more_qua.h_s->unit = "%";
	up_bucket(gen, red->more_qua.h_s);
	red->more_qua.ge_s = new_bucket(gen, new_sdlrect(15, 380, 270, 30), new_sdlrect(0, 100, 50, 5));
	red->more_qua.ge_s->unit = "%";
	up_bucket(gen, red->more_qua.ge_s);
	red->more_qua.ge_h = new_bucket(gen, new_sdlrect(15, 455, 270, 30), new_sdlrect(0, 100, 50, 5));
	red->more_qua.ge_h->unit = "%";
	up_bucket(gen, red->more_qua.ge_h);
	red->more_qua.param_3 = gen_help(gen, new_sdlrect(256, 310, 29, 29), 0);
	red->more_qua.param1 = gen_help(gen, new_sdlrect(256, 50, 29, 29), 0);
	red->more_qua.param2 = gen_help(gen, new_sdlrect(256, 90, 29, 29), 0);
	take_new_tool(gen, tool_block);
	//red->average_fps = 0;
	paint_r_2(red->surf_gen, new_sdlrect(0, 0, WIN_W, WIN_H), 0xFF00C2C7, 1);
}
