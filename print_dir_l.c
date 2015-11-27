/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 12:17:37 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:32:16 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_dir_l(char *path, char **files, t_bol bol)
{
	int		*size;
	int		i;

	i = 0;
	size = (int *)ft_memalloc(0);
	size = ft_get_spaces_size(size, files, path, bol);
	if (ft_get_hide(files) == 1 || bol.a == 1)
	{
		ft_putstr("total ");
		ft_putnbr(size[6]);
		ft_putchar('\n');
	}
	while (files[i])
	{
		if (bol.a == 0 && files[i][0] == '.')
			i++;
		else
		{
			ft_write_l(files[i], size, path);
			i++;
		}
	}
}
