/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 12:06:01 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:33:04 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_tab_split(char **tab, t_bol bol)
{
	char	**dir;
	char	**files;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	dir = (char **)ft_memalloc(sizeof(char *) * 1);
	files = (char **)ft_memalloc(sizeof(char *) * 1);
	dir[0] = NULL;
	files[0] = NULL;
	while (tab[i])
	{
		ret = ft_sort_dir_files(tab[i], bol);
		if (ret == 1)
			files = ft_realloc_tab(files, tab[i]);
		else if (ret == 0)
			dir = ft_realloc_tab(dir, tab[i]);
		i++;
	}
	ft_free_tab(tab, bol.tmp);
	ft_sort_tab(files, dir, bol);
}
