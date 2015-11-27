/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 17:35:21 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:33:40 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_write_right(mode_t mode)
{
	ft_putchar((S_IRUSR & mode) ? 'r' : '-');
	ft_putchar((S_IWUSR & mode) ? 'w' : '-');
	if ((S_ISUID & mode) && (S_IXUSR & mode))
		ft_putchar('s');
	else if (S_ISUID & mode)
		ft_putchar('S');
	else
		ft_putchar((S_IXGRP & mode) ? 'x' : '-');
	ft_putchar((S_IRGRP & mode) ? 'r' : '-');
	ft_putchar((S_IWGRP & mode) ? 'w' : '-');
	if ((S_ISGID & mode) && (S_IXGRP & mode))
		ft_putchar('s');
	else if (S_ISGID & mode)
		ft_putchar('S');
	else
		ft_putchar((S_IXGRP & mode) ? 'x' : '-');
	ft_putchar((S_IROTH & mode) ? 'r' : '-');
	ft_putchar((S_IWOTH & mode) ? 'w' : '-');
	if ((S_ISVTX & mode) && (S_IXUSR & mode))
		ft_putchar('t');
	else if (S_ISVTX & mode)
		ft_putchar('T');
	else
		ft_putchar((S_IXOTH & mode) ? 'x' : '-');
}
