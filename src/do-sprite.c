#include "wolf3d.h"

void 	takeSprite(t_box *box, double x, double y, double d_x, double d_y)
{
	 y = 0;
	 x = 0;
	 d_x = 0;
	 d_y = 0;
	 box->HUD.hp_val = 10;
	// if ((((box->all_map[(int)y][(int)(x + d_x * box->go.spd + 0.15)] == 6) ||
	// 	(box->all_map[(int)y][(int)(x + d_x * box->go.spd - 0.15)] == 6)) ||
	// 	((box->all_map[(int)(y + d_y * box->go.spd + 0.15)][(int)x] == 6) ||
	// 	(box->all_map[(int)(y + d_y * box->go.spd - 0.15)][(int)x] == 6))) &&
	// 	(box->keys[SDL_SCANCODE_E] == 1))
	// {
	// 	box->bag[i] = 6;
	// 	// printf("%d\n", (int)(x + d_x * box->go.spd + 0.15));
	// 	// printf("%d\n", (int)y);
	// 	box->all_map[(int)y][(int)(x + d_x * box->go.spd + 0.15)] = 0;
	// 	box->all_map[(int)y][(int)(x + d_x * box->go.spd - 0.15)] = 0;
	// 	box->all_map[(int)(y + d_y * box->go.spd + 0.15)][(int)x] = 0;
	// 	box->all_map[(int)(y + d_y * box->go.spd - 0.15)][(int)x] = 0;
	// 	while(j < box->sprites.n_sprites)
	// 	{
	// 		if((box->sprites.spt[j].x == ((int)x + 0.5)  && box->sprites.spt[j].y == ((int)(y + d_y * box->go.spd + 0.15) + 0.5)) ||
	// 			(box->sprites.spt[j].x == ((int)x + 0.5) && box->sprites.spt[j].y == ((int)(y + d_y * box->go.spd - 0.15) + 0.5)) ||
	// 			(box->sprites.spt[j].x == ((int)(x + d_x * box->go.spd + 0.15) + 0.5) && box->sprites.spt[j].y == ((int)y + 0.5)) ||
	// 			(box->sprites.spt[j].x == ((int)(x + d_x * box->go.spd - 0.15) + 0.5) && box->sprites.spt[j].y == ((int)y + 0.5)))
	// 		{
	// 			int k = 0;
	// 			int l = 0;
	// 			box->sprites.n_sprites--;
	// 			while(k < box->sprites.n_sprites)
	// 			{
	// 				if(l != j)
	// 				{
	// 					box->sprites.spt[k] = box->sprites.spt[l];
	// 					k++;
	// 				}
	// 				l++;
	// 			}
	// 		}
	// 		j++;
	// 	}
	// 	// printf("%d\n", box->bag[i]);
	// 	i++;
	// }
}