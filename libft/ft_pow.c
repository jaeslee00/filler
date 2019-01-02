/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:43:19 by jaelee            #+#    #+#             */
/*   Updated: 2018/11/13 11:47:40 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int a, int b)
{
	if (a == 0 || b < 0)
		return (0);
	if (a == 1 || b == 0)
		return (1);
	return (a * ft_pow(a, (b - 1)));
}