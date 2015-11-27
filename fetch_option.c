/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 19:20:30 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/28 09:42:18 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bol	ft_catch_option(char *s, t_bol bol)
{
	int	i;

	i = 0;
	while (s[++i])
	{
		if (s[i] == 'l')
			bol.l = 1;
		else if (s[i] == 'r')
			bol.r = 1;
		else if (s[i] == 'R')
			bol.re = 1;
		else if (s[i] == 'a')
			bol.a = 1;
		else if (s[i] == 't')
			bol.t = 1;
		else if (s[i] != '1')
		{
			ft_putstr_fd ("ft_ls: illegal option -- ", 2);
			ft_putchar_fd (s[i], 2);
			ft_putchar_fd ('\n', 2);
			ft_putstr_fd ("usage ft_ls [-Ralrt] [file ...]\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	return (bol);
}

t_bol	ft_fetch_option(char **tab)
{
	t_bol	bol;
	int		i;

	i = 0;
	bol = ft_init_struct();
	while (tab[i] && tab[i][0] == '-')
	{
		if (tab[i][1] == '\0')
			break ;
		else if (tab[i][1] == '-' && tab[i][2] == '\0')
		{
			i++;
			break ;
		}
		else
			bol = ft_catch_option(tab[i], bol);
		i++;
	}
	bol.tmp = i;
	return (bol);
}
