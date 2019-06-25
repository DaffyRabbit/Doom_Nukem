#include "gen.h"

void ft_bb(t_gen *gen)
{
	if (gen && gen->win)
	{
		SDL_SetRelativeMouseMode(SDL_FALSE);
		SDL_WarpMouseInWindow(gen->win, WIN_W / 2, WIN_H / 2);
	}
	SDL_Quit();
	exit(0);
}