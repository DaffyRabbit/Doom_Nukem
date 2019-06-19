/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_n_add_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:05:04 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/19 17:05:05 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_my_swap1(t_box *box, int i, int j)
{
	double	temp;

	temp = box->sprites.spriteDistance[i];
	box->sprites.spriteDistance[i] = box->sprites.spriteDistance[j];
	box->sprites.spriteDistance[j] = temp;
}

void		ft_my_swap2(t_box *box, int i, int j)
{
	int	temp;

	temp = box->sprites.spriteOrder[i];
	box->sprites.spriteOrder[i] = box->sprites.spriteOrder[j];
	box->sprites.spriteOrder[j] = temp;
}

void		add_sprite(t_box *box, int n, int x, int y)
{
	box->sprites.spt[box->sprites.n_sprites].x = x + 0.5;
	box->sprites.spt[box->sprites.n_sprites].y = y + 0.5;
	if (n == 8)
		box->sprites.spt[box->sprites.n_sprites].n_text = 0;
	if (n == 3)
		box->sprites.spt[box->sprites.n_sprites].n_text = 1;
	if (n == 4)
		box->sprites.spt[box->sprites.n_sprites].n_text = 2;
	if (n == 5)
		box->sprites.spt[box->sprites.n_sprites].n_text = 3;
	if (n == 6)
		box->sprites.spt[box->sprites.n_sprites].n_text = 4;
	if (n == 7)
		box->sprites.spt[box->sprites.n_sprites].n_text = 5;
	if (n == 2)
		box->sprites.spt[box->sprites.n_sprites].n_text = 9;
	if (n == 9)
		box->sprites.spt[box->sprites.n_sprites].n_text = 11;
	box->sprites.n_sprites++;
}
