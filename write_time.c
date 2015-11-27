/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 20:47:24 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/28 10:11:37 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_write_time(time_t *tm)
{
	char	*str;
	int		i;

	i = 4;
	str = ctime(tm);
	while (i < 16)
	{
		if (((*tm < time(NULL) - 15778458) || (*tm > time(NULL))) && i > 10)
			ft_putchar(str[i + 8]);
		else
			ft_putchar(str[i]);
		i++;
	}
	ft_putchar(' ');
}
