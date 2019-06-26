/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:23:35 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/19 14:23:36 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doomnukem.h"

int					ft_chek_dfile(char *str, char *f)
{
	int				i;
	int				c;

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

char				*add_map_name(char *str)
{
	char			*name;
	int				i;
	int				j;

	i = ft_strlen(str) - 4;
	if (i > 7)
		i = 9;
	name = (char *)malloc(sizeof(char) * (i + 1));
	j = 0;
	while (str[j] != '.' && j <= 6)
	{
		name[j] = str[j];
		j++;
	}
	if (i == 9)
	{
		name[7] = '.';
		name[8] = '.';
		name[9] = '.';
		j = 10;
	}
	name[j] = '\0';
	return (name);
}

int					check_input_map(struct dirent *dp, t_maps *m_l, int j)
{
	int				i;

	if (ft_chek_dfile(dp->d_name, ".map") == 1)
	{
		i = ft_strlen(dp->d_name);
		m_l->map_name[j] = add_map_name(dp->d_name);
		i += ft_strlen("maps/");
		m_l->map_path[j] = (char *)malloc(sizeof(char) * i);
		m_l->map_path[j] = ft_strcat(m_l->map_path[j], "maps/");
		m_l->map_path[j] = ft_strcat(m_l->map_path[j], dp->d_name);
		j++;
	}
	return (j);
}

void				load_maps(t_maps *m_l, int i)
{
	int				j;
	int				fddir;
	struct dirent	*dp;
	DIR				*dfd;

	j = 0;
	fddir = open("maps", O_DIRECTORY);
	if (fddir == -1)
		ft_putendl("Map dir NotFound");
	dfd = opendir("maps");
	while ((dp = readdir(dfd)) != NULL)
	{
		if (ft_chek_dfile(dp->d_name, ".map") == 1)
			i++;
	}
	m_l->max_maps = i - 1;
	rewinddir(dfd);
	m_l->map_path = (char **)malloc(sizeof(char *) * (i + 1));
	m_l->map_name = (char **)malloc(sizeof(char *) * (i + 1));
	while ((dp = readdir(dfd)) != NULL)
		j = check_input_map(dp, m_l, j);
	closedir(dfd);
	close(fddir);
}

void				show_map_name(t_box *box, t_arg *arg, int ch)
{
	int				y;
	SDL_Texture		*pic;

	y = 304;
	while ((ch + box->map_list.c_list - 1) <= box->map_list.max_maps && ch <= 6)
	{
		if (arg->z != ch && arg->c != ch)
		{
			pic = render_text_blue(box->map_list.map_name[ch +
				box->map_list.c_list - 1], "ttf/mainfont.ttf", 35, box->rend);
			apply_menu_surface(944, y, pic, box->rend);
			y += 54;
			ch++;
		}
		else
		{
			y += 54;
			ch++;
		}
	}
	if ((ch + box->map_list.c_list - 1) == (box->map_list.max_maps + 1))
		box->map_list.l_f = 1;
	else
		box->map_list.l_f = 0;
}
