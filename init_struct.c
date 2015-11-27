/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 19:04:57 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:31:49 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bol	ft_init_struct(void)
{
	t_bol bol;

	bol.a = 0;
	bol.l = 0;
	bol.r = 0;
	bol.t = 0;
	bol.re = 0;
	bol.multi = 0;
	bol.hidprint = 0;
	return (bol);
}
