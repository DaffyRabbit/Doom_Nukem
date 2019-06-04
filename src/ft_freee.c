#include "wolf3d.h"

void	ft_freee(t_box *box)
{
	int i;

	i = 0;
	SDL_FreeSurface(box->hud.bar.bott_bar);
	SDL_FreeSurface(box->hud.bar.rad_bar);
	while (i < 3)
	{
		SDL_FreeSurface(box->hud.heals[i].heals);
		SDL_FreeSurface(box->hud.rad[i].rad);
		SDL_FreeSurface(box->hud.weapon[i].weapon);
		SDL_FreeSurface(box->hud.face[i].face);
		i++;
	}
	while(i < 6)
	{
		SDL_FreeSurface(box->hud.weapon[i].weapon);
		i++;
	}
}

void ft_music_free(t_box *box)
{
	Mix_HaltMusic();
	Mix_FreeMusic(box->music.bgm);
	Mix_FreeMusic(box->music.bgm_menu);
	Mix_FreeMusic(box->music.dead_sound);
	Mix_FreeChunk(box->music.rad);
	Mix_FreeChunk(box->music.knife);
	Mix_FreeChunk(box->music.walk);
	Mix_FreeChunk(box->music.jet);
	Mix_Quit();
}	