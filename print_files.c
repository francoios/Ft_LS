/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 14:41:31 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:32:20 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bol	ft_print_files(char **files, t_bol bol)
{
	int i;

	i = 0;
	if (files[0] != NULL)
		bol.multi = 1;
	if (bol.l == 1)
	{
		ft_print_files_l(files);
		ft_free_tab(files, 0);
		return (bol);
	}
	while (files[i])
	{
		ft_putendl(files[i]);
		i++;
	}
	ft_free_tab(files, 0);
	return (bol);
}
