/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 03:20:54 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/09 09:33:03 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		init_sdl(t_visu *v)
{
	int	success;

	success = 1;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! %s\n", SDL_GetError());
		success = 0;
	}
	else
	{
		v->window = SDL_CreateWindow("THE FILLER", SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED, v->w_width, v->w_height,
				SDL_WINDOW_SHOWN);
		if (v->window == NULL)
		{
			printf("window could not be created! %s\n", SDL_GetError());
			success = 0;
		}
		else
			v->surf = SDL_GetWindowSurface(v->window);
	}
	return (success);
}
