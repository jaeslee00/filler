/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 04:12:04 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/09 02:36:54 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "visu.h"

void	get_mapsize(t_page **t, t_visu *v)
{
	char	*line;
	char	*temp;
	int		index;

	line = NULL;
	index = 0;
	*t = (t_v*)malloc(sizeof(**t));
	while (index < 9)
	{
		if (get_next_line(0, &line))
			ft_exit(v);
		free(line);
	}
	if (get_next_line(0, &line) < 1)
		ft_exit(v);
	if (ft_strstr(line, "Plateau"))
	{
		temp = line;
		v->nb_y = ft_atoi_ptr(&temp);
		v->nb_x = ft_atoi_ptr(&temp);
		free(line);
	}
	if (v->nb_y <= 0 || v->nb_x <= 0)
	{
		free_all(v); //TODO free all mallocs made
		ft_exit(v);
	}
}

