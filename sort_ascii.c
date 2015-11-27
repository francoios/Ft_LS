/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 13:20:05 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:37:31 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sort_sup_ascii(t_info *tmp, t_info *tmp2)
{
	while (ft_strcmp(tmp2->file_name, tmp->file_name) <= 0 && tmp->next != NULL)
		tmp = tmp->next;
	if (ft_strcmp(tmp2->file_name, tmp->file_name) > 0)
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

void	ft_sort_inf_ascii(t_info *tmp, t_info *tmp2)
{
	while (ft_strcmp(tmp2->file_name, tmp->file_name) >= 0 && tmp->prev != NULL)
		tmp = tmp->prev;
	if (ft_strcmp(tmp2->file_name, tmp->file_name) < 0)
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

char	**ft_no_r_ascii(char **tab, t_info *tmp, int r)
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

t_info	*ft_get_info_ascii(char *tab, t_info *tmp2)
{
	tmp2 = (t_info*)malloc(sizeof(t_info));
	tmp2->file_name = tab;
	tmp2->next = NULL;
	tmp2->prev = NULL;
	return (tmp2);
}

char	**ft_sort_ascii(char **tab, int r)
{
	t_info		*tmp;
	t_info		*tmp2;
	int			i;

	i = 0;
	tmp = NULL;
	while (tab[i])
	{
		tmp2 = ft_get_info_ascii(tab[i], tmp2);
		if (tmp == NULL)
		{
			tmp = tmp2;
			i++;
			continue;
		}
		if (ft_strcmp(tmp2->file_name, tmp->file_name) < 0)
			ft_sort_sup_ascii(tmp, tmp2);
		else
			ft_sort_inf_ascii(tmp, tmp2);
		i++;
	}
	return (ft_no_r_ascii(tab, tmp, r));
}
