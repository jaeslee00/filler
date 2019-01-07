/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 21:23:13 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/05 12:43:20 by jaelee           ###   ########.fr       */
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

static void	parse_piece(t_filler *pc, char *info, int fd)
{
	int		index;
	char	*temp;
	int		cnt;

	temp = info;
	pc->pc_h = ft_atoi_ptr(&temp);
	pc->pc_w = ft_atoi_ptr(&temp);
	(pc->pc_h > 0 && pc->pc_w > 0) ? 0 : error(pc);
	free(info);
	index = 0;
	cnt = 0;
	if (!(pc->piece = ft_memalloc(sizeof(char*) * (pc->pc_h + 1))))
		error(pc);
	while (index < pc->pc_h)
	{
		if ((get_next_line(fd, &(pc->piece[index]))) < 1)
			error(pc);
		pc->pc_w == (int)ft_strlen(pc->piece[index]) ? 0 : error(pc);
		if (ft_strchr(pc->piece[index], '*'))
			cnt++;
		index++;
	}
	cnt > 0 ? 0 : error(pc);
}

static void	parse_map(t_filler *pc, char *info, int fd)
{
	int		index;
	char	*line;
	char	*temp;

	temp = info;
	pc->map_h = ft_atoi_ptr(&temp);
	pc->map_w = ft_atoi_ptr(&temp);
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
		pc->map_w == (int)ft_strlen(pc->map[index]) ? 0 : error(pc);
		index++;
		free(line);
	}
}

static void	get_start_pos(t_filler *pc)
{
	int	x;
	int	y;
	int	y_me;
	int	y_op;

	y_me = -1;
	y_op = -1;
	y = 0;
	while (y < pc->map_h)
	{
		x = 0;
		while (x < pc->map_w)
		{
			if (pc->map[y][x] == pc->me)
				y_me = y;
			if (pc->map[y][x] == pc->op)
				y_op = y;
			x++;
		}
		y++;
	}
	if (y_me < 0 || y_op < 0)
		error(pc);
	pc->start_pos = (y_me < y_op) ? ABOVE : BELOW;
}

void		parse_input(t_filler *pc, int fd)
{
	char	*line;

	init_filler(pc);
	if (get_next_line(fd, &line) < 1)
		error(pc);
	parse_map(pc, line, fd);
	pc->start_pos == 0 ? get_start_pos(pc) : 0;
	if (get_next_line(fd, &line) < 1)
		error(pc);
	parse_piece(pc, line, fd);
}
