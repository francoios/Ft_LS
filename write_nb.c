/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 17:35:41 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:33:31 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_write_nb(int size, int nb)
{
	int i;

	i = 0;
	while (i < (size - ft_get_nb_size(0, nb)))
	{
		ft_putchar(' ');
		i++;
	}
	ft_putnbr(nb);
	ft_putchar(' ');
}
