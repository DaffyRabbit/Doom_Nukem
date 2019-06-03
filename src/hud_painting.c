#include "wolf3d.h"

void		paint_hud(t_box *box)
{
	int i;

	i = 0;
	ft_r_bars_face(box);
	while (i < box->bag.n_items)
	{
		if (box->bag.rect[i].rect_items.x)
		{
			SDL_RenderCopy(box->rend, box->bag.text_item,
				NULL, &box->bag.rect[i].rect_items);
		}
		i++;
	}
	if (box->bag.Message)
	{
		ApplySurface(5, 681, 0, 0, box->bag.Message, box->rend);
	}
	if (box->hud.time > 100)
		box->hud.time = 100;
	if (box->hud.w_start == 0)
		ft_start_anim(box);
	else
		ft_knife_sh(box);
	box->hud.time++;
}

void		ft_load_hud_tex(t_box *box)
{
	box->hud.weapon[0].weapon = ft_check_png(box, "txtrs/weapon/w_start1.png");
	box->hud.weapon[1].weapon = ft_check_png(box, "txtrs/weapon/w_start2.png");
	box->hud.weapon[2].weapon = ft_check_png(box, "txtrs/weapon/w_start3.png");
	box->hud.weapon[3].weapon = ft_check_png(box, "txtrs/weapon/w_wait.png");
	box->hud.weapon[4].weapon = ft_check_png(box, "txtrs/weapon/w_fight1.png");
	box->hud.weapon[5].weapon = ft_check_png(box, "txtrs/weapon/w_fight2.png");
	box->hud.bar.bott_bar = ft_check_png(box, "txtrs/bott_bar.png");
	box->hud.bar.rad_bar = ft_check_png(box, "txtrs/rad.png");
	box->hud.face[0].face = ft_check_png(box, "txtrs/face_left.png");
	box->hud.face[1].face = ft_check_png(box, "txtrs/face_center.png");
	box->hud.face[2].face = ft_check_png(box, "txtrs/face_right.png");
}

void		ft_shooting(int code, t_box *box)
{
	if (code == SDL_BUTTON_LEFT && box->hud.weapon[0].usless == 1)
	{
		box->hud.fire = 1;
	}
	box->hud.weapon[0].usless = 1;
}
