/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dir_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 12:06:28 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:32:47 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_sort_dir_files(char *str, t_bol bol)
{
	DIR		*ret;
	t_stat	buf;

	ret = opendir(str);
	if (ret == NULL && errno == 20)
		return (1);
	else if (ret == NULL)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(str, 2);
		perror(" ");
		return (-1);
	}
	else
	{
		lstat(str, &buf);
		if (S_ISLNK(buf.st_mode) && bol.l == 1)
			return (1);
		closedir(ret);
		return (0);
	}
	return (0);
}
