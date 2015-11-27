/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 13:20:05 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:37:15 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sort_sup_time(t_info *tmp, t_info *tmp2)
{
	while (tmp->next && (tmp2->time.st_mtime >= tmp->time.st_mtime))
		tmp = tmp->next;
	if (tmp2->time.st_mtime < tmp->time.st_mtime)
	{
		tmp2->next = tmp;
		tmp2->prev = tmp->prev;
		if (tmp->prev)
			tmp->prev->next = tmp2;
		tmp->prev = tmp2;
	}
	else
	{
		tmp->next = tmp2;
		tmp2->next = NULL;
		tmp2->prev = tmp;
	}
}

void	ft_sort_inf_time(t_info *tmp, t_info *tmp2)
{
	while (tmp->prev && (tmp2->time.st_mtime <= tmp->time.st_mtime))
		tmp = tmp->prev;
	if (tmp2->time.st_mtime > tmp->time.st_mtime)
	{
		tmp2->prev = tmp;
		tmp2->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = tmp2;
		tmp->next = tmp2;
	}
	else
	{
		tmp->prev = tmp2;
		tmp2->prev = NULL;
		tmp2->next = tmp;
	}
}

char	**ft_no_r_time(char **tab, t_info *tmp, int r)
{
	int	i;

	i = 0;
	if (r == 0)
	{
		while (tmp->next)
			tmp = tmp->next;
		while (tmp->prev)
		{
			tab[i++] = tmp->file_name;
			tmp = tmp->prev;
		}
	}
	else
	{
		while (tmp->prev)
			tmp = tmp->prev;
		while (tmp->next)
		{
			tab[i++] = tmp->file_name;
			tmp = tmp->next;
		}
	}
	tab[i] = tmp->file_name;
	return (tab);
}

t_info	*ft_get_info_time(char *tab, char *dir, t_info *tmp2)
{
	char *buff;

	buff = ft_strjoin(dir, tab);
	tmp2 = (t_info*)malloc(sizeof(t_info));
	lstat(buff, &(tmp2->time));
	tmp2->file_name = tab;
	tmp2->next = NULL;
	tmp2->prev = NULL;
	return (tmp2);
}

char	**ft_sort_time(char **tab, char *dir, t_bol bol)
{
	t_info		*tmp;
	t_info		*tmp2;
	int			i;

	i = 0;
	tmp = NULL;
	while (tab[i])
	{
		tmp2 = ft_get_info_time(tab[i], dir, tmp2);
		if (tmp == NULL)
		{
			tmp = tmp2;
			i++;
			continue;
		}
		if (tmp2->time.st_mtime > tmp->time.st_mtime)
			ft_sort_sup_time(tmp, tmp2);
		else
			ft_sort_inf_time(tmp, tmp2);
		i++;
	}
	return (ft_no_r_time(tab, tmp, bol.r));
}
