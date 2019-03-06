#include "wolf3d.h"

void	add_resources(t_box *box)
{
	int er;

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		fatal_error(1, box);
	if ((box->wind = SDL_CreateWindow("Doom Nukem", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WIND_W, WIND_H, SDL_WINDOW_SHOWN)) == NULL)
		fatal_error(2, box);
	if ((box->renderer = SDL_CreateRenderer(box->wind, -1, SDL_RENDERER_ACCELERATED |
										SDL_RENDERER_PRESENTVSYNC)) == NULL)
		fatal_error(3, box);
	if (TTF_Init() != 0)
		fatal_error(4, box);
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
		fatal_error(4, box);
	add_textures_and_mapl(&box);
	if ((er = find_tx("sys_txerr.png", box->alltxtr)) == -2)
		fatal_error(6, box);
	er = ft_chek_sys(box->images);
	if (er != 0)
		fatal_error(6, box);
	else
		printf("All system img was found\n");
}

int find_tx(char *name, char **list)
{
	int i;

	i = 0;
	while (list[i])
	{
		if (ft_strcmp(name, list[i]) == 0)
			return (i);
		i++;
	}
	//printf("name  = %s list = %s i = %d\n", name, list[i], i);
	return (-2);
}

int ft_chek_sys(t_texture *t)
{
	int arry[9] = {8, 7, 6, 5, 4, 3, 2, 1, 0};
	int i;
	t_texture *buf;

	i = 0;
	buf = t;
	if (buf == NULL)
		return(-1);
	while (arry[i] == buf->code)
	{
		//printf("arry = %d buf->code = %d\n", arry[i], buf->code);
		if (buf->next == NULL)
			break;
		i++;
		buf = buf->next;
	}
	if (arry[i] == buf->code)
		return(0);
	return (-1);
}

int	ft_chek_dfile(char *str, char *f)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (str[i++] != '\0')
		;
	if (i <= 5 || str[0] == '.')
		return (0);
	i -= 5;
	while (str[i++] == f[c++] && str[i] != '\0')
		;
	if (c != 4)
		return (0);
	return (1);
}

int	ft_chek_tfile(char *str)
{
	int i;

	i = 0;
	if (ft_strcmp("sys_txerr.png", str) == 0)
		return (3);
	if (str[i] == 't')
		if (str[++i] == 'x')
			if (str[++i] == '_')
				return (1);
	if (str[i] == 's')
		if (str[++i] == 'y')
			if (str[++i] == 's')
				if (str[++i] == '_')
					if (ft_isdigit(str[++i]) == 1)
						return(2);
	return(0);
}

int how_many_files(DIR *dfd, char *f)
{
	int x;
	int i;
	struct dirent *dp;

	i = 0;
	x = 0;
	while((dp = readdir(dfd)) != NULL)
		if (ft_chek_dfile(dp->d_name, f) != 0)
		{
			if ((x = ft_chek_tfile(dp->d_name)) == 1 || x == 2 || x == 3)
				i++;
			if (f[1] == 'm')
				i++;
		}
	rewinddir(dfd);
	return (i);
}

char	**add_map_to_list(DIR *dfd, int x)
{
	int i;
	char			**list;
	struct dirent	*dp;

	i = 0;
	list = (char **)malloc(sizeof(char *) * x + 1);
	while((dp = readdir(dfd)) != NULL)
		if (ft_chek_dfile(dp->d_name, ".map") == 1)
			list[i++] = ft_strjoin("maps/", dp->d_name);
	closedir(dfd);
	list[i] = NULL;
	return (list);
}

void	add_textures_and_mapl(t_box **box)
{
	int x;
	int				fddir;
	DIR				*dfd;
	struct dirent	*dp;

	fddir = open("txtrs", O_DIRECTORY);
	if (fddir < 0)
		fatal_error(5, *box);
	dfd = opendir("txtrs");
	x = how_many_files(dfd, ".png");
	(*box)->alltxtr = (char **)malloc(sizeof(char*) * x);
	while((dp = readdir(dfd)) != NULL)
		if (ft_chek_dfile(dp->d_name, ".png") != 0)
			if ((fddir = ft_chek_tfile(dp->d_name)) == 1 || fddir == 2 || fddir == 3)
				Loadtxtr(&box, dp->d_name, fddir);
	closedir(dfd);
	fddir = open("maps", O_DIRECTORY);
	if (fddir < 0)
		fatal_error(5, *box);
	dfd = opendir("maps");
	x = how_many_files(dfd, ".map");
	if (x == 0)
		x = 1;
	(*box)->maplist = add_map_to_list(dfd, x);
}
