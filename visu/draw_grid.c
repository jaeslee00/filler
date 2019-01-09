/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 22:51:28 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/09 10:50:18 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	draw_grid_horiz(t_visu *v)
{
	int			nb_y;
	SDL_Rect	info;
	SDL_Surface *grid;

	nb_y = v->nb_y;
	info.x = (v->w_width - v->width_line) / 2;
	info.y = (v->w_height - v->height_line) / 2;
	info.h = 1;
	info.w = v->width_line + 2;
	grid = SDL_CreateRGBSurface(0, info.w, info.h, 32, 0, 0, 0, 0);
	while (nb_y-- >= 0)
	{
		SDL_FillRect(grid, NULL, SDL_MapRGB(grid->format, 255, 255, 255));
		SDL_BlitSurface(grid, NULL, v->surf, &info);
		info.y += v->square + 1;
	}
	SDL_FreeSurface(grid);
}

void	draw_grid_verti(t_visu *v)
{
	int			nb_x;
	SDL_Rect	info;
	SDL_Surface	*grid;

	nb_x = v->nb_x;
	v->width_line = v->nb_x * v->square + (v->nb_x - 1);
	v->height_line = v->nb_y * v->square + (v->nb_y - 1);
	info.x = (v->w_width - v->width_line) / 2;
	info.y = (v->w_height - v->height_line) / 2;
	v->origin_x = info.x;
	v->origin_y = info.y;
	info.h = v->height_line + 2;
	info.w = 1;
	grid = SDL_CreateRGBSurface(0, info.w, info.h, 32, 0, 0, 0, 0);
	while (nb_x-- >= 0)
	{
		SDL_FillRect(grid, NULL, SDL_MapRGB(grid->format, 255, 255, 255));
		SDL_BlitSurface(grid, NULL, v->surf, &info);
		info.x += v->square + 1;
	}
	SDL_FreeSurface(grid);
}

