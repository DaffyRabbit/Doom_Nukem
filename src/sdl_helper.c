#include "wolf3d.h"

void ApplySurface(int x, int y, int w, int h, SDL_Texture *tex, SDL_Renderer *rend)
{
   SDL_Rect pos;
   pos.x = x;
   pos.y = y;
   if (w == 0 || h == 0)
		SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
   else
   {
   		pos.w = w;
   		pos.h = h;
   }
   SDL_RenderCopy(rend, tex, NULL, &pos);
}

SDL_Texture* LoadImage(char *file, SDL_Renderer *renderer)
{
   SDL_Surface *loadedImage = NULL;
   SDL_Texture *texture = NULL;
   loadedImage = SDL_LoadBMP(file);
   if (loadedImage != NULL)
	{
		texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
	}
   else
		printf("error 3\n");
   return texture;
}

SDL_Texture* renderText(char *message, char *fontFile, SDL_Color color, int fontSize,
					SDL_Renderer *renderer)
{
	TTF_Font *font = TTF_OpenFont(fontFile, fontSize);
	if (font == NULL){
		printf("error 5\n");
		return NULL;
	}	
	SDL_Surface *surf = TTF_RenderText_Blended(font, message, color);
	if (surf == NULL){
		TTF_CloseFont(font);
		printf("error 6\n");
		return NULL;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == NULL){
		printf("error 7\n");
	}
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return texture;
}