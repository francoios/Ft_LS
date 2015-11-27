/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 17:35:49 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:47:00 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_write_str(char *str, int size)
{
	int i;

	i = 0;
	ft_putstr(str);
	while (i < (size - ft_strlen(str)))
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr("  ");
}
