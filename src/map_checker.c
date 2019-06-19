/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:05:17 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/19 14:05:19 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			check_map(t_box *box)
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

int			add_to_map(char *str)
{
	int		i;
	int		res;

	i = 1;
	res = str[0] - 48;
	if (str[1] != '\0')
		res *= 10;
	while (str[i] != '\0')
	{
		res += str[i] - 48;
		i++;
		if (str[i] != '\0')
			res *= 10;
	}
	return (res);
}

int			check_map_par(t_box *box, char *str, int i, int n)
{
	int		block;

	block = add_to_map(str);
	if ((box->uselessy == 0 || box->uselessy == box->mapy) &&
		(block == 0 || block == 999))
		return (-1);
	if ((block == 0 || block == 999) && (i == 0 || i == box->mapx))
		return (-1);
	if (block == 999)
	{
		box->cam.position.x = i + 0.5;
		box->cam.position.y = box->uselessy + 0.5;
		box->all_map[box->uselessy][i] = 0;
		n *= 2;
		return (n);
	}
	if (block == 4)
		box->all_map[box->uselessy][i] = 0;
	else
		box->all_map[box->uselessy][i] = block;
	if (block >= 2 && block <= 9)
		add_sprite(box, block, i, box->uselessy);
	return (n);
}
