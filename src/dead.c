#include "wolf3d.h"

void	ft_dead(t_box *box)
{
	Mix_HaltMusic();
	Mix_HaltChannel(5);
	box->dead = 1;
	Mix_PlayMusic(box->music.dead_sound,-1);
}