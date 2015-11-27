/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_min_maj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 20:14:27 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:33:25 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_write_maj_min(int *size, int maj, int min)
{
	int i;

	i = 0;
	while (i < (size[4] - ft_get_nb_size(0, maj)))
	{
		ft_putchar(' ');
		i++;
	}
	ft_putnbr(maj);
	ft_putstr(", ");
	i = 0;
	while (i < (size[5] - ft_get_nb_size(0, min)))
	{
		ft_putchar(' ');
		i++;
	}
	ft_putnbr(min);
	ft_putstr("  ");
}
