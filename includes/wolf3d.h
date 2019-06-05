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

# include "../libft/libft.h"
# include "SDL.h"
# include "SDL_image.h"
# include "SDL_ttf.h"
# include "SDL_mixer.h"
# include <pthread.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>

# define WIND_W		1280
# define WIND_H		720
# define KEY_CODE	265
# define INT_MAX	2147483647

typedef struct 		s_maps
{
	int 		l_f;
	int 		max_maps;
	int 		c_list;
	char 		**map_path;
	char 		**map_name;
}					t_maps;

typedef struct		s_rectItems
{
	SDL_Rect		rect_items;
}					t_rectItems;

typedef struct		s_bag
{
	SDL_Texture		*text_item;
	t_rectItems		rect[6];
	int 			items[6];
	SDL_Texture 	*Message;
	SDL_Texture 	*full_message;
	SDL_Rect 		Message_rect;
	int 			posX;
	int 			posY;
	int 			n_items;
	int				time;
}					t_bag;

typedef struct		s_drawSprite
{
	double 			spriteX;
	double 			spriteY;
	double 			invDet;
	double 			transformX;
	double 			transformY;
	int 			spriteScreenX;
	int 			spriteHeight;
	int 			drawStartY;
	int 			drawEndY;
	int 			spriteWidth;
	int 			drawStartX;
	int 			drawEndX;
	int 			i;
	int 			texX;
	int 			texY;
}					t_drawSprite;

typedef struct		s_spriteCord
{
	double			x;
	double			y;
	int 			n_text;
	int 			bag;
}					t_spriteCord;

typedef struct		s_sprite
{
	double			ZBuffer[1280];
	SDL_Surface		*tex_sprite[20];
	t_spriteCord 	spt[20];
	double			spriteDistance[20];
	int 			spriteOrder[20];
	int 			n_sprites;
}					t_sprite;

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
	double			bd;
	double			btouch;
	int				bs;
	int				bh;
	int				bt;
	int				bb;
}					t_block;

typedef struct		s_mouse 
{
	double			od_x;
	double			od_y;
	double			old_px;
	double			old_py;
	double			rot_spd;
	int				x;
	int				y;
	
}					t_mouse;

typedef	struct		s_face
{
	SDL_Surface		*face;
	SDL_Texture		*face_texture;
	SDL_Rect		rect_face;
	int				w_face;
	int				h_face;
	int				face_start;
}					t_face;

typedef struct		s_h_bar
{
	SDL_Surface		*heals;
	SDL_Texture		*heals_texture;
	SDL_Rect		rect_heals;
	int				w_heals;
	int				h_heals;
	int				hp_val;	
	int				n;
}					t_h_bar;

typedef struct		s_am_bar
{
	SDL_Surface		*ammo;
	SDL_Texture		*ammo_texture;
	SDL_Rect		rect_face;
	int				w_ammo;
	int				h_ammo;	
}					t_am_bar;


typedef struct		s_rad_bar
{
	SDL_Surface		*rad;
	SDL_Texture		*rad_texture;
	SDL_Rect		rect_rad;
	int				w_rad;
	int				h_rad;
	int				n;
	int				ticks;
}					t_rad_bar;

typedef struct 		s_weapon
{
	SDL_Surface		*weapon;
	SDL_Texture		*weapon_texture;
	SDL_Rect		rect_weapon;
	int				w_weapon;
	int				h_weapon;	
	int 			usless;
}					t_weapon;

typedef struct 		s_bar
{
	SDL_Rect		rect_bott_bar;
 	SDL_Surface		*bott_bar;
 	SDL_Texture		*bott_bar_texture;
 	SDL_Rect		rect_rad_bar;
	SDL_Surface		*rad_bar;
	SDL_Texture		*rad_bar_texture;
	int				w_rad_bar;
	int				h_rad_bar;
	
}					t_bar;

typedef struct 		s_hud
{
	t_bar			bar;
 	t_weapon		weapon[6];
 	t_face			face[3];
 	t_h_bar			heals[3];
 	t_rad_bar		rad[3];
	char			*numb[10];
	int				w_start;	
 	int				hp_val;
 	int				rad_val;	
	int				h_scope; //If delete - segment. fault
	int				hp_i;
	int				rad_i;
	int             fire;
	int				time;
	int				w_time;
}					t_hud;

typedef struct 		s_music
{
	Mix_Music	*bgm;
	Mix_Music	*bgm_menu;
	Mix_Music	*dead_sound;
	Mix_Chunk	*rad;
	Mix_Chunk	*walk;
	Mix_Chunk	*knife;
	Mix_Chunk	*jet;
	int			walking;
	
}					t_music;

typedef struct		s_box
{
	t_sprite 		sprites;
	int				keys[KEY_CODE];
	t_hud			hud;
	t_bag 			bag;
	SDL_Surface		*txtrs[13];
	SDL_Texture		*menu_txtrs[10];
	t_drawSprite	dsprite;
	t_music			music;
	t_tir			tir;
	t_cam			cam;
	t_mouse			mouse;
	t_maps			map_list;
	t_block			block;
	t_goparam		go;
	t_goparam		ogo;
	t_intlparam		paramtext;
	t_pic			*pic;
	SDL_Window		*wind;
	SDL_Texture		*texture;
	SDL_Texture		*main_t;
	SDL_Texture		*this_txtr;
	SDL_Renderer	*rend;
	double			dist;
	double			tmp_dist;
	double			floor_x;
	double			floor_y;
	double			light_power;
	double			scene;
	Uint32			*pixels;
	int				**all_map;
	Uint32			sleep;
	int				blok;
	int				num_face;
	int				mirror_effect;
	int				no_shadow;
	int				x_t;
	int				tex_floor_x;
	int				tex_floor_y;
	int				ttsky2;
	int				ttsky;
	int				sitd;
	int				tpos;
	int				atpos;
	int				map_fd;
	int				mapx;
	int				mapy;
	int				uselessy;
	int				start;
	int				error;
	int				a;
	int				btpos;
	int				face_start;
	int				sky;
	int				dead;
	int				fly_mode;
}					t_box;

int					hooks(t_box *box);
SDL_Surface			*load_texture(char *path, t_box *wolf);
void				load_menu_txtrs(t_box *box);
SDL_Texture			*menu_png(char *text, t_box *box);
void				all_destroy(t_box *box);
void				start_game(t_box *box);
void				fatal_error(int er, t_box *box);
int					main(void);
void				change_map(t_box *box);
int					open_map(t_box *box);
int					ft_check_all(t_box *box);
int					check_wrong(t_box *box);
int					check_c(char *str);
int					check_line(t_box *box);
int					check_map(t_box *box);
int					check_map_par(t_box *box, char *str, int i, int n);
void				some_pthreads(t_box *box);
void				*thi_is_raycast(void *box);
void				lets_start_game(t_box *box);
void				load_wall_textures(t_box *box);
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
//// mouse scope && HUD
void				ft_check_walk(t_box *box);
void				ft_dead(t_box *box);
void				ft_init_music(t_box *box);
int					mouse_control(int x, int y, t_box *box);
int					ft_scope(t_box *box);
SDL_Surface			*ft_check_png(t_box *box, char *text);
int					ft_hud(t_box *box);
int					ft_hud_bar(t_box *box);
int					ft_all_bars(t_box *box);
void				ft_load_hud_tex(t_box *box);
void				ft_music_free(t_box *box);
void				ft_hud_param(t_box *box);
void				paint_hud(t_box *box);
void				ft_shooting(int code, t_box *box);
void				ft_freee(t_box *box);
void				ft_r_bars_face(t_box *box);
void				ft_start_anim(t_box *box);
void				ft_knife_sh(t_box *box);
void				ft_lets_music(t_box *box);
void				ApplyTexture(int x, int y, t_box *box);
void 				if_b_or_n(t_box *box, int x, int y, int *z, int *c);
void				show_map_name(t_box *box, int c, int z);
void				ifc_map_name(t_box *box, int c, int z);
void				ifp_map_name(t_box *box, int c, int z);
void				ifcnp_map_name(t_box *box, int c, int z);
void 				load_maps(t_maps *m_l);
///
/* sprite */
void 				ft_my_swap1(t_box *box, int i, int j);
void 				ft_my_swap2(t_box *box, int i, int j);
void 				combSort(t_box *box, int amount);
Uint32				get_pixel(t_box *box, SDL_Surface *surface, int x, int y);
void 				sort_sprits(t_box *box);
void        		add_sprite(t_box *box, int n, int x, int y);
void				draw_sprites(t_box *box);
void    			draw_sprites2(t_box *box);
void    			draw_sprites3(t_box *box);
void    			draw_sprites4(t_box *box);
/* !sprite */

/////////////////////////////
void	fly_mode_on(t_box *box);
////////////////////////////
int 	takeSprite(t_box *box, double x, double y, double d_x, double d_y);
SDL_Texture* renderText(char *message, char *fontFile, SDL_Color color, int fontSize,
					SDL_Renderer *renderer);
void ApplySurface(int x, int y, int w, int h, SDL_Texture *tex, SDL_Renderer *rend);

#endif
