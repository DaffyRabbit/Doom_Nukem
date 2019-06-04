#include "wolf3d.h"

int 	takeSprite(t_box *box, double x, double y, double d_x, double d_y)
{
	int j;
	SDL_Color color = {192, 11, 0, 0};  

	if (box->bag.n_items == 6)
	{
		 /// !!!!!!!!!!!! //////////
		box->bag.full_message = renderText("Your bag is full!", "ttf/mainfont.ttf", color, 20, (*box).rend);
		/// !!!!!!!!!!!! //////////
		return 0;
	}
	SDL_RenderClear(box->rend);
	box->bag.text_item = SDL_CreateTextureFromSurface(box->rend,box->sprites.tex_sprite[4]);
	if ((((box->all_map[(int)y][(int)(x + d_x * box->go.spd + 0.15)] == 6) ||
		(box->all_map[(int)y][(int)(x + d_x * box->go.spd - 0.15)] == 6)) ||
		((box->all_map[(int)(y + d_y * box->go.spd + 0.15)][(int)x] == 6) ||
		(box->all_map[(int)(y + d_y * box->go.spd - 0.15)][(int)x] == 6))) &&
		(box->keys[SDL_SCANCODE_E] == 1))
	{
		if (box->bag.n_items == 3)
		{
			box->bag.posX = 5;
			box->bag.posY = box->bag.posY + 50;
		}
		box->bag.items[box->bag.n_items] = 6;
		box->bag.rect[box->bag.n_items].rect_items.x = box->bag.posX;
		box->bag.rect[box->bag.n_items].rect_items.y = box->bag.posY;
		box->bag.rect[box->bag.n_items].rect_items.h = 50;
		box->bag.rect[box->bag.n_items].rect_items.w = 50;
		box->bag.posX = box->bag.posX + 50;
		box->all_map[(int)y][(int)(x + d_x * box->go.spd + 0.15)] = 0;
		box->all_map[(int)y][(int)(x + d_x * box->go.spd - 0.15)] = 0;
		box->all_map[(int)(y + d_y * box->go.spd + 0.15)][(int)x] = 0;
		box->all_map[(int)(y + d_y * box->go.spd - 0.15)][(int)x] = 0;
		j = 0;
		while(j < box->sprites.n_sprites)
		{
			if((box->sprites.spt[j].x == ((int)x + 0.5)  && box->sprites.spt[j].y == ((int)(y + d_y * box->go.spd + 0.15) + 0.5)) ||
				(box->sprites.spt[j].x == ((int)x + 0.5) && box->sprites.spt[j].y == ((int)(y + d_y * box->go.spd - 0.15) + 0.5)) ||
				(box->sprites.spt[j].x == ((int)(x + d_x * box->go.spd + 0.15) + 0.5) && box->sprites.spt[j].y == ((int)y + 0.5)) ||
				(box->sprites.spt[j].x == ((int)(x + d_x * box->go.spd - 0.15) + 0.5) && box->sprites.spt[j].y == ((int)y + 0.5)))
			{
				int k = 0;
				int l = 0;
				box->sprites.n_sprites--;
				while(k < box->sprites.n_sprites)
				{
					if(l != j)
					{
						box->sprites.spt[k] = box->sprites.spt[l];
						k++;
					}
					l++;
				}
			}
			j++;
		}
		box->bag.n_items++;
	}
	return 1;
}