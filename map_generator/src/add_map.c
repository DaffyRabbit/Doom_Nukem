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

void	add_map2(t_gen *gen)
{
	int i;

	i = -1;
	malloc_map(gen);
	while (gen->allmap->x >= ++i)
		second_malloc(gen, i);
	gnl_loop(gen);
	close(gen->allmap->fd);
	print_map(gen, 0, 0, 0);
}

void	map_gnl_loop(t_gen *gen, char *line, char **str_map)
{
	int	i;
	int	j;

	while (get_next_line(gen->allmap->fd, &line) > 0)
	{
		gen->allmap->y++;
		i = 0;
		j = 0;
		str_map = ft_strsplit(line, ' ');
		while (str_map[i])
		{
			j++;
			free(str_map[i]);
			i++;
		}
		if (j != gen->allmap->x)
		{
			ft_putendl("BROKEN MAP");
			ft_bb(gen);
		}
		free(line);
		free(str_map);
	}
}

void	abrakadabra(t_gen *gen)
{
	if (gen->allmap->y < 5 || gen->allmap->y > 200
		|| gen->allmap->x < 5 || gen->allmap->x > 200)
	{
		ft_putendl("Map too big/small!!!");
		ft_bb(gen);
	}
	close(gen->allmap->fd);
	add_map2(gen);
}

void	add_map(t_gen *gen)
{
	int		i;
	char	**str_map;
	char	*line;

	i = 0;
	if (get_next_line(gen->allmap->fd, &line) > 0)
	{
		gen->allmap->y = 1;
		str_map = ft_strsplit(line, ' ');
		while (str_map[i])
		{
			gen->allmap->x++;
			free(str_map[i]);
			i++;
		}
		free(line);
		free(str_map);
		map_gnl_loop(gen, line, str_map);
	}
	abrakadabra(gen);
}
