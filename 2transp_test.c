# include "SDL.h"
#include "wolf3d.h"

SDL_Surface		*load_texture(char *path, t_box *wolf)
{
	SDL_Surface		*tmp;
	SDL_Surface		*image;

	tmp = SDL_LoadBMP(path);
	if (tmp == NULL)
	{
		ft_putendl("Error while loading a texture file\n");
		all_destroy(wolf);
		exit(1);
	}
	else
	{
		image = SDL_ConvertSurfaceFormat(tmp, SDL_PIXELFORMAT_ARGB8888, 0);
		SDL_FreeSurface(tmp);
	}
	return (image);
}

void fillTexture(SDL_Renderer *renderer, SDL_Texture *texture, int r, int g, int b, int a)
{
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, NULL);
}

int					main()
{
	t_box			*box;
	t_pic			*pic;
	SDL_Event		evnt;
	SDL_Texture		*texture1;
	SDL_Texture 	*texture2;

	box = (t_box *)malloc(sizeof(t_box));
	pic = (t_pic *)malloc(sizeof(t_pic));
	SDL_Init(SDL_INIT_VIDEO);
	box->wind = SDL_CreateWindow(name, 100, 100, 400, 400, 0);
	box->rend = SDL_CreateRenderer(box->wind, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	pic->this_picm0 = load_texture("txtrs/bricks.bmp", box);
	pic->this_picm1 = load_texture("txtrs/rf.bmp", box);
	texture1 = SDL_CreateTextureFromSurface(box->rend, pic->this_picm0);
	texture2 = SDL_CreateTextureFromSurface(box->rend, pic->this_picm1);
	box->texture = SDL_CreateTexture(box->rend,
        SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 400, 400);

	fillTexture(box->rend, box->texture, 0, 255, 50, 255);
}
