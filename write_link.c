/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 21:12:21 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:33:20 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_write_link(char *str, char *path)
{
	char	buf[4096];
	int		len;
	char	*link;

	ft_putstr(str);
	link = ft_strjoin(path, str);
	len = readlink(link, buf, sizeof(buf) - 1);
	if (len != -1)
	{
		buf[len] = '\0';
		ft_putstr(" -> ");
		ft_putstr(buf);
	}
	free(link);
	ft_putchar('\n');
}
