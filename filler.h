/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 23:03:21 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/04 06:41:42 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# define OPEN 2147483646
# define ABOVE 1
# define BELOW 2

typedef struct	s_filler
{
	int		pc_h;
	int		pc_w;
	int		map_h;
	int		map_w;
	int		start_pos;
	int		put_y;
	int		put_x;
	int		sum;
	char	**piece;
	char	**map;
	int		**nmap;
	char	me;
	char	op;
	int		nbr_me;
	int		nbr_op;
}				t_filler;

void			parse_input(t_filler *pc, int fd);
void			create_nmap(t_filler *pc);
void			process_nmap(t_filler *pc);
int				filler(t_filler *pc);
int				ft_atoi_ptr(char **str);
void			error(t_filler *pc);
void			free_all(t_filler *pc);

#endif
