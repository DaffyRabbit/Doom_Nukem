#include "gen.h"

void		re_text(t_gen *gen, SDL_Surface *surface, t_el_text *text)
{
	if (!text)
		return ;
	(void)gen;
	SDL_BlitSurface(text->surface, NULL, surface, &text->rect);
}

void		tx_pre(t_gen *gen, t_el_text *text, int mk_size, int cent)
{
	(void)gen;
	if (!text)
		return ;
	SDL_FreeSurface(text->surface);
	text->surface = TTF_RenderUTF8_Blended(
		text->font,
		text->text,
		text->text_color);
	if (mk_size)
	{
		ts(text);
		text->pn->uiw = text->weighu;
		text->pn->uih = text->weighu;
	}
	text->rect.x = cent ? text->pn->uix - text->weighu / 2 : text->pn->uix;
	text->rect.y = cent ? text->pn->uiy - text->heighu / 2 : text->pn->uiy;
	text->rect.w = text->pn->uiw;
	text->rect.h = text->pn->uih;
}

void	take_new_tool(t_gen *gen, int to_tool)
{
	gen->generus.hand_tool = to_tool > 0 && to_tool <= 3 ? to_tool : 0;
	if (gen->generus.current_tool)
	{
		free(gen->generus.current_tool->text);
		gen->generus.current_tool->text = ft_strjoin_alt("Tool type : ", gen->selected_block, 0);
		tx_pre(gen, gen->generus.current_tool, 1, 0);
	}
	how_b_look_like(gen, to_tool);
}

Uint32		c_in_u(SDL_Color color)
{
	return (Uint32)((color.r << 16) + (color.g << 8) + (color.b << 0));
}

int			where_m(int m_x, int m_y, SDL_Rect rect)
{
	if (m_x >= rect.x && m_x < rect.x + rect.w)
		if (m_y >= rect.y && m_y < rect.y + rect.h)
			return (1);
	return (0);
}

int			lcm(void)
{
	return (SDL_GetMouseState(NULL, NULL) == SDL_BUTTON_LMASK);
}

int			lrm(void)
{
	return (SDL_GetMouseState(NULL, NULL) == SDL_BUTTON_RMASK);
}

SDL_Rect	m_trak(void)
{
	int	x;
	int	y;

	SDL_GetMouseState(&x, &y);
	return (new_sdlrect(x, y, 0, 0));
}