#include "wolf3d.h"

void	ft_dead(t_box *box)
{
	SDL_Event		event;

	Mix_HaltMusic();
	Mix_HaltChannel(5);
	box->dead = 1;
	Mix_PlayMusic(box->music.dead_sound,-1);
	box->this_txtr = box->texture;
	while (1)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT || (event.key.keysym.sym == SDLK_ESCAPE &&
				event.key.state == SDL_RELEASED))
				all_destroy(box);
		SDL_RenderClear(box->rend);
		ApplyTexture(0, 0, box);
		SDL_RenderPresent(box->rend);
	}
}