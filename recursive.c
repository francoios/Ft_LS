/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 13:41:18 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:32:36 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_free(char *path, char **dir)
{
	free(path);
	ft_free_tab(dir, 0);
}

void	ft_recursive(char **dir, t_bol bol, char *path)
{
	int		i;
	t_stat	buf;
	char	*file;

	bol.multi = 1;
	i = 0;
	while (dir[i])
	{
		buf = ft_get_stat(path, dir[i]);
		if (S_ISDIR(buf.st_mode) && dir[i][0] != '\0'
			&& (ft_strcmp(dir[i], ".") != 0) && (ft_strcmp(dir[i], "..") != 0))
		{
			file = ft_strjoin(path, dir[i]);
			if (bol.a == 0 && dir[i][0] == '.')
				bol.hidprint = 1;
			else
				bol.hidprint = 0;
			if (bol.hidprint == 0)
				ft_putchar('\n');
			ft_hub_dir(file, bol);
			free(file);
		}
		i++;
	}
	ft_free(path, dir);
}
