/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:09:09 by arykov            #+#    #+#             */
/*   Updated: 2018/11/30 14:09:10 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		paint_this(t_box *box)
{
	some_pthreads(box);
	just_travel(box);
	some_rotation(box);
	return (0);
}

void	just_travel(t_box *box)
{
	if (box->go.tohell == 1)
	{
		if (box->all_map[(int)box->cam.position.y]
				[(int)(box->cam.position.x -
					box->cam.d.x * box->go.spd)] == 0)
			box->cam.position.x -= box->cam.d.x * box->go.spd;
		if (box->all_map[(int)(box->cam.position.y -
								box->cam.d.y * box->go.spd)]
				[(int)box->cam.position.x] == 0)
			box->cam.position.y -= box->cam.d.y * box->go.spd;
	}
	if (box->go.insky == 1)
	{
		if (box->all_map[(int)box->cam.position.y]
				[(int)(box->cam.position.x +
					box->cam.d.x * box->go.spd)] == 0)
			box->cam.position.x += box->cam.d.x * box->go.spd;
		if (box->all_map[(int)(box->cam.position.y +
						box->cam.d.y * box->go.spd)]
				[(int)box->cam.position.x] == 0)
			box->cam.position.y += box->cam.d.y * box->go.spd;
	}
	go_and_west(box);
	ttsky_and_sit(box);
}

void	go_and_west(t_box *box)
{
	if (box->go.south == 1)
	{
		if (box->all_map[(int)box->cam.position.y]
				[(int)(box->cam.position.x -
					box->cam.p.x * box->go.spd)] == 0)
			box->cam.position.x -= box->cam.p.x * box->go.spd;
		if (box->all_map[(int)(box->cam.position.y -
						box->cam.p.y * box->go.spd)]
				[(int)box->cam.position.x] == 0)
			box->cam.position.y -= box->cam.p.y * box->go.spd;
	}
	if (box->go.west == 1)
	{
		if (box->all_map[(int)box->cam.position.y]
				[(int)(box->cam.position.x +
					box->cam.p.x * box->go.spd)] == 0)
			box->cam.position.x += box->cam.p.x * box->go.spd;
		if (box->all_map[(int)(box->cam.position.y +
						box->cam.p.y * box->go.spd)]
				[(int)box->cam.position.x] == 0)
			box->cam.position.y += box->cam.p.y * box->go.spd;
	}
}

void	some_rotation(t_box *box)
{
	double	i;

	box->ogo.spd = 0.05;
	if (box->ogo.west == 1 || box->ogo.south == 1)
	{
		if (box->ogo.south == 1)
			box->ogo.spd = -box->ogo.spd;
		i = box->cam.d.x;
		box->cam.d.x = box->cam.d.x * cos(box->ogo.spd) -
			box->cam.d.y * sin(box->ogo.spd);
		box->cam.d.y = i * sin(box->ogo.spd) +
			box->cam.d.y * cos(box->ogo.spd);
		i = box->cam.p.x;
		box->cam.p.x = box->cam.p.x * cos(box->ogo.spd) -
			box->cam.p.y * sin(box->ogo.spd);
		box->cam.p.y = i * sin(box->ogo.spd) +
			box->cam.p.y * cos(box->ogo.spd);
	}
	if (box->ogo.insky == 1 && box->ogo.lop < 1000)
		box->ogo.lop += 20;
	if (box->ogo.tohell == 1 && box->ogo.lop > -1000)
		box->ogo.lop -= 20;
}

void	ttsky_and_sit(t_box *box)
{
	if (box->ttsky2 == 1 && box->go.lop < 0.7)
		box->go.lop += 0.075;
	if (box->go.lop >= 0.7)
		box->ttsky2 = 0;
	if (box->ttsky2 == 0 && box->go.lop > 0)
		box->go.lop -= 0.075;
	if (box->sitd == 1 && box->go.lop > -0.5)
		box->go.lop -= 0.1;
	if (box->sitd == 0 && box->go.lop < 0)
	{
		box->go.lop += 0.1;
		box->go.lop = box->go.lop > 0 ? 0 : box->go.lop;
	}
}
