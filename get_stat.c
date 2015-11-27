/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 22:31:44 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:31:35 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_stat	ft_get_stat(char *dir, char *str)
{
	t_stat	buf;
	t_stat	err;
	char	*s;

	err.st_atime = 0;
	s = ft_strjoin(dir, str);
	if (lstat(s, &buf) == -1)
	{
		ft_putstr_fd("ft_ls:", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		perror("");
		free(s);
		return (err);
	}
	free(s);
	return (buf);
}
