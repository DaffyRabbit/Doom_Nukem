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

char	*ft_create_path(int i)
{
	char *f;
	char *s;
	char *t;

	f = ft_itoa(i);
	s = ft_strjoin("maps/map", f);
	t = ft_strjoin(s, ".map");
	free(f);
	free(s);
	return (t);
}

void	mx_my_param(t_gen *gen, char *x, char *y)
{
	gen->mx = ft_atoi(x);
	gen->my = ft_atoi(y);
	if (gen->mx < 5)
	{
		ft_putendl("Param\"X\" too small(min 5)");
		gen->mx = 5;
	}
	if (gen->mx > 200)
	{
		ft_putendl("Param\"X\" too big(max 200)");
		gen->mx = 200;
	}
	if (gen->my < 5)
	{
		ft_putendl("Param\"Y\" too small(min 5)");
		gen->my = 5;
	}
	if (gen->my > 200)
	{
		ft_putendl("Param\"Y\" too big(max 200)");
		gen->my = 200;
	}
}

int		allmap_loop(t_gen *gen, int i, char **path)
{
	close(gen->allmap->fd);
	i++;
	free(*path);
	if (i > 250)
	{
		ft_putendl("You created max maps already!");
		ft_bb(gen);
	}
	*path = ft_create_path(i);
	gen->allmap->fd = open(*path, O_RDONLY);
	return (i);
}

void	map_malloc(t_gen *gen)
{
	int	i;

	i = 0;
	gen->allmap->map = (int **)malloc(sizeof(int *) * gen->allmap->x + 1);
	gen->allmap->event_id = (int **)malloc(sizeof(int *) * gen->allmap->x + 1);
	while (gen->allmap->x >= i)
	{
		gen->allmap->map[i] = (int *)malloc(sizeof(int) * gen->allmap->y + 1);
		gen->allmap->event_id[i] = (int *)malloc(sizeof(int)
			* gen->allmap->y + 1);
		i++;
	}
	gen->my = 0;
	while (gen->allmap->y >= gen->my)
	{
		gen->mx = 0;
		while (gen->allmap->x >= gen->mx)
		{
			gen->allmap->map[gen->mx][gen->my] = 0;
			gen->allmap->event_id[gen->mx][gen->my] = 0;
			gen->mx++;
		}
		gen->my++;
	}
}

void	generation_map(t_gen *gen, char *x, char *y)
{
	int		i;
	char	*path;

	i = 0;
	mx_my_param(gen, x, y);
	path = ft_create_path(i);
	gen->allmap->fd = open(path, O_RDONLY);
	while (gen->allmap->fd != -1)
	{
		i = allmap_loop(gen, i, &path);
	}
	gen->allmap->map_name = ft_strdup(path);
	free(path);
	path = ft_strjoin("Creating new map with name ", gen->allmap->map_name);
	ft_putendl(path);
	free(path);
	gen->allmap->x = gen->mx;
	gen->allmap->y = gen->my;
	map_malloc(gen);
}
