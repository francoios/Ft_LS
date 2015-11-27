/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 10:01:50 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:32:53 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ft_mini_sort(char **tab, t_bol bol)
{
	if (tab[0] != NULL)
	{
		if (bol.t == 1)
		{
			tab = ft_sort_ascii(tab, 0);
			tab = ft_sort_time(tab, "", bol);
		}
		else
			tab = ft_sort_ascii(tab, bol.r);
	}
	return (tab);
}

void	ft_sort_tab(char **files, char **dir, t_bol bol)
{
	int i;

	i = 0;
	files = ft_mini_sort(files, bol);
	dir = ft_mini_sort(dir, bol);
	bol = ft_print_files(files, bol);
	if (bol.multi == 1 && (dir[0] != NULL))
		ft_putchar('\n');
	if (dir[1] != NULL)
		bol.multi = 1;
	while (dir[i])
	{
		if (i > 0 && bol.multi == 1)
			ft_putchar('\n');
		ft_hub_dir(dir[i++], bol);
	}
}
