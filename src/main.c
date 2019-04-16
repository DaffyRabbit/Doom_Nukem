/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:42:09 by arykov            #+#    #+#             */
/*   Updated: 2018/11/30 13:42:11 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				main(void)
{
	t_box		box;
	t_pic		pic;

	box.go.south = 0;
	start_game(&box, &pic, "Wolf3d");
	return (0);
}
