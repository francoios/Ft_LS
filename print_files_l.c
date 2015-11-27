/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 14:42:13 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:32:26 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_files_l(char **tab)
{
	int		i;
	int		*size;
	t_bol	bol;

	bol.a = 1;
	size = (int *)malloc(0);
	size = ft_get_spaces_size(size, tab, "", bol);
	i = 0;
	while (tab[i])
		ft_write_l(tab[i++], size, "");
}
