/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:14:02 by arykov            #+#    #+#             */
/*   Updated: 2018/11/30 14:21:16 by arykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include "SDL.h"
# include <pthread.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define WIND_W		1280
# define WIND_H		720
# define KEY_CODE	265

typedef struct		s_listparam
{
	double			x;
	double			y;
}					t_listparam;

typedef struct		s_intlparam
{
	int				x;
	int				y;
}					t_intlparam;

typedef struct		s_cam
{
	t_listparam		position;
	t_listparam		d;
	t_listparam		p;
}					t_cam;

typedef struct		s_pic
{
	int				ext;
	int				b;
	int				scale;
	SDL_Surface		*this_pic;
	SDL_Surface		*this_picm0;
	SDL_Surface		*this_picm1;
	SDL_Surface		*this_picm2;
	SDL_Surface		*this_picbm;
}					t_pic;

typedef struct		s_goparam
{
	double			rot_spd;
	float			spd;
	int				insky;
	int				tohell;
	int				west;
	int				south;
	float			lop;
}					t_goparam;

typedef struct		s_tir
{
	t_listparam		fold;
	t_intlparam		pl;
	t_intlparam		go;
	t_listparam		cast;
	t_listparam		cting;
}					t_tir;

typedef struct		s_block
{
	int				bs;
	double			bd;
	int				bh;
	int				bt;
	int				bb;
	double			btouch;
}					t_block;

typedef struct		s_box
{
	int				ttsky2;
	int				ttsky;
	int				sitd;
	int				tpos;
	int				atpos;
	SDL_Surface		*new_pic;
	SDL_Surface		*npd;
	int				npbpp;
	int				npsl;
	int				npend;
	int				map_fd;
	int				mapx;
	int				mapy;
	int				uselessy;
	int				**all_map;
	SDL_Window		*wind;
	SDL_Surface		*surf;
	int				start;
	int				error;
	double			scene;
	int				a;
	int				btpos;
	int				coloriz;
	t_pic			*pic;
	SDL_Surface		*txtrs[8];
	int				keys[KEY_CODE];
	t_cam			cam;
	t_goparam		go;
	t_tir			tir;
	t_block			block;
	t_goparam		ogo;
	t_intlparam		paramtext;
	int				exit;
}					t_box;

int					menu_mouse(int code, int x, int y, t_box *box);
int					exit_this(void);
void				all_destroy(t_box *box);
int					menu_keys(int code, t_box *box);
void				start_game(t_box *box, t_pic *pic, char *name);
int					main(void);
void				change_map(t_box *box);
int					open_map(t_box *box);
int					ft_check_all(t_box *box);
int					check_wrong(t_box *box);
int					check_c(char *str);
int					check_line(t_box *box);
int					check_map(t_box *box);
int					check_map_par(t_box *box, char *str, int i, int n);
void				error_msg(t_box *box);
void				some_pthreads(t_box *box);
void				*thi_is_raycast(void *box);
void				colorize_this(t_box *box);
void				lets_start_game(t_box *box);
void				add_textures(t_box *box);
void				for_cam(int code, t_box *box, int i);
void				for_go(int code, t_box *box, int i);
int					key_rele(int code, t_box *box);
int					key_push(t_box *box);
int					paint_this(t_box *box);
void				just_travel_s(t_box *box, double x, double y, double d_x, double d_y);
void				just_travel_w(t_box *box, double x, double y, double d_x, double d_y);
void				go_and_west(t_box *box, double x, double y, double p_x, double p_y);
void				some_rotation(t_box *box);
void				ttsky_and_sit(t_box *box);
void				this_is_castingray(t_box *box);
void				ray_start(t_box *box);
void				some_blocks(t_box *box);
void				add_txtrs(t_box *box, int x, int y);
void				print_walls(t_box *box);
void				up_and_down(t_box *box);
int					small_map(t_box *box);
int					menu_mouse_click(int x, int y, t_box *box);

#endif
