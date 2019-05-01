# include "SDL.h"
#include "includes/wolf3d.h"

SDL_Surface		*load_texture(char *path, t_box *wolf)
{
	SDL_Surface		*tmp;
	SDL_Surface		*image;

	tmp = SDL_LoadBMP(path);
	image = SDL_ConvertSurfaceFormat(tmp, SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(tmp);
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
	SDL_Event		event;
	int				running;
	int				alpha;

	alpha = 255;
	running = 1;
	box = (t_box *)malloc(sizeof(t_box));
	pic = (t_pic *)malloc(sizeof(t_pic));
	SDL_Init(SDL_INIT_VIDEO);
	box->wind = SDL_CreateWindow("Transperency is freedom!", 100, 100, 600, 600, 0);
	box->rend = SDL_CreateRenderer(box->wind, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	pic->this_picm0 = load_texture("txtrs/bricks.bmp", box);
	pic->this_picm1 = load_texture("txtrs/window.bmp", box);
	texture1 = SDL_CreateTextureFromSurface(box->rend, pic->this_picm0);
	texture2 = SDL_CreateTextureFromSurface(box->rend, pic->this_picm1);
	box->texture = SDL_CreateTexture(box->rend,
        SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 100, 100);
	SDL_SetTextureBlendMode(texture2, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(texture2, alpha);
	//fillTexture(box->rend, box->texture, 255, 0, 0, 50);

	 SDL_SetRenderTarget(box->rend, texture1);
 //    SDL_SetRenderDrawBlendMode(box->rend, SDL_BLENDMODE_BLEND);
 //    SDL_SetRenderDrawColor(box->rend, 0, 255, 0, 255);
    SDL_Rect rect;

	while(running)
	{
		SDL_RenderClear(box->rend);
		SDL_PollEvent(&event);
		if (evnt.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
			running = 0;
		else if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_a && alpha >= 32)
			{
				alpha -= 32;
				printf("alpha = %d\n", alpha);
			}
			else if (event.key.keysym.sym == SDLK_s && alpha <= 223)
			{
				alpha += 32;
				printf("alpha = %d\n", alpha);
			}
			rect.w = 600;
		    rect.h = 600;
		    rect.x = 0;
		    rect.y = 0;
			SDL_SetTextureAlphaMod(texture2, alpha);
			SDL_RenderCopy(box->rend, texture1, NULL, &rect);
			rect.w = 200;
		    rect.h = 200;
		    rect.x = 200;
		    rect.y = 200;
		    SDL_RenderCopy(box->rend, texture2, NULL, &rect);
			SDL_RenderPresent(box->rend);
		}
	}
	SDL_DestroyRenderer(box->rend);
	SDL_DestroyWindow(box->wind);
	SDL_Quit();
}
