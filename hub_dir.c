/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 12:22:17 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 15:14:09 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_hub_dir(char *dir, t_bol bol)
{
	char	**files;
	char	*path;
	int		len;

	len = ft_count_files(dir);
	if (len == -1)
		return ;
	files = (char **)malloc(sizeof(char *) * len + 1);
	files = ft_fetch_files(dir, files);
	path = ft_strjoin(dir, "/");
	if (bol.t == 1 && files[0] != NULL)
	{
		files = ft_sort_ascii(files, 0);
		files = ft_sort_time(files, path, bol);
	}
	else if (files[0] != NULL)
		files = ft_sort_ascii(files, bol.r);
	ft_print_dir(files, bol, dir);
	free(path);
}
