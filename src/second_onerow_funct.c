/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_onerow_funct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:24:27 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/25 19:24:42 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen.h"

void				something_new(t_gen *gen)
{
	t_generator		*e;

	e = &gen->generus;
}

void				for_one_time(t_strc_type *dest, t_strc_type *src, int free2)
{
	dest->tool_t = src->tool_t;
	if (free2)
		free(src);
}

void				reset_tt(t_strc_type *dest)
{
	dest->tool_t = wall_tool;
}

int					where_b(t_el_key *button, int x, int y)
{
	if (x >= button->real_x && x <= (button->real_x + button->rect.w))
		if (y >= button->real_y && y <= (button->real_y + button->rect.h))
			return (1);
	return (0);
}

void				updait_b(t_el_key *but, int x, int y)
{
	but->real_x += x;
	but->real_y += y;
}
