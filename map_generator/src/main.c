/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:13:31 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/25 19:13:32 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gen.h"

int			this_map_or_not(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	i--;
	if (str[i--] == 'p')
		if (str[i--] == 'a')
			if (str[i--] == 'm')
				if (str[i--] == '.')
					return (0);
	return (-1);
}

int			argv_3(char **argv)
{
	int		i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (ft_isdigit(argv[1][i]) == 1)
			i++;
		else
		{
			ft_putendl("Wrong Param \"X\"!!!");
			return (-1);
		}
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		if (ft_isdigit(argv[2][i]) == 1)
			i++;
		else
		{
			ft_putendl("Wrong Param \"Y\"!!!");
			return (-1);
		}
	}
	return (0);
}

void		argv_2(t_gen *m, char **argv)
{
	if (this_map_or_not(argv[1]) != 0)
	{
		ft_putendl("Wrong param!");
		ft_bb(m);
	}
	m->allmap->map_name = ft_strdup(argv[1]);
	m->allmap->fd = open(m->allmap->map_name, O_RDONLY);
	if (m->allmap->fd < 0)
	{
		ft_putendl("Map not found!");
		ft_bb(m);
	}
}

void		init_params(t_gen *m, char **argv, int argc)
{
	init_all(m);
	load_some_code(m);
	m->selected_block = ft_strdup("none");
	m->buttons = lbox_new();
	m->ui_ids = 1;
	m->events = lbox_new();
	load_ttf(m);
	m->surface = SDL_GetWindowSurface(m->win);
	m->s_pixels = m->surface->pixels;
	m->allmap->y = 0;
	m->allmap->x = 0;
	m->eve_id = 0;
	m->eve_id_scale = 1;
	if (argc == 2)
		add_map(m);
	else
		generation_map(m, argv[1], argv[2]);
	load_generus_pls(m);
	loop_gen(m);
}

int			main(int argc, char **argv)
{
	t_gen	m;
	int		a;

	if (argc == 1 || argc > 3)
	{
		ft_putendl("./generator [map_name or map params(x y)]");
		return (0);
	}
	if (argc == 3)
	{
		if ((a = argv_3(argv)) == -1)
			return (0);
	}
	m.allmap = (t_map_box *)malloc(sizeof(t_map_box));
	if (argc == 2)
		argv_2(&m, argv);
	init_params(&m, argv, argc);
	return (0);
}
