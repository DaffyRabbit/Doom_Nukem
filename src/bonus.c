/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 20:28:08 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/17 20:28:11 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			some_pthreads(t_box *box)
{
	t_box		this_is_sheet[8];
	pthread_t	t[8];
	int			i;

	i = 0;
	while (i < 8)
	{
		this_is_sheet[i] = *box;
		this_is_sheet[i].atpos = i * (WIND_W / 8 + 1);
		this_is_sheet[i].tpos = (i + 1) * (WIND_W / 8 + 1);
		pthread_create(&t[i], NULL, thi_is_raycast, &this_is_sheet[i]);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		pthread_join(t[i], NULL);
		i++;
	}
}

void			*thi_is_raycast(void *his_is_sheet)
{
	t_box		box;

	box = *(t_box *)his_is_sheet;
	while (box.atpos < box.tpos && box.atpos < WIND_W)
	{
		ray_start(&box);
		this_is_castingray(&box);
		some_blocks(&box);
		print_walls(&box);
		box.atpos++;
	}
	draw_sprites(&box);
	return (0);
}
