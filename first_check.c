/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 19:57:45 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:30:50 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_first_check(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == '\0')
		{
			ft_putstr_fd ("ft_ls: fts_open: No such file or directory\n", 2);
			exit (EXIT_FAILURE);
		}
		i++;
	}
}
