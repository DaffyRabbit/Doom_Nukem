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

#include "doomnukem.h"

int			doors_validation(t_box *box, int i)
{
	int		j;

	while (i < box->mapy)
	{
		j = 1;
		while (j < box->mapx)
		{
			if (box->all_map[i][j] == 34)
			{
				if (box->all_map[i - 1][j] == 34 || box->all_map[i + 1][j] ==
					34 || box->all_map[i - 1][j] == 34 || box->all_map[i]
					[j + 1] == 34 || box->all_map[i][j - 1] == 34)
					return (-1);
				if (box->all_map[i - 1][j] < 25 || box->all_map[i + 1][j] < 25)
				{
					if (box->all_map[i][j - 1] < 25 ||
						box->all_map[i][j + 1] < 25)
						return (-1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

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
	if ((res > 9 && res < 25) || (res > 34 && res != 999) ||
		res == 1 || res == 33)
		res = 0;
	return (res);
}

int			start_point(t_box *box, int i, int n)
{
	box->cam.position.x = i + 0.5;
	box->cam.position.y = box->uselessy + 0.5;
	box->all_map[box->uselessy][i] = 0;
	n *= 2;
	return (n);
}

int			check_map_par(t_box *b, char *str, int i, int n)
{
	int		a;

	a = add_to_map(str);
	if ((b->uselessy == 0 || b->uselessy == b->mapy) && (a < 25 || a > 32))
		a = 25;
	if ((a < 25 || a > 32) && (i == 0 || i == b->mapx))
		a = 25;
	if (a == 999)
	{
		n = start_point(b, i, n);
		return (n);
	}
	if (a == 4)
		b->all_map[b->uselessy][i] = 0;
	else
		b->all_map[b->uselessy][i] = a;
	if (a >= 2 && a <= 9)
	{
		b->sprites_amount++;
		add_sprite(b, a, i, b->uselessy);
	}
	if (b->sprites_amount > 59)
		return (-1);
	return (n);
}
