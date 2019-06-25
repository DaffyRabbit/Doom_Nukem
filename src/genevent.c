#include "gen.h"

void		i_need_tx(t_gen *gen, SDL_Surface *s, char *st, SDL_Rect poscols)
{
	SDL_Surface *su;
	TTF_Font	*f;
	int			w;
	int			h;
	SDL_Rect	rect;

	if ((f = gen_ttf(gen, "ttf/mainfont.ttf", poscols.w)))
	{
		su = TTF_RenderUTF8_Blended(
			f,
			st,
			gen->tmp_color);
		TTF_SizeUTF8(f, st, &w, &h);
		rect = new_sdlrect(poscols.x, poscols.y, w, h);
		SDL_BlitSurface(su, NULL, s, &rect);
		SDL_FreeSurface(su);
	}
	if (poscols.h)
		free(st);
}

void	load_new_ev(t_gen *gen)
{
	if ((gen->events = lbox_new()) == NULL)
		ft_bb(gen);
}

void	del_ev(t_gen *gen, SDL_Event sdl_event)
{
	t_list				*list;
	t_registered_event	*event;

	list = gen->events->prev;
	while (list)
	{
		event = (t_registered_event *)list->content;
		if (event->type == sdl_event.type
			&& gen->game_mode == event->gamemode)
		{
			event->handler(gen, sdl_event);
		}
		list = list->next;
	}
	ft_lstdel_alt(list, 1);
}