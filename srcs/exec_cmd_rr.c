/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:24:51 by epillot           #+#    #+#             */
/*   Updated: 2017/02/02 16:44:34 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		exec_cmd_rr(char *cmd, t_ll **la, t_ll **lb)
{
	if (*cmd == 'a')
	{
		if (*la)
			*la = (*la)->prev;
	}
	else if (*cmd == 'b')
	{
		if (*lb)
			*lb = (*lb)->prev;
	}
	else
	{
		if (*la)
			*la = (*la)->prev;
		if (*lb)
			*lb = (*lb)->prev;
	}
}
