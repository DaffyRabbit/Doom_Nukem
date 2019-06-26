/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:00:08 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/25 20:00:21 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gen.h"

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
	gen_ttf(gen, "ttf/gener_font.ttf", 20);
}

void		del_ttf(t_gen *gen)
{
	t_list		*tmp;
	t_font		*tmp_font;

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
