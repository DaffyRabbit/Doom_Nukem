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
# include "SDL_ttf.h"
# include "SDL_mixer.h"
# include "SDL_image.h"
# include <pthread.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
// WARNING
# include <stdio.h>
# include <dirent.h>

# define WIND_W		1280
# define WIND_H		720

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

typedef struct		s_goparam
{
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

typedef struct		s_texture
{
	int 				code;
	Uint32				*pixels;
	int w;
	int h;
	int pitch;
	SDL_Texture 		*img;
	struct s_texture	*next;
}					t_texture;

typedef struct		s_box
{
	char			*ch_map;
	char			**maplist;
	char			**alltxtr;
	t_texture		*txtr;
	t_texture		this_txtr;
	t_texture		*images;
	SDL_Renderer 	*renderer;
	int				ttsky2;
	int				ttsky;
	int				sitd;
	int				tpos;
	int				atpos;
	SDL_Surface		*npd;
	int				npbpp;
	int				npsl;
	int				npend;
	int				map_fd;
	int				mapx;
	int				mapy;
	int				uselessy;
	int				**all_map;
	SDL_Event		event;
	SDL_Window		*wind;
	// на скільки я зрозумів він не потрібен >WARNINGS<
	SDL_Surface		*surf;
	int				error;
	double			scene;
	int				a;
	int				btpos;
	int				coloriz;
	t_cam			cam;
	t_goparam		go;
	t_tir			tir;
	t_block			block;
	t_goparam		ogo;
	t_intlparam		paramtext;
	int				exit;
}					t_box;

void ApplyTexture(int x, int y, t_box *box);
void chose_map(int x, int y, int *z, int *c, int f);
int  add_map_list(t_box **box, int l, int z, int c);
void Loadtxtr(t_box ***box, char *file, int f);
int finde_slote(t_box *t);
int ft_syscode(char *file);
char	*add_name(char *file, char f);
t_texture findeimg(int c, t_texture *txtr);
SDL_Texture* renderText(char *message, char *fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer);
SDL_Texture* LoadImage(char *file, t_box *box, t_texture **new_txtr);
void ApplySurface(int x, int y, int w, int h, SDL_Texture *tex, SDL_Renderer *rend);
void	add_textures_and_mapl(t_box **box);
char	**add_map_to_list(DIR *dfd, int x);
int how_many_files(DIR *dfd, char *f);
int	ft_chek_tfile(char *str);
int ft_chek_sys(t_texture *t);
int find_tx(char *name, char **list);
void	add_resources(t_box *box);
void	fatal_error(int er, t_box *box);
void	add_menu(t_box *box);
int					exit_this(void);
void				all_destroy(t_box *box);
int					menu_keys(int code, t_box *box);
int					main(void);
void					open_map(t_box *box);
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
void				for_cam(int code, t_box *box, int i);
void				for_go(int code, t_box *box, int i);
int					key_rele(int code, t_box *box);
int					key_push(int code, t_box *box);
int					paint_this(t_box *box);
void				just_travel(t_box *box);
void				go_and_west(t_box *box);
void				some_rotation(t_box *box);
void				ttsky_and_sit(t_box *box);
void				this_is_castingray(t_box *box);
void				ray_start(t_box *box);
void				some_blocks(t_box *box);
void				add_txtrs(t_box *box, int x, int y);
void				print_walls(t_box *box);
void				up_and_down(t_box *box);
int					small_map(t_box *box);

#endif
