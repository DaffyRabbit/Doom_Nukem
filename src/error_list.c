#include "wolf3d.h"

void	fatal_error(int er, t_box *box)
{
	if (er == 1)
		ft_putendl("SDL did not initialize!");
	if (er == 2)
		ft_putendl("Window did not create!");
	if (er == 3)
	{
		ft_putendl("Renderer did not create!");
		SDL_DestroyWindow(box->wind);
	}
	if (er == 4)
	{
		ft_putendl("SDL_ttf did not initialize!");
		SDL_DestroyWindow(box->wind);
		SDL_DestroyRenderer(box->renderer);
	}
	if (er == 5)
		ft_putendl("Some dir not found!");
	if (er == 6)
		ft_putendl("Some sytem img not found!");
	if (er == 7)
		ft_putendl("ALL GOOD");
	if (er > 1 && er < 5)
		SDL_Quit();
	if (er >= 5)
	{
		SDL_DestroyWindow(box->wind);
		SDL_DestroyRenderer(box->renderer);
		SDL_Quit();
	}
	exit(er);
}