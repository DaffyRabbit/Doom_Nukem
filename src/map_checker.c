/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:49:44 by arykov            #+#    #+#             */
/*   Updated: 2018/11/30 14:12:17 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_map(t_box *box)
{
	char	**map;
	char	*line;
	int		n;
	int		i;

	n = 1;
	box->uselessy *= 0;
	while (get_next_line(box->map_fd, &line) > 0)
	{
		i = 0;
		map = ft_strsplit(line, ' ');
		while (map[i])
		{
			if ((n = check_map_par(box, map[i], i, n)) < 0)
				return (box->error = -7);
			else if (n > 2 || (n == 1 && box->uselessy == box->mapy))
				return (box->error = -8);
			free(map[i]);
			i++;
		}
		box->uselessy++;
		free(line);
		free(map);
	}
	return (0);
}

int		check_map_par(t_box *box, char *str, int i, int n)
{
	if ((box->uselessy == 0 || box->uselessy == box->mapy) &&
		(str[0] != '0' || str[0] != '0'))
		box->all_map[box->uselessy][i] = str[0] - 48;
	else if (box->uselessy == 0 || box->uselessy == box->mapy)
		return (-1);
	else if ((str[0] == '0' || str[0] == '9') &&
			(i == 0 || i == box->mapx))
		return (-1);
	else
	{
		if (str[0] == '9')
		{
			box->cam.position.x = i + 0.5;
			box->cam.position.y = box->uselessy + 0.5;
			box->all_map[box->uselessy][i] = 0;
			n *= 2;
		}
		else
			box->all_map[box->uselessy][i] = str[0] - 48;
	}
	return (n);
}
