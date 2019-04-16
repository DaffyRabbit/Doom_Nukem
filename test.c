#include "includes/wolf3d.h"
#include <stdio.h>

int 	exxit(t_box *box)
{
	SDL_RenderClear(box->rend);
	SDL_DestroyWindow(box->wind);
	SDL_DestroyTexture(box->texture);
	SDL_DestroyRenderer(box->rend);
	exit(0);
	return (0);
}

SDL_Texture		*load_texture(char *path, t_box *box)
{
	SDL_Surface		*tmp;
	SDL_Texture		*texture;

	tmp = SDL_LoadBMP(path);
	if (tmp == NULL)
	{
		printf("Error while loading a texture file\n");
		exit(1);
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(box->rend, tmp);
		SDL_FreeSurface(tmp);
	}
	return (texture);
}

void				start_game(t_box *box, t_pic *pic, char *name)
{
	int				w;
	int				row_l;
	int				h;
	Uint32			format;
	SDL_Event		evnt;
	Uint32				*pixels;
	Uint32 i;
	int j;
	int pitch = 0;
	Uint32 			*upixels;

	row_l = 0;
	SDL_Init(SDL_INIT_VIDEO);
	box->wind = SDL_CreateWindow(name, 100, 100, WIND_W, WIND_H, 0);
	box->rend = SDL_CreateRenderer(box->wind, -1, SDL_RENDERER_ACCELERATED);

	if ((box->texture = load_texture("txtrs/stone.bmp", box)) == NULL)
		printf("ERROR!\n");
	SDL_QueryTexture(box->texture, NULL, NULL, &w, &h);
	printf("w = %d, h = %d\n", w, h);
	SDL_LockTexture(box->texture, NULL, (void **)&pixels, &pitch);
	printf("sum = %d\n", pitch);
	/*while(j < w * h)
	{*/
		pixels[2048] = 0xff00ff;
	/*	printf("WSP\n");
		j++;
	}*/
	SDL_UnlockTexture(box->texture);
	while (1)
	{
		SDL_PollEvent(&evnt);
		SDL_RenderClear(box->rend);
		if (evnt.type == SDL_QUIT || evnt.key.keysym.sym == SDLK_ESCAPE)
			exxit(box);
		SDL_RenderCopy(box->rend, box->texture, NULL, NULL );
		SDL_RenderPresent(box->rend);
	}
}

int				main(void)
{
	t_box		box;
	t_pic		pic;

	box.go.south = 0;
	start_game(&box, &pic, "Wolf3d");
	return (0);
}