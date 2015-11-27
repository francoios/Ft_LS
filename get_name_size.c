/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:07:58 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:31:16 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_name_size(char *name, int size)
{
	int size2;

	size2 = ft_strlen(name);
	if (size2 > size)
		size = size2;
	return (size);
}
