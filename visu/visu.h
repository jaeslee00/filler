/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 08:56:03 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/09 10:08:10 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H
# include "libft.h"
# include "SDL.h"
# include <math.h>

typedef struct	s_page
{
	char	map[24][40];
//	struct s_page	*next;
//	struct s_page	*prev;
}				t_page;


typedef struct	s_visu
{
	SDL_Window	*window;
	SDL_Surface	*surf;
	SDL_Surface *image;
	SDL_Event	event;
	//	int			loop;
	//	SDL_Color	white;
	//	SDL_Color	purple;
	//	SDL_Color	red;
	int			nb_x;
	int			nb_y;
	int			w_width;
	int			w_height;
	int			square;
	int			origin_x;
	int			origin_y;
	int			width_line;
	int			height_line;
	t_page		*begin; //better turn into address so i don't copy the whole thing.
}				t_visu;

void	get_windowsize(t_visu *v);
int		init_sdl(t_visu *v);
void	draw_grid_verti(t_visu *v);
void	draw_grid_horiz(t_visu *v);
void	check_piece(t_visu *v);

#endif
