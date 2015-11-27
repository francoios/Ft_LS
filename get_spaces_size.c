/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spaces_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:04:10 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:31:30 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_fuck_size(int *size1, int *size2, t_stat buf)
{
	if (getpwuid(buf.st_uid) == NULL)
		*size1 = ft_get_nb_size(*size1, buf.st_uid);
	else
		*size1 = ft_name_size((getpwuid(buf.st_uid)->pw_name), *size1);
	if (getgrgid(buf.st_gid) == NULL)
		*size2 = ft_get_nb_size(*size2, buf.st_gid);
	else
		*size2 = ft_name_size(getgrgid(buf.st_gid)->gr_name, *size2);
}

int		*ft_super_fuck_size(int *size)
{
	if (size[3] < size[4] + size[5] + 2)
		size[3] = size[4] + size[5] + 2;
	else
		size[4] = size[3] + (size[5] + 2);
	return (size);
}

int		*ft_get_spaces_size(int *size, char **tab, char *dir, t_bol bol)
{
	int		i;
	t_stat	buf;

	size = ft_init_int();
	i = 0;
	while (tab[i])
	{
		if (bol.a == 0 && tab[i][0] == '.')
		{
			i++;
			continue;
		}
		buf = ft_get_stat(dir, tab[i]);
		size[0] = ft_get_nb_size(size[0], buf.st_nlink);
		ft_fuck_size(size + 1, size + 2, buf);
		size[3] = ft_get_nb_size(size[3], buf.st_size);
		if (S_ISBLK(buf.st_mode) || S_ISCHR(buf.st_mode))
		{
			size[4] = 3;
			size[5] = ft_get_nb_size(size[5], minor(buf.st_rdev));
		}
		size[6] += buf.st_blocks;
		i++;
	}
	return (ft_super_fuck_size(size));
}
