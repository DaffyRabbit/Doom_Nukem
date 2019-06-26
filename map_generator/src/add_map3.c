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

void	write_loop(t_gen *gen, int x, int y, int fd)
{
	int		res;
	char	*hyu;

	if (gen->allmap->map[x][y] == 999)
		res = 999;
	if (gen->allmap->map[x][y] == 1 || gen->allmap->map[x][y] == 25)
		res = gen->allmap->map[x][y] + gen->allmap->event_id[x][y];
	if (gen->allmap->map[x][y] == 34)
		res = 34;
	hyu = ft_itoa(res);
	ft_putstr_fd(hyu, fd);
	ft_putchar_fd(' ', fd);
	free(hyu);
}

int		write_this(t_gen *gen, char *path)
{
	int		x;
	int		y;
	int		fd;

	y = 0;
	gen->allmap->fd = open(gen->allmap->map_name, O_RDONLY);
	if (gen->allmap->fd < 0)
	{
		gen->allmap->fd = open(gen->allmap->map_name,
			O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
		close(gen->allmap->fd);
	}
	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC | O_NOFOLLOW);
	while (gen->allmap->y > y)
	{
		x = 0;
		while (gen->allmap->x > x)
		{
			write_loop(gen, x, y, fd);
			x++;
		}
		ft_putchar_fd('\n', fd);
		y++;
	}
	return (1);
}

void	save_this(t_gen *gen, t_el_key *b, SDL_MouseButtonEvent ev)
{
	char	*str;

	(void)ev;
	b->is_disabled = 1;
	str = ft_strjoin("Saving file in ", gen->allmap->map_name);
	ft_putendl(str);
	free(str);
	write_this(gen, gen->allmap->map_name);
	b->is_disabled = 0;
}

void	print_map(t_gen *gen, int y, int x, int res)
{
	char	*a;

	while (gen->allmap->y > y)
	{
		x = 0;
		while (gen->allmap->x > x)
		{
			if (gen->allmap->map[x][y] == 999)
				res = 999;
			if (gen->allmap->map[x][y] == 1)
				res = gen->allmap->map[x][y] + gen->allmap->event_id[x][y] - 1;
			if (gen->allmap->map[x][y] == 25)
				res = gen->allmap->map[x][y] + gen->allmap->event_id[x][y];
			if (gen->allmap->map[x][y] == 34)
				res = 34;
			a = ft_itoa(res);
			ft_putstr(a);
			free(a);
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	ft_putchar('\n');
}

int		chek_num_check(t_gen *gen, int res, int x, int y)
{
	if (res >= 0 && res <= 9)
	{
		gen->allmap->map[x][y] = 1;
		if (res != 0)
			gen->allmap->event_id[x][y] = res - 1;
		else
			gen->allmap->event_id[x][y] = res;
		return (-1);
	}
	if (res == 999)
	{
		gen->allmap->map[x][y] = 999;
		gen->allmap->event_id[x][y] = 0;
		return (-1);
	}
	return (0);
}
