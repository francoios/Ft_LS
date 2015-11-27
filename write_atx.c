/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_atx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 19:16:12 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:33:10 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_write_atx(char *str)
{
	char buf[1024];

	if (listxattr(str, buf, 1024, 0) > 0)
		ft_putstr("@ ");
	else if (acl_get_file(str, ACL_TYPE_EXTENDED))
		ft_putstr("+ ");
	else
		ft_putstr("  ");
}
