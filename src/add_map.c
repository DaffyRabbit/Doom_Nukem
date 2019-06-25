#include "gen.h"

void	generation_map(t_gen *gen, char *x, char *y)
{
	int i;
	char *path;
	int mx;
	int my;

	mx = ft_atoi(x);
	my = ft_atoi(y);
	i = 0;
	if (mx < 5)
	{
		ft_putendl("Param\"X\" too small(min 5)");
		mx = 5;
	}
	if (mx > 200)
	{
		ft_putendl("Param\"X\" too big(max 200)");
		mx = 200;
	}
	if (my < 5)
	{
		ft_putendl("Param\"Y\" too small(min 5)");
		my = 5;
	}
	if (my > 200)
	{
		ft_putendl("Param\"Y\" too big(max 200)");
		my = 200;
	}
	path = ft_strjoin(ft_strjoin("maps/map", ft_itoa(i)), ".map");
	gen->allmap->fd = open(path, O_RDONLY);
	while (gen->allmap->fd != -1)
	{
		i++;
		if (i > 250)
		{
			ft_putendl("You created max maps already!");
			ft_bb(gen);
		}
		free(path);
		path = ft_strjoin(ft_strjoin("maps/map", ft_itoa(i)), ".map");
		gen->allmap->fd = open(path, O_RDONLY);
	};
	gen->allmap->map_name = ft_strdup(path);
	free(path);
	path = ft_strjoin("Created new map with name ", gen->allmap->map_name);
	ft_putendl(path);
	free(path);
	gen->allmap->x = mx;
	gen->allmap->y = my;
	i = 0;
	gen->allmap->map = (int **)malloc(sizeof(int *) * gen->allmap->x + 1);
	gen->allmap->event_id = (int **)malloc(sizeof(int *) * gen->allmap->x + 1);
	while (gen->allmap->x >= i)
	{
		gen->allmap->map[i] = (int *)malloc(sizeof(int) * gen->allmap->y + 1);
		gen->allmap->event_id[i] = (int *)malloc(sizeof(int) * gen->allmap->y + 1);
		i++;
	}
	my = 0;
	while (gen->allmap->y >= my)
	{
		mx = 0;
		while (gen->allmap->x >= mx)
		{
			gen->allmap->map[mx][my] = 1;
			gen->allmap->event_id[mx][my] = 0;
			mx++;
		}
		my++;
	}
}

int write_this (t_gen *gen, char *path)
{
	int res;
	int x;
	int y;
	int fd;
	
	y = 0;
	if (gen->allmap->fd < 0)
	{
		gen->allmap->fd = open(gen->allmap->map_name, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
		close(gen->allmap->fd);
	}
	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC | O_NOFOLLOW);
	while (gen->allmap->y > y)
	{
		x = 0;
		while (gen->allmap->x > x)
		{
			if (gen->allmap->map[x][y] == 999)
				res = 999;
			if (gen->allmap->map[x][y] == 1 || gen->allmap->map[x][y] == 25)
				res = gen->allmap->map[x][y] + gen->allmap->event_id[x][y];
			if (gen->allmap->map[x][y] == 34)
				res = 34;
			ft_putstr_fd(ft_itoa(res), fd);
			ft_putchar_fd(' ', fd);
			x++;
		}
		ft_putchar_fd('\n', fd);
		y++;
	}
	return (1);
}

void	save_this(t_gen *gen, t_el_key *b, SDL_MouseButtonEvent ev)
{

	(void)ev;
	b->is_disabled = 1;
	ft_putendl(ft_strjoin("Saving file in ", gen->allmap->map_name));
	write_this(gen, gen->allmap->map_name);
	b->is_disabled = 0;
}

void	print_map(t_gen *gen)
{
	int res;
	int x;
	int y;

	y = 0;
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
			ft_putstr(ft_itoa(res));
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	ft_putchar('\n');
}

int		chek_num(char *str, int x, int y, t_gen *gen)
{
	int i;
	int res;

	i = 1;
	res = 0;
	if (ft_isdigit(str[0]) == 0)
			return(-1);
	res += str[0] - 48;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return(-1);
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	if (res >= 0 && res <= 9)
	{
		gen->allmap->map[x][y] = 1;
		if (res != 0)
			gen->allmap->event_id[x][y] = res - 1;
		else
			gen->allmap->event_id[x][y] = res;
		return (0);
	}
	if (res == 999)
	{
		gen->allmap->map[x][y] = 999;
		gen->allmap->event_id[x][y] = 0;
		return (0);
	}
	if (res >= 25 && res <= 32)
	{
		gen->allmap->map[x][y] = 25;
		gen->allmap->event_id[x][y] = res - 25;
		return (0);
	}
	if (res == 34)
	{
		gen->allmap->map[x][y] = 34;
		gen->allmap->event_id[x][y] = 34;
		return (0);
	}
	return (-1);
}

void	add_map2(t_gen *gen)
{
	int i;
	int j;
	char *line;
	char **str_map;

	i = 0;
	j = 0;
	gen->allmap->fd = open(gen->allmap->map_name, O_RDONLY);
	gen->allmap->map = (int **)malloc(sizeof(int *) * gen->allmap->x + 1);
	gen->allmap->event_id = (int **)malloc(sizeof(int *) * gen->allmap->x + 1);
	while (gen->allmap->x >= i)
	{
		gen->allmap->map[i] = (int *)malloc(sizeof(int) * gen->allmap->y + 1);
		gen->allmap->event_id[i] = (int *)malloc(sizeof(int) * gen->allmap->y + 1);
		i++;
	}
	while (get_next_line(gen->allmap->fd, &line) > 0)
	{
		i = 0;
		str_map = ft_strsplit(line, ' ');
		while (str_map[i])
		{
			if(chek_num(str_map[i], i, j, gen) == -1)
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
	close(gen->allmap->fd);
	print_map(gen);
}

void	add_map(t_gen *gen)
{
	int i;
	int j;
	char **str_map;
	char *line;

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
	if (gen->allmap->y < 5 || gen->allmap->y > 200 || gen->allmap->x < 5 || gen->allmap->x > 200)
	{
		ft_putendl("Map too big/small!!!");
		ft_bb(gen);
	}
	close(gen->allmap->fd);
	add_map2(gen);
}