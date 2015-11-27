/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 12:20:06 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:30:30 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_count_files(char *dir_name)
{
	DIR		*rep;
	t_dir	*dir;
	int		i;

	i = 0;
	rep = opendir(dir_name);
	if (rep == NULL)
	{
		ft_putstr_fd("ft_ls: ", 2);
		while (dir_name[i])
			i++;
		while (i > 0 && dir_name[i - 1] != '/')
			i--;
		ft_putstr_fd(dir_name + i, 2);
		perror(" ");
		return (-1);
	}
	i = 0;
	while ((dir = readdir(rep)) != NULL)
		i++;
	closedir(rep);
	return (i);
}
