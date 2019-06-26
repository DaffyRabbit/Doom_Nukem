/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:54:14 by rhusak            #+#    #+#             */
/*   Updated: 2019/06/25 20:54:16 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gen.h"

int		chek_num_sec_check(t_gen *gen, int res, int x, int y)
{
	if (res >= 25 && res <= 32)
	{
		gen->allmap->map[x][y] = 25;
		gen->allmap->event_id[x][y] = res - 25;
		return (-1);
	}
	if (res == 34)
	{
		gen->allmap->map[x][y] = 34;
		gen->allmap->event_id[x][y] = 34;
		return (-1);
	}
	return (0);
}

int		chek_num(char *str, int x, int y, t_gen *gen)
{
	int i;
	int res;
	int	a;

	i = 1;
	res = 0;
	if (ft_isdigit(str[0]) == 0)
		return (-1);
	res += str[0] - 48;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	if ((a = chek_num_check(gen, res, x, y)) == -1)
		return (0);
	if ((a = chek_num_sec_check(gen, res, x, y)) == -1)
		return (0);
	return (-1);
}

void	second_malloc(t_gen *gen, int i)
{
	gen->allmap->map[i] = (int *)malloc(sizeof(int) * gen->allmap->y + 1);
	gen->allmap->event_id[i] = (int *)malloc(sizeof(int) * gen->allmap->y + 1);
}

void	malloc_map(t_gen *gen)
{
	gen->allmap->fd = open(gen->allmap->map_name, O_RDONLY);
	gen->allmap->map = (int **)malloc(sizeof(int *) * gen->allmap->x + 1);
	gen->allmap->event_id = (int **)malloc(sizeof(int *)
		* gen->allmap->x + 1);
}

void	gnl_loop(t_gen *gen)
{
	char	**str_map;
	char	*line;
	int		i;
	int		j;

	j = 0;
	while (get_next_line(gen->allmap->fd, &line) > 0)
	{
		i = 0;
		str_map = ft_strsplit(line, ' ');
		while (str_map[i])
		{
			if (chek_num(str_map[i], i, j, gen) == -1)
			{
				ft_putendl(ft_strjoin("WRONG SYMBOL ", str_map[i]));
				ft_bb(gen);
			}
			free(str_map[i]);
			i++;
		}
		free(line);
		free(str_map);
		j++;
	}
}
