/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 00:19:46 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/09 09:54:29 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "visu.h"

void	ft_close(t_visu *v)
{
	SDL_FreeSurface(v->image);
	v->image = NULL;
	SDL_DestroyWindow(v->window);
	v->window = NULL;
	SDL_Quit();
}

void	draw_grid(t_visu *v)
{
	draw_grid_verti(v);
	draw_grid_horiz(v);
}

int		main(int argc, char *argv[])
{
	t_visu		v;
	int			quit;


	ft_bzero(&v, sizeof(v));
	quit = 0;
//		get_mapsize(&t, &v);
	//	begin = t;
	v.nb_x = 40; //TODO these has to be parsed through stdin
	v.nb_y = 24;
	t_page t = {{
			"..OOOOOOOOOOOOOOOXXXXXXXXXXXXXXXXXXXXXXX",
			"..OOOOOOOOOOOOOOOXXXXXXXXXXXXXXXXXXXXXXX",
			"..OOOOOOOOOOOOOOOOXXXXXXXXXXXXXXXXXXXXXX",
			"...OOOOOOOOOOOOOOOXXXXXXXXXXXXXXXXXXXXXX",
			"...OOOOOOXXXXOOOXXXXXXXXXXXXXXXXXXXXXXXX",
			"...OOOOOOXXXXOOOXXXXXXXXXXXXXXXXXXXXXXXX",
			"..OOOOOOOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
			"....OOOOOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
			"...OOOOOOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
			"...OOOOOOOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
			"..OOOOOOOOOOXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
			"OOOO.OOOOOOOOXXXXXXXXXXXXXXXXXXXXXXXXXXX",
			"OOOOOOOOOOOOOOOOOOXOXXXXXXXXXXXXXXXXXXXX",
			".OOOOOOOOOOOOOOOOOOOXXXXXXXXXXXXXXXXXXXX",
			"O.OOOOOOOOOOOOOOOOOOXXXXXXxxXXXXXXXXXXXX",
			"OOOOOOOOOOOOOOOOOOOXXXXXXXXXX.XXXXXXXXXX",
			"OOOOOOOOOOOOOOOOOOXXX.XXXXXXXXX..X.XXXXX",
			"OOOOOOOOOOOOOOOOOOOOXXX.XXX..XX.XXXXX...",
			"OOOOOOOOOOOOOOOOXXXXXXX..XXXXXXXXXXX....",
			"OOOOOOOOOOOOOOOOOOXXXXX..XX.X...X.XXX...",
			"OOOOOOOOOOOOOOOOOOXXXXXXXXXXX......XX...",
			"OOOOOOOOOOOOOOOOOOXOOOOXXX..XX..........",
			"OOOOOOOOOOOOOOOOOOOOOOOOOXXXXX..........",
			"OOOOOOOOOOOOOOOOOOOOOOOOOXXX.X.........."
	}};
	v.begin = &t;
	get_windowsize(&v);
	if (!(init_sdl(&v)))
		printf("Failed to initialize!\n");
	else
	{
		while (!quit)
		{
			while (SDL_PollEvent(&v.event) != 0)
			{
				if (v.event.type == SDL_QUIT)
					quit = 1;
			}
			draw_grid(&v);
			check_piece(&v);
			SDL_UpdateWindowSurface(v.window);
		}
	}
	ft_close(&v);
	return (0);
}
