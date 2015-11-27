/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 12:17:34 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 15:17:34 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_dir(char **dir, t_bol bol, char *path)
{
	int i;

	i = 0;
	if (bol.multi == 1 && bol.hidprint == 0)
	{
		ft_putstr(path);
		ft_putendl(":");
	}
	path = ft_strjoin(path, "/");
	if (bol.l == 1 && bol.hidprint == 0)
		ft_print_dir_l(path, dir, bol);
	else
	{
		while (dir[i])
		{
			if ((bol.a == 1 && bol.hidprint == 0)
				|| (bol.a == 0 && dir[i][0] != '.' && bol.hidprint == 0))
				ft_putendl(dir[i]);
			i++;
		}
	}
	if (bol.re == 1)
		ft_recursive(dir, bol, path);
}
