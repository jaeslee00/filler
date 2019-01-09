/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 07:14:30 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/09 10:08:04 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include <stdio.h>

void	draw_curr_x(SDL_Surface *piece, t_visu *v)
{
	SDL_FillRect(piece, NULL, SDL_MapRGB(piece->format, 4, 45, 249));
}

void	draw_prev_x(SDL_Surface *piece, t_visu *v)
{
	SDL_FillRect(piece, NULL, SDL_MapRGB(piece->format, 4, 236, 230));
}

void	draw_curr_o(SDL_Surface *piece, t_visu *v)
{
	SDL_FillRect(piece, NULL, SDL_MapRGB(piece->format, 249, 4, 4));
}

void	draw_prev_o(SDL_Surface *piece, t_visu *v)
{
	SDL_FillRect(piece, NULL, SDL_MapRGB(piece->format, 249, 189, 4));
}

void	draw_piece(int y, int x, t_visu *v)
{
	SDL_Rect	info;
	SDL_Surface	*piece;

	info.x = v->origin_x + 1 + x * v->square + x;
	info.y = v->origin_y + 1 + y * v->square + y;
	info.h = v->square;
	info.w = v->square;
	piece = SDL_CreateRGBSurface(0, info.w, info.h, 32, 0, 0, 0, 0);
	if (v->begin->map[y][x] == 'O')
		draw_prev_o(piece, v);
	else if (v->begin->map[y][x] == 'o')
		draw_curr_o(piece, v);
	else if (v->begin->map[y][x] == 'X')
		draw_prev_x(piece, v);
	else if (v->begin->map[y][x] == 'x')
		draw_curr_x(piece, v);
	SDL_BlitSurface(piece, NULL, v->surf, &info);
	SDL_FreeSurface(piece);
}

void	check_piece(t_visu *v)
{
	int y;
	int x;

	y = 0;
	while (y < v->nb_y)
	{
		x = 0;
		while (x < v->nb_x)
		{
			if (v->begin->map[y][x] != '.')
				draw_piece(y, x, v);
			x++;
		}
		y++;
	}
}
