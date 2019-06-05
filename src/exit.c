/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:41:23 by arykov            #+#    #+#             */
/*   Updated: 2018/11/30 13:41:30 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	all_destroy(t_box *box)
{
	printf("map_list = %lu\n", sizeof(box->map_list));
	printf("sprites = %lu\n", sizeof(box->sprites));
	printf("keys = %lu\n", sizeof(box->keys));
	printf("bag = %lu\n", sizeof(box->bag));
	printf("hud = %lu\n", sizeof(box->hud));
	printf("txtrs = %lu\n", sizeof(box->txtrs));
	printf("menu_txtrs = %lu\n", sizeof(box->menu_txtrs));
	printf("music = %lu\n", sizeof(box->music));
	printf("dsprite = %lu\n", sizeof(box->dsprite));
	printf("tir = %lu\n", sizeof(box->tir));
	printf("cam = %lu\n", sizeof(box->cam));
	printf("mouse = %lu\n", sizeof(box->mouse));
	printf("block = %lu\n", sizeof(box->block));
	printf("go = %lu\n", sizeof(box->go));
	printf("ogo = %lu\n", sizeof(box->ogo));
	printf("paramtext = %lu\n", sizeof(box->paramtext));
	printf("pic = %lu\n", sizeof(box->pic));
	printf("wind = %lu\n", sizeof(box->wind));
	printf("texture = %lu\n", sizeof(box->texture));
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
