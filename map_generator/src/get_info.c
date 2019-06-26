/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:27:20 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/25 19:27:31 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gen.h"

t_uid				*get_new_uid(t_gen *gen)
{
	t_uid			*srcs;

	if (!(srcs = maloc_alt(sizeof(t_uid))))
		ft_bb(gen);
	srcs->id = wery_i_f(gen);
	srcs->uix = 0;
	srcs->uiy = 0;
	srcs->uiw = 100;
	srcs->uih = 100;
	return (srcs);
}

void				last_up_tool(t_gen *gen, t_list *tmp, int x, int y)
{
	t_tool_t		*tmp_bt;

	tmp_bt = (t_tool_t *)tmp->content;
	paint_r_2(gen, gen->generus.gen_s, new_sdlrect(x, y, 170, 70),
		tmp_bt->tool_c, 1);
	gen->tmp_color = new_rgb_mask(0, 0, 0, 255);
	i_need_tx(gen, gen->generus.gen_s,
		tmp_bt->tool_id, new_sdlrect(x + 10, y + 22, 20, 0));
	if (lcm() && where_m(gen->m_x, gen->m_y,
			new_sdlrect(gen->generus.gen_r.x
				+ x, gen->generus.gen_r.y + y, 170, 70)))
		take_tool_t(gen, tmp_bt);
}

void				repeat_tool_t(t_gen *gen, t_tool_t *type, t_strc_type *blk)
{
	gen->generus.selected_block = type;
	gen->generus.foc.bonus_param = blk->tool_t;
	something_new(gen);
}

void				take_tool_t(t_gen *gen, t_tool_t *type)
{
	gen->generus.selected_block = type;
	if (gen->generus.selected_block->tool_index != repeat_tool)
		gen->eve_id = 0;
	gen->generus.foc.bonus_param = type->tool_index;
	something_new(gen);
}

void				gen_update_surf(t_gen *gen)
{
	t_generator		*e;

	e = &gen->generus;
	if (e->selected_block)
	{
		gen->selected_block = ft_strdup(e->selected_block->tool_id);
		free(gen->generus.current_tool->text);
		gen->generus.current_tool->text = ft_strjoin_alt("Tool type : ",
			gen->selected_block, 0);
		tx_pre(gen, gen->generus.current_tool, 1, 0);
		if (e->selected_block->tool_index != repeat_tool)
			gen_show_this_for_me(gen, e);
	}
}
