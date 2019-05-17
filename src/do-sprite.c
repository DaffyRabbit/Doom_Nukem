#include "wolf3d.h"

void 	takeSprite(t_box *box, double x, double y, double d_x, double d_y)
{
	if ((((box->all_map[(int)y][(int)(x + d_x * box->go.spd + 0.15)] == 6) ||
		(box->all_map[(int)y][(int)(x + d_x * box->go.spd - 0.15)] == 6)) ||
		((box->all_map[(int)(y + d_y * box->go.spd + 0.15)][(int)x] == 6) ||
		(box->all_map[(int)(y + d_y * box->go.spd - 0.15)][(int)x] == 6))) &&
		(box->keys[SDL_SCANCODE_E] == 1))
	{
		box->HUD.hp_val++;
		// printf("%s\n", box->my_bag.items[i]);
	}
}