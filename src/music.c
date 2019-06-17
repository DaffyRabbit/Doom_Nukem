#include "wolf3d.h"

void		ft_init_music(t_box *box)
{
	box->music.walking = 5;
	box->music.bgm_menu = Mix_LoadMUS("music/bgm_menu.mp3");
	box->music.bgm = Mix_LoadMUS("music/bgm.mp3");
	box->music.dead_sound = Mix_LoadMUS("music/dead_sound.mp3");
	box->music.gta = Mix_LoadMUS("music/GTA.mp3");
	Mix_PlayMusic(box->music.bgm_menu, -1);
	box->music.rad = Mix_LoadWAV("music/rad.mp3");
	box->music.walk = Mix_LoadWAV("music/walk.mp3");
	box->music.knife = Mix_LoadWAV("music/knife_sound.mp3");
}

void		ft_walking(t_box *box)
{
	if (!box->keys[SDL_SCANCODE_SPACE] && box->fly_mode == 0)
		Mix_PlayChannel(2, box->music.walk, 0);
}

void		ft_check_walk(t_box *box)
{
	if (box->music.walking == 17 && box->fly_mode == 0)
	{
		ft_walking(box);
		box->music.walking = 0;
	}
	box->music.walking++;
}

void		ft_lets_music(t_box *box)
{
	Mix_HaltMusic();
	Mix_VolumeMusic(70);
	Mix_PlayMusic(box->music.bgm, 1);
	Mix_PlayChannel(5, box->music.rad, 999);
}
