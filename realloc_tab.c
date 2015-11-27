/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 12:19:25 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:32:31 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ft_realloc_tab(char **tab, char *str)
{
	char	**dest;
	int		len;
	int		i;

	len = ft_len_tab(tab);
	dest = (char **)ft_memalloc(sizeof(char *) * (len + 1) + 1);
	i = 0;
	while (tab[i])
	{
		dest[i] = ft_strdup(tab[i]);
		i++;
	}
	dest[i] = ft_strdup(str);
	dest[i + 1] = NULL;
	ft_free_tab(tab, 0);
	return (dest);
}
