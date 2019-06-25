/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:41:48 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/25 19:41:49 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen.h"

void	ft_bb(t_gen *gen)
{
	if (gen && gen->win)
	{
		SDL_SetRelativeMouseMode(SDL_FALSE);
		SDL_WarpMouseInWindow(gen->win, WIN_W / 2, WIN_H / 2);
	}
	SDL_Quit();
	exit(0);
}
