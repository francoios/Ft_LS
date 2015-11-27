/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:07:48 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:31:25 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_get_nb_size(int size, int nb)
{
	int size2;

	size2 = 1;
	while (nb > 9)
	{
		size2++;
		nb /= 10;
	}
	if (size2 > size)
		size = size2;
	return (size);
}
