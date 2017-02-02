/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:59:47 by epillot           #+#    #+#             */
/*   Updated: 2017/02/02 16:44:23 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		exec_cmd_s(char *cmd, t_ll *la, t_ll *lb)
{
	if (*cmd == 'a')
	{
		if (la)
			ll_swap(la);
	}
	else if (*cmd == 'b')
	{
		if (lb)
			ll_swap(lb);
	}
	else
	{
		if (la)
			ll_swap(la);
		if (lb)
			ll_swap(lb);
	}
}
