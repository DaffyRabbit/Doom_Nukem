/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:50:44 by rhusak            #+#    #+#             */
/*   Updated: 2019/06/25 22:50:46 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEN_H
# define GEN_H

# include <stdio.h>
# include "../../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <time.h>
# include <SDL2/SDL.h>
# include <SDL2_ttf/SDL_ttf.h>
# include <SDL2_image/SDL_image.h>

# define WIN_W 1280
# define WIN_H 720

typedef struct s_gen	t_gen;

typedef struct			s_lbox
{
	void				(*add)(struct s_lbox *l, void *cont);
	void				(*remove)(struct s_lbox *l, t_list *element);
	int					(*size)(struct s_lbox *list_container);
	int					(*fastsize)(struct s_lbox *list_container);
	void				(*reindex)(struct s_lbox *list_container);
	t_list				*prev;
	t_list				*next;
}						t_lbox;

typedef struct			s_strc_type
{
	int					tool_t;
}						t_strc_type;

typedef struct			s_uid
{
	int					id;
	int					uiw;
	int					uih;
	int					uix;
	int					uiy;
}						t_uid;

typedef struct			s_echb
{
	int					checked;
	int					disabled;
	t_uid				*pn;
	SDL_Color			color;
	SDL_Rect			pos;
	SDL_Color			background;
	SDL_Color			falsc;
	SDL_Color			border;
}						t_echb;

typedef struct			s_text_element
{
	t_uid				*pn;
	SDL_Surface			*surface;
	SDL_Rect			rect;
	TTF_Font			*font;
	SDL_Color			text_color;
	int					list_id;
	char				*text;
	int					weighu;
	int					heighu;
}						t_el_text;

typedef struct			s_el_key
{
	t_uid				*pn;
	void				(*pn_callback)(t_gen *gen,
						struct s_el_key *b,
						SDL_MouseButtonEvent event);
	SDL_Color			background_color;
	SDL_Color			background_color_disabled;
	t_el_text			*text;
	SDL_Rect			rect;
	int					is_disabled;
	int					is_visible;
	int					real_x;
	int					real_y;
}						t_el_key;

typedef struct			s_map_box
{
	char				*map_name;
	int					**map;
	int					**event_id;
	int					x;
	int					y;
	int					fd;
}						t_map_box;

typedef struct			s_font
{
	TTF_Font			*font;
	int					size;
	char				*font_path;
}						t_font;

enum					e_toll_code
{
	event_tool = 1,
	wall_tool = 25,
	door_tool = 34,
	startpoint_tool = 999,
	repeat_tool = 5,
};

typedef struct			s_w_strc
{
	int					min;
	int					max;
	int					is_focused;
	int					value;
	int					step;
	t_uid				*pn;
	t_el_text			*txt;
	SDL_Rect			pos;
	SDL_Color			background;
	SDL_Color			border;
	SDL_Color			color;
	char				*unit;
}						t_w_strc;

typedef struct			s_tool_t
{
	char				*tool_id;
	Uint32				tool_c;
	int					tool_index;
}						t_tool_t;

typedef struct			s_ren_params
{
	int					cam_scale;
	int					def_x;
	int					def_y;
	int					pos_x;
	int					pos_y;
	t_w_strc			*this_ind;
	t_w_strc			*h_s;
	t_w_strc			*ge_s;
	t_w_strc			*ge_h;
	t_echb				*param1;
	t_echb				*param2;
	t_echb				*param_3;
}						t_ren_params;

typedef struct			s_special
{
	int					bonus_param;
}						t_special;

typedef struct			s_spec_2
{
	int					bonus_col;
	int					bonus_ob;
}						t_spec_2;

typedef struct			s_generator
{
	SDL_Surface			*surf_gen;
	int					x_gen;
	int					y_gen;
	int					w_gen;
	int					h_gen;
	int					cuter_s;
	int					w_spec;
	int					h_spec;
	SDL_Surface			*this_el_par;
	SDL_Rect			r;
	t_ren_params		qua;
	SDL_Surface			*gen_s;
	SDL_Rect			gen_r;
	t_ren_params		gen_qua;
	SDL_Surface			*more_surf;
	SDL_Rect			more_r;
	t_ren_params		more_qua;
	int					third_m_click;
	int					separator;
	int					anim_w;
	int					anim_h;
	Uint8				anim_alpha;
	t_el_key			*tool_block;
	int					hand_tool;
	t_tool_t			*selected_block;
	t_el_text			*current_tool;
	t_el_text			*str_tool;
	int					c_focus;
	int					x_focus;
	int					y_focus;
	t_special			foc;
	t_spec_2			foc_s;
	SDL_Color			base_color;
	SDL_Color			select_color;
	t_el_key			*save;
	int					is_clicking;
	t_lbox				*l_textures;
}						t_generator;

struct					s_gen
{
	int					mx;
	int					my;
	t_map_box			*allmap;
	int					eve_id;
	int					eve_id_scale;
	char				*selected_block;
	SDL_Window			*win;
	SDL_Renderer		*rend;
	SDL_Event			last_event;
	SDL_Surface			*surface;
	Uint32				*s_pixels;
	t_lbox				*events;
	Uint32				last_frame;
	int					original_mode;
	int					game_mode;
	t_lbox				*fonts;
	t_lbox				*texts;
	int					ui_ids;
	t_el_text			*fps_counter;
	t_el_text			*easter_egg;
	int					average_fps;
	t_generator			generus;
	t_lbox				*buttons;
	int					temp_color;
	SDL_Color			tmp_color;
	int					texture_amount;
	int					mouse_focused;
	int					game_init;
	int					m_x;
	int					m_y;
	t_lbox				*toll_code;
	t_lbox				*sprite_types;
};

typedef struct			s_registered_event
{
	Uint32				type;
	int					gamemode;
	int					(*handler)(t_gen *gen, SDL_Event ev);
}						t_registered_event;

enum					e_tools
{
	tool_none = 0,
	tool_block = 1,
	tool_textures = 2,
	tool_sprite = 3,
};

int						main(int argc, char **argv);
void					ft_lstdelone_alt(t_list *el);
void					print_map(t_gen *gen, int y, int x, int res);
int						chek_num(char *str, int x, int y, t_gen *gen);
void					add_map2(t_gen *gen);
void					add_map(t_gen *gen);
t_el_key				*add_new_b(t_gen *gen, char *string, SDL_Rect rect,
						void (*pn_callback)(t_gen *gen,
						t_el_key *b, SDL_MouseButtonEvent event));
void					key_parameters(t_gen *gen, t_el_key *button);
t_w_strc				*new_bucket(t_gen *gen, SDL_Rect rc, SDL_Rect mmvs);
void					up_bucket(t_gen *gen, t_w_strc *jg);
void					af_up_bucket(t_gen *gen,
						t_w_strc *jg, int change, int prepare);
void					com_bucket(t_gen *gen,
						t_w_strc *jg, int value, int prepare);
t_echb					*gen_help(t_gen *gen, SDL_Rect pos, int checked);
void					ren_gen_help(t_gen *gen, SDL_Surface *s, t_echb *ck);
void					re_text(t_gen *gen,
						SDL_Surface *surface, t_el_text *text);
void					tx_pre(t_gen *gen,
						t_el_text *text, int mk_size, int cent);
void					take_new_tool(t_gen *gen, int to_tool);
Uint32					c_in_u(SDL_Color color);
int						where_m(int m_x, int m_y, SDL_Rect rect);
int						lcm(void);
int						lrm(void);
SDL_Rect				m_trak(void);
void					i_need_tx(t_gen *gen,
						SDL_Surface *s, char *st, SDL_Rect poscols);
void					load_new_ev(t_gen *gen);
void					del_ev(t_gen *gen, SDL_Event sdl_event);
void					init_all(t_gen *gen);
TTF_Font				*gen_ttf(t_gen *gen, char *font_path, int size);
void					load_ttf(t_gen *gen);
void					del_ttf(t_gen *gen);
t_tool_t				*new_tool_t(t_gen *gen, char *bn, Uint32 bc, int bt);
void					load_some_code(t_gen *gen);
void					check_ev(t_gen *gen, Uint32 type,
						int (*handler)(t_gen *gen, SDL_Event ev));
void					load_ev(t_gen *gen);
SDL_Rect				new_sdlrect(int x, int y, int width, int height);
void					paint_r(SDL_Surface *s, SDL_Rect rect, SDL_Color color,
																int fill_rect);
void					paint_r_2(SDL_Surface *s, SDL_Rect rect, Uint32 color,
						int fill_rect);
SDL_Color				new_rgb_mask(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
t_el_text				*add_tx(t_gen *gen,
						char *string, char *font_path, int size);
void					load_generus_pls(t_gen *gen);
void					some_usful_ft(t_gen *gen,
						t_el_key *b, SDL_MouseButtonEvent ev);
void					add_to_surf(t_gen *gen,
						SDL_Event event, SDL_MouseButtonEvent ms);
int						scan_m_surf(t_gen *gen, SDL_Event event);
int						scan_mb_surf(t_gen *gen, SDL_Event event);
int						scan_mw_surf(t_gen *gen, SDL_Event event);
int						push_keys(t_gen *gen, SDL_Event sdl_event);
int						m_param_1(t_gen *gen, SDL_Event sdl_event);
int						m_param_2(t_gen *gen, SDL_Event sdl_event);
int						gen_scale_map(t_gen *gen, SDL_Event sdl_event);
int						this_is_end(t_gen *gen, SDL_Event sdl_event);
int						params_keys(t_gen *gen, SDL_Event sdl_event);
t_lbox					*lbox_new(void);
void					lbox_add(t_lbox *container, void *content);
void					show_k_for_me(t_gen *gen, SDL_Surface *surface,
													t_el_key *button);
void					all_s(t_gen *gen);
void					update_all_tools(t_gen *gen);
void					this_generus_2(t_gen *gen);
void					this_generus(t_gen *gen);
void					loop_gen(t_gen *gen);
void					last_up_tool(t_gen *gen, t_list *tmp, int x, int y);
void					repeat_tool_t(t_gen *gen,
						t_tool_t *type, t_strc_type *blk);
void					take_tool_t(t_gen *gen, t_tool_t *type);
void					something_new(t_gen *gen);
void					for_one_time(t_strc_type *dest,
						t_strc_type *src, int free2);
void					reset_tt(t_strc_type *dest);
void					gen_update_surf(t_gen *gen);
void					chek_gen_surf(t_gen *gen, t_ren_params *qr,
						SDL_MouseWheelEvent wheel, SDL_Rect rc);
void					end_gen_rend(t_gen *gen,
						int x, SDL_Rect r, t_ren_params *q);
void					key_inp_par(t_gen *gen);
void					key_ch_par(t_gen *gen);
void					*maloc_alt(size_t size);
void					lbox_remove(t_lbox *l, t_list *element);
int						lbox_size(t_lbox *list_container);
int						lbox_fastsize(t_lbox *container);
void					lbox_reindex(t_lbox *container);
t_list					*ft_lstnew_alt(void *content);
t_list					*ft_lstadd_alt(t_list *listelement, t_list *newelement);
int						where_b(t_el_key *button, int x, int y);
void					updait_b(t_el_key *but, int x, int y);
void					ft_lstdel_alt(t_list *lst, int free_content);
t_list					*ft_lstgetfirst(t_list *lst);
int						r_a_i(int r, int g, int b, int a);
t_uid					*get_new_uid(t_gen *gen);
int						ts(t_el_text *text);
void					editor_win_param(t_gen *gen);
void					save_this(t_gen *gen,
						t_el_key *b, SDL_MouseButtonEvent ev);
char					*ft_strjoin_alt(char const *s1,
						char const *s2, size_t free_level);
void					how_b_look_like(t_gen *gen, int tool);
int						wery_i_f(t_gen *gen);
void					gen_show_this_for_me(t_gen *gen, t_generator *e);
t_tool_t				*tool_t(t_gen *gen, int bt);
void					free_alt(void *ptr);
void					generation_map(t_gen *gen, char *x, char *y);
void					ft_bb(t_gen *gen);
void					malloc_map(t_gen *gen);
void					gnl_loop(t_gen *gen);
void					second_malloc(t_gen *gen, int i);
int						chek_num_sec_check(t_gen *gen, int res, int x, int y);
int						chek_num_check(t_gen *gen, int res, int x, int y);

#endif
