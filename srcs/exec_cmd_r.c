/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:15:36 by epillot           #+#    #+#             */
/*   Updated: 2017/02/02 16:59:05 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		exec_cmd_r(char *cmd, t_ll **la, t_ll **lb)
{
	if (*cmd == 'a')
	{
		if (*la)
			*la = (*la)->next;
	}
	else if (*cmd == 'b')
	{
		if (*lb)
			*lb = (*lb)->next;
	}
	else
	{
		if (*la)
			*la = (*la)->next;
		if (*lb)
			*lb = (*lb)->next;
	}
}
