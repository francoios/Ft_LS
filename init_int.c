/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:33:59 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:27:13 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	*ft_init_int(void)
{
	int		*size;
	int		i;

	size = (int *)malloc(sizeof(int) * 7);
	i = 0;
	while (i < 7)
	{
		if (i == 2 || i == 1)
			size[i] = 1;
		else
			size[i] = 0;
		i++;
	}
	return (size);
}
