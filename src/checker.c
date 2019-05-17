/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:46:28 by arykov            #+#    #+#             */
/*   Updated: 2018/11/30 13:53:01 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		open_map(t_box *box)
{
	if (box->start == 1)
		box->map_fd = open("maps/map0", O_RDONLY);
	else if (box->start == 2)
		box->map_fd = open("maps/map1", O_RDONLY);
	else if (box->start == 3)
		box->map_fd = open("maps/map2", O_RDONLY);
	return (box->map_fd);
}

int		ft_check_all(t_box *box)
{
	int	i;

	i = 0;
	if (check_wrong(box) < 0)
	{
		close(box->map_fd);
		return (-1);
	}
	if (small_map(box) == -9)
		return (-1);
	close(box->map_fd);
	box->all_map = (int **)malloc(sizeof(int *) * box->mapy + 1);
	while (box->mapy >= i)
		box->all_map[i++] = (int *)malloc(sizeof(int) * box->mapx + 1);
	box->mapx--;
	box->mapy--;
	open_map(box);
	if (check_map(box) < 0)
	{
		close(box->map_fd);
		return (-1);
	}
	close(box->map_fd);
	return (0);
}

int		check_wrong(t_box *box)
{
	char	*line;

	if (open_map(box) == -1)
		return (box->error = -2);
	if (get_next_line(box->map_fd, &line) == 0)
		return (box->error = -3);
	free(line);
	return (check_line(box));
}

int		check_c(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i > 0)
			return (-4);
		i++;
	}
	if (str[0] >= '0' && str[0] <= '9')
		return (0);
	return (-5);
}

int		check_line(t_box *box)
{
	char	**w_s;
	char	*line;
	int		cx;

	open_map(box);
	while (get_next_line(box->map_fd, &line) > 0)
	{
		cx = 0;
		w_s = ft_strsplit(line, ' ');
		while (w_s[cx])
		{
			if ((box->error = check_c(w_s[cx])) < 0)
				return (-1);
			free(w_s[cx]);
			cx++;
		}
		free(line);
		free(w_s);
		if (box->mapy == 0)
			box->mapx = cx;
		else if (cx != box->mapx)
			return (box->error = -6);
		box->mapy++;
	}
	return (0);
}
