/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 07:50:42 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/03 18:24:16 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

void	print_coord(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

int		main(void)
{
	t_filler	pc;
	int			success;

	ft_bzero(&pc, sizeof(pc));
	get_player(&pc, 0);
	while (1)
	{
		parse_input(&pc, 0);
		create_nmap(&pc);
		process_map(&pc);
		success = filler(&pc);
		if (success == 1)
			print_coord(pc.put_y, pc.put_x);
		else
			break ;
		free_struct(&pc);
	}
	error(&pc);
	return (0);
}
