/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 21:23:13 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/02 04:16:56 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

static void	init_filler(t_filler *pc)
{
	pc->pc_h = 0;
	pc->pc_w = 0;
	pc->map_h = 0;
	pc->map_w = 0;
	pc->put_y = 0;
	pc->put_x = 0;
	pc->map = NULL;
	pc->nmap = NULL;
	pc->piece = NULL;
}
void	parse_piece(t_filler *pc, char *info, int fd)
{
	int			index;
	char		**temp;

	temp = ft_strsplit(info, ' ');
	pc->pc_h = ft_atoi(temp[1]);
	pc->pc_w = ft_atoi(temp[2]);
	(pc->pc_h > 0 && pc->pc_w > 0) ? 0 : error(pc);
	index = 0;
	free(info);
	if (!(pc->piece = ft_memalloc(sizeof(char*) * (pc->pc_h + 1))))
		error(pc);
	while (index < pc->pc_h)
	{
		if ((get_next_line(fd, &(pc->piece[index]))) < 1)
			error(pc);
		ft_strlen(pc->piece[index]) == pc->pc_w ? 0 : error(pc);
		index++;
	}
}

void	parse_map(t_filler *pc, char *info, int fd)
{
	int		index;
	char	*line;
	char	**temp;

	temp = ft_strsplit(info, ' ');
	pc->map_h = ft_atoi(temp[1]);
	pc->map_w = ft_atoi(temp[2]);
	(pc->map_h > 0 && pc->map_w > 0) ? 0 : error(pc);
	index = 0;
	free(info);
	if (!(pc->map = ft_memalloc(sizeof(char*) * (pc->map_h + 1))))
		error(pc);
	if ((get_next_line(fd, &line)) < 1)
		error(pc);
	free(line);
	while (index < pc->map_h)
	{
		if ((get_next_line(fd, &line)) < 1)
			error(pc);
		if (!(pc->map[index] = ft_strdup(line + 4)))
			error(pc);
		ft_strlen(pc->map[index]) == pc->map_w ? 0 : error(pc);
		index++;
		free(line);
	}
}

void	parse_input(t_filler *pc, int fd)
{
	char	*line;

	init_filler(pc);
	if (get_next_line(fd, &line) < 1)
		error(pc);
	parse_map(pc, line, fd);
	if (get_next_line(fd, &line) < 1)
		error(pc);
	parse_piece(pc, line, fd);
}

void	get_player(t_filler *pc, int fd)
{
	char	*line;

	if (get_next_line(fd, &line) < 1)
		error(pc);
	if (ft_strstr(line, "p1"))
	{
		pc->me = 'O';
		pc->op = 'X';
	}
	else if (ft_strstr(line, "p2"))
	{
		pc->me = 'X';
		pc->op = 'O';
	}
	free(line);
}
