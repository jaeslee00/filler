/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 07:50:42 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/04 05:16:04 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

static void	get_player(t_filler *pc, int fd)
{
	char	*line;

	if (get_next_line(fd, &line) < 1)
		error(pc);
	if (ft_strstr(line, "p1"))
	{
		pc->me = 'O';
		pc->op = 'X';
		pc->nbr_me = -1;
		pc->nbr_op = -2;
	}
	else if (ft_strstr(line, "p2"))
	{
		pc->me = 'X';
		pc->op = 'O';
		pc->nbr_me = -2;
		pc->nbr_op = -1;
	}
	free(line);
}

static void	print_coord(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

int			main(void)
{
	t_filler	pc;
	int			success;

	ft_bzero(&pc, sizeof(pc));
	get_player(&pc, 0);
	while (1)
	{
		parse_input(&pc, 0);
		create_nmap(&pc);
		process_nmap(&pc);
		success = filler(&pc);
		if (success == 1)
			print_coord(pc.put_y, pc.put_x);
		else
			break ;
		free_all(&pc);
	}
	error(&pc);
	return (0);
}
