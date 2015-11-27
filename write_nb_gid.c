/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_nb_gid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 11:31:27 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:33:36 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_write_nb_gid(int size, int nb)
{
	int i;

	i = 0;
	ft_putnbr(nb);
	while (i < (size - ft_get_nb_size(0, nb)))
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr("  ");
}
