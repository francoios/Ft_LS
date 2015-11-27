/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 17:41:42 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:33:56 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_write_types(mode_t mode)
{
	if (S_ISFIFO(mode))
		ft_putchar('p');
	if (S_ISCHR(mode))
		ft_putchar('c');
	if (S_ISDIR(mode))
		ft_putchar('d');
	if (S_ISBLK(mode))
		ft_putchar('b');
	if (S_ISREG(mode))
		ft_putchar('-');
	if (S_ISSOCK(mode))
		ft_putchar('s');
	if (S_ISWHT(mode))
		ft_putchar('w');
	if (S_ISLNK(mode))
		ft_putchar('l');
}
