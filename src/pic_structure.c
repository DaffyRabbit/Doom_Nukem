/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic_structure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 12:53:37 by aperesad          #+#    #+#             */
/*   Updated: 2019/06/20 12:53:38 by aperesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				load_menu_txtrs(t_box *box)
{
	box->menu_txtrs[0] = menu_png("txtrs/sys_0_fon.png", box);
	box->menu_txtrs[1] = menu_png("txtrs/sys_1_bunch.png", box);
	box->menu_txtrs[2] = menu_png("txtrs/sys_2_bch.png", box);
	box->menu_txtrs[3] = menu_png("txtrs/sys_3_nunch.png", box);
	box->menu_txtrs[4] = menu_png("txtrs/sys_4_nch.png", box);
	box->menu_txtrs[5] = menu_png("txtrs/sys_5_start.png", box);
	box->menu_txtrs[6] = menu_png("txtrs/sys_6_create.png", box);
	box->menu_txtrs[7] = menu_png("txtrs/sys_7_exit.png", box);
	box->menu_txtrs[8] = menu_png("txtrs/sys_8_exit.png", box);
	box->menu_txtrs[9] = menu_png("txtrs/sys_txerr.png", box);
}

void				sprites_loader(t_box *box)
{
	box->sprites.tex_sprite[0] = IMG_Load("txtrs/acid_barel.png");
	box->sprites.tex_sprite[1] = IMG_Load("txtrs/acid.png");
	box->sprites.tex_sprite[2] = IMG_Load("txtrs/lamp.png");
	box->sprites.tex_sprite[3] = IMG_Load("txtrs/table-chairs.png");
	box->sprites.tex_sprite[4] = IMG_Load("txtrs/keys.png");
	box->sprites.tex_sprite[5] = IMG_Load("txtrs/dog1.png");
	box->sprites.tex_sprite[6] = IMG_Load("txtrs/dog2.png");
	box->sprites.tex_sprite[7] = IMG_Load("txtrs/dog3.png");
	box->sprites.tex_sprite[8] = IMG_Load("txtrs/dog4.png");
	box->sprites.tex_sprite[9] = IMG_Load("txtrs/health.png");
	box->sprites.tex_sprite[10] = IMG_Load("txtrs/key_in_bug.png");
	box->sprites.tex_sprite[11] = IMG_Load("txtrs/end_level.png");
}

void				load_wall_textures(t_box *box)
{
	box->texture = menu_png("txtrs/game_over.png", box);
	box->texture2 = menu_png("txtrs/mission_passed.png", box);
	box->txtrs[0] = load_texture("txtrs/rock.bmp", box);
	box->txtrs[1] = load_texture("txtrs/mine.bmp", box);
	box->txtrs[2] = load_texture("txtrs/brick.bmp", box);
	box->txtrs[3] = load_texture("txtrs/brown.bmp", box);
	box->txtrs[4] = load_texture("txtrs/castle.bmp", box);
	box->txtrs[5] = load_texture("txtrs/txt1.bmp", box);
	box->txtrs[6] = load_texture("txtrs/sand.bmp", box);
	box->txtrs[7] = load_texture("txtrs/bricks.bmp", box);
	box->txtrs[8] = load_texture("txtrs/Door2.bmp", box);
	box->txtrs[9] = load_texture("txtrs/Door1.bmp", box);
	box->txtrs[10] = load_texture("txtrs/night_r.bmp", box);
	box->txtrs[11] = load_texture("txtrs/fl.bmp", box);
	box->txtrs[12] = load_texture("txtrs/ceiling_01.bmp", box);
	sprites_loader(box);
	ft_load_hud_tex(box);
}
