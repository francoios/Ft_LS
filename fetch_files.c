/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 12:20:17 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 15:17:11 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ft_fetch_files(char *dir_name, char **files)
{
	DIR		*rep;
	t_dir	*dir;
	int		i;

	i = 0;
	rep = opendir(dir_name);
	while ((dir = readdir(rep)) != NULL)
	{
		files[i] = ft_strdup(dir->d_name);
		i++;
	}
	files[i] = NULL;
	closedir(rep);
	return (files);
}
