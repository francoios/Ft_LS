/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 10:28:44 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:30:18 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_mini_write(t_stat buf, char *tab, char *path)
{
	ft_write_time(&buf.st_mtime);
	ft_write_link(tab, path);
}

void	ft_write_l(char *tab, int *size, char *path)
{
	t_stat buf;

	buf = ft_get_stat(path, tab);
	if (buf.st_atime == 0)
		return ;
	ft_write_types(buf.st_mode);
	ft_write_right(buf.st_mode);
	ft_write_atx(tab);
	ft_write_nb(size[0], buf.st_nlink);
	if (getpwuid(buf.st_uid) == NULL)
		ft_write_nb_gid(size[1], (buf.st_uid));
	else
		ft_write_str((getpwuid(buf.st_uid)->pw_name), size[1]);
	if (getgrgid(buf.st_gid) == NULL)
		ft_write_nb_gid(size[2], buf.st_gid);
	else
		ft_write_str((getgrgid(buf.st_gid)->gr_name), size[2]);
	if (S_ISBLK(buf.st_mode) || S_ISCHR(buf.st_mode))
		ft_write_maj_min(size, major(buf.st_rdev), minor(buf.st_rdev));
	else
		ft_write_nb(size[3], buf.st_size);
	ft_mini_write(buf, tab, path);
}
