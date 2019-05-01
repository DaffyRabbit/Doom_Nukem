SDL_Color GetPixelColor(const SDL_Surface* pSurface, const int X, const int Y)
{
const int	Bpp	= pSurface->format->BytesPerPixel;
const Uint8*	pPixel	= (Uint8*)pSurface->pixels + Y * pSurface->pitch + X * Bpp;
const Uint32	PixelColor = (Uint32)pPixel;
	SDL_Color Color = {0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE};

	SDL_GetRGBA(PixelColor, pSurface->format, &Color.r, &Color.g, &Color.b, &Color.a);

	return Color;
}

void SetPixelColor(SDL_Surface* pSurface, int X, int Y, Uint32 Pixel)
{
	Uint32* pPixels = (Uint32*)pSurface->pixels;

	pPixels[(Y * pSurface->w) + X] = Pixel;
}

bool Create(void)
{
	// Create two surfaces with the same texture in it that we can render and compare
	SDL_Surface* pSurface1 = CreateSurface("Data/Textures/Texture.png");
	SDL_Surface* pSurface2 = CreateSurface("Data/Textures/Texture.png");

	if(!pSurface1) return false;
	if(!pSurface2) return false;

	const int SurfaceWidth	= pSurface2->w;
	const int SurfaceHeight	= pSurface2->h;

	// Loop through the second surface' pixel data
	for(int i = 0; i < SurfaceHeight; ++i)
	{
		for(int j = 0; j < SurfaceWidth; ++j)
		{
			const SDL_Color PixelColor = GetPixelColor(pSurface2, j, i);

			int AlphaValue = PixelColor.a;

			// Set the alpha value of the second surface' upper left region to 16, the lower right region to 128 and let the rest of the surface' pixel values be as they are
			     if(i < (SurfaceHeight / 2) && j < (SurfaceWidth / 2)) AlphaValue = 16;
			else if(i > (SurfaceHeight / 2) && j > (SurfaceWidth / 2)) AlphaValue = 128;

			const Uint32 NewPixelValue = SDL_MapRGBA(pSurface2->format, PixelColor.r, PixelColor.g, PixelColor.b, AlphaValue);

			if(SDL_MUSTLOCK(pSurface2))
				SDL_LockSurface(pSurface2);

			SetPixelColor(pSurface2, j, i, N. ewPixelValue);

			if(SDL_MUSTLOCK(pSurface2))
				SDL_UnlockSurface(pSurface2);
		}
	}

	// Create the final textures
	SDL_Texture* pTexture1 = SDL_CreateTextureFromSurface(pRenderer, pSurface1);
	SDL_Texture* pTexture2 = SDL_CreateTextureFromSurface(pRenderer, pSurface2);

	if(!pTexture1) return false;
	if(!pTexture2) return false;

	SDL_SetTextureBlendMode(pTexture1, SDL_BLENDMODE_BLEND);
	SDL_SetTextureBlendMode(pTexture2, SDL_BLENDMODE_BLEND);

	return true;
}