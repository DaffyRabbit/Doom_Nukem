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

void ApplyTexture(int x, int y, t_box *box)
{
	SDL_Rect pos;

	pos.x = x;
	pos.y = y;
	pos.w = (*box).this_txtr.w;
	pos.h = (*box).this_txtr.h;
	SDL_RenderCopy((*box).renderer, (*box).this_txtr.img, NULL, &pos);
}

SDL_Texture* LoadImage(char *file, t_box *box, t_texture **new_txtr)
{
	int i = 0;
	SDL_Surface *loadedImage = NULL;
	SDL_Texture *texture = NULL;
	loadedImage = IMG_Load(file);
	Uint32 format = SDL_GetWindowPixelFormat( box->wind );
    SDL_PixelFormat* mappingFormat = SDL_AllocFormat( format );
	// SDL_Color color = { 88, 214, 141, 0 };
	// SDL_Color transparent = { 255, 255, 255, 255 };
	Uint32 color = SDL_MapRGB( mappingFormat, 0xFF, 0x00, 0x00 );
	// >WARNINGS< якогось біса не працюе прозорість;
	Uint32 transparent = SDL_MapRGBA( mappingFormat, 0xFF, 0xFF, 0xFF, 0x00 );
	if (loadedImage != NULL)
	{
		SDL_Surface* formattedSurface = SDL_ConvertSurfaceFormat( loadedImage, SDL_GetWindowPixelFormat( box->wind ), NULL );
		texture = SDL_CreateTexture( box->renderer, SDL_GetWindowPixelFormat( box->wind ), SDL_TEXTUREACCESS_STREAMING, formattedSurface->w, formattedSurface->h );
		SDL_LockTexture( texture, NULL, &(**new_txtr).pixels, &(**new_txtr).pitch );
		ft_memcpy((**new_txtr).pixels, formattedSurface->pixels, formattedSurface->pitch * loadedImage->h);
		(**new_txtr).w = formattedSurface->w;
		(**new_txtr).h = formattedSurface->h;
		Uint32* pixel = (Uint32*)(**new_txtr).pixels;
		int pixelCount = ((**new_txtr).pitch / 4) * loadedImage->h;
		while (i < pixelCount)
		{
			//printf("%d\n", (int)color);
			if (pixel[i] == color)
			{
				pixel[i] = transparent;
			}
			i++;
		}
		(**new_txtr).pixels = (void *)pixel;
		printf("Load w = %d h = %d\n", loadedImage->w, loadedImage->h);
		SDL_UnlockTexture( texture );
	}
	else
		printf("error %s\n", file);
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

t_texture findeimg(int c, t_texture *txtr)
{
	t_texture *buf;

	buf = txtr;
	while (c != buf->code)
	{
		if (buf->next == NULL)
		{
			printf("Not Found!\n");
			break;
		}
		buf = buf->next;
	}
	return(*buf);
}

char	*if_it_map(int i, char *name, char f)
{
	if (f == '/' && i > 10)
	{
		name[8] = '.';
		name[9] = '.';
		name[10] = '.';
		name[11] = '\0';
	}
	else
		name[i] = '\0';
	return (name);
}

char	*add_name(char *file, char f)
{
	int i;
	int a;
	int b;
	char *name;

	a = 0;
	b = 0;
	i = 0;
	while (file[a] != '\0')
		a++;
	while (file[b] != f && file[b] != '\0')
		b++;
	b++;
	if (b > a)
		b = 0;
	a = a - b - 4;
	name = (char *)malloc(sizeof(char) * a);
	while (a > 0)
	{
		name[i++] = file[b++];
		a--;
	}
	name = if_it_map(i, name, f);
	return(name);
}

int ft_syscode(char *file)
{
	int j;
	int i;
	int res;
	char *filename;

	j = 4;
	i = 0;
	while (ft_isdigit(file[j++]) == 1)
		i++;
	if (i == 0)
		return (-1);
	filename = (char *)malloc(sizeof(char) * i);
	j = 4;
	i = 0;
	while (ft_isdigit(file[j]) == 1)
		filename[i++] = file[j++];
	filename[i] = '\0';
	res = ft_atoi(filename);
	free(filename);
	return (res);
}

int finde_slote(t_box *t)
{
	int c;
	t_texture *buf;

	c = 0;
	buf = t->txtr;
	if (buf == NULL)
		return (0);
	if (buf->code == 0)
		return (1);
	while (buf->next != NULL)
	{
		buf = buf->next;
		c++;
	}
	return(c);
}

void Loadtxtr(t_box ***box, char *file, int f)
{
	int c;
	t_texture  *new_txtr;

	c = 0;
	if ((new_txtr = (t_texture *)malloc(sizeof(t_texture))) == NULL)
		printf("Error\n");
	new_txtr->img = LoadImage(ft_strjoin("txtrs/",file), **box, &new_txtr);
	if (f == 1 || f == 3)
	{
		c = finde_slote(**box);
		if (f != 3)
			(**box)->alltxtr[c] = add_name(file, '_');
		else
			(**box)->alltxtr[c] = file;
		new_txtr->code = c;
		new_txtr->next = (**box)->txtr;
		(**box)->txtr = new_txtr;
	}
	else if (f == 2)
	{
		new_txtr->code = ft_syscode(file);
		new_txtr->next = (**box)->images;
		(**box)->images = new_txtr;
	}
}