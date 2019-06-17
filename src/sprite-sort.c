#include "wolf3d.h"

void ft_my_swap1(t_box *box, int i, int j)
{
	double temp;

	temp = box->sprites.spriteDistance[i];
	box->sprites.spriteDistance[i] = box->sprites.spriteDistance[j];
	box->sprites.spriteDistance[j] = temp;
}

void ft_my_swap2(t_box *box, int i, int j)
{
	int temp;

	temp = box->sprites.spriteOrder[i];
	box->sprites.spriteOrder[i] = box->sprites.spriteOrder[j];
	box->sprites.spriteOrder[j] = temp;
}

void combSort(t_box *box, int amount)
{
	int i;
	int j;

	i = 0;
	while(i < amount - 1)
	{
		j = 0;
		while(j < amount - i - 1)
		{
			if(box->sprites.spriteDistance[j] < box->sprites.spriteDistance[j + 1])
			{           
              ft_my_swap1(box, j, j + 1);
              ft_my_swap2(box, j, j + 1);
           	}
			j++;
		}
		i++;
	}
}

Uint32		get_pixel(t_box *box, SDL_Surface *surface, int x, int y)
{
	Uint32		color;
	Uint8		r;
	Uint8		g;
	Uint8		b;
	double		intens;

	color = 0;
	if (box->no_shadow == 1 || box->mirror_effect == 1 || box->sprites.spt[box->sprites.spriteOrder[box->dsprite.i]].n_text == 2)
		intens = (box->no_shadow == 1) ? 0.68 : 0.8;
	else if (box->sprites.spriteDistance[box->dsprite.i] >= 0)
	{
		intens = (box->sprites.spriteDistance[box->dsprite.i] < 27) ? (1 / box->sprites.spriteDistance[box->dsprite.i] * box->light_power) :
		(0.5 / box->sprites.spriteDistance[box->dsprite.i] * box->light_power);
		if (intens > 0.8)
			intens = 0.8;
	}
	if ((x >= 0 && x <= 64) && (y >= 0 && y <= 64))
	{
		SDL_GetRGB(((int *)surface->pixels)[(y * surface->w) + x], surface->format, &r, &g, &b);
		if (r == 152 && g == 0 && b == 136)
		{
			return 0;
		}
		r = r * intens;
		g = g * intens;
		b = b * intens;
		color = SDL_MapRGB(surface->format, r, g, b);
	}
	return color;
}

void 		sort_sprits(t_box *box)
{
	int i;

	i = 0;
	while (i < box->sprites.n_sprites)
	{
		box->sprites.spriteOrder[i] = i;
     	box->sprites.spriteDistance[i] = ((box->cam.position.x - box->sprites.spt[i].x) * (box->cam.position.x - box->sprites.spt[i].x) + (box->cam.position.y - box->sprites.spt[i].y) * (box->cam.position.y - box->sprites.spt[i].y)); //sqrt not taken, unneeded
		i++;
	}
    combSort(box, box->sprites.n_sprites);
}