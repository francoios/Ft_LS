/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 18:53:27 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 15:06:09 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	char	**tab;
	int		i;
	t_bol	bol;

	i = -1;
	tab = (char **)ft_memalloc(sizeof(char *) * argc + 1);
	tab[argc] = NULL;
	while (++i < argc - 1)
		tab[i] = ft_strdup(argv[i + 1]);
	bol = ft_fetch_option(tab);
	tab += bol.tmp;
	if (tab[0] != NULL)
	{
		ft_first_check(tab);
		tab = ft_sort_ascii(tab, 0);
		ft_tab_split(tab, bol);
	}
	else
		ft_hub_dir(".", bol);
	return (0);
}
