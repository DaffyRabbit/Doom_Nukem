/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 22:02:29 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/17 22:02:31 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	all_destroy(t_box *box)
{
	if (box->rend != NULL)
		SDL_DestroyRenderer(box->rend);
	if (box->texture != NULL)
		SDL_DestroyTexture(box->texture);
	ft_freee(box);
	ft_music_free(box);
	SDL_DestroyWindow(box->wind);
	SDL_Quit();
	exit(0);
}

int		small_map(t_box *box)
{
	if (box->mapx >= 5 && box->mapy >= 5)
		return (0);
	return (box->error = -9);
}
