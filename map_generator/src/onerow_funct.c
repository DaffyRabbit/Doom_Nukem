/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onerow_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:23:07 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/25 19:23:19 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gen.h"

void				gen_show_this_for_me(t_gen *gen, t_generator *red)
{
	char	*res;
	char	*str;

	res = ft_itoa(gen->eve_id);
	str = ft_strjoin_alt("Object ID: ", res, 0);
	i_need_tx(gen, red->surf_gen, str, new_sdlrect(WIN_W - 680, 25, 18, 0));
	free(str);
	free(res);
}

int					wery_i_f(t_gen *gen)
{
	return (gen->ui_ids++);
}

void				how_b_look_like(t_gen *gen, int tool)
{
	gen->generus.tool_block->background_color = tool == tool_block ?
		gen->generus.select_color : gen->generus.base_color;
}

int					ts(t_el_text *text)
{
	return (TTF_SizeUTF8(text->font, text->text, &text->weighu, &text->heighu));
}

int					r_a_i(int r, int g, int b, int a)
{
	return ((a & 0xff) << 24 | (r & 0xff) << 16 | (g & 0xff) << 8 | (b & 0xff));
}
