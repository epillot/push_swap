/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:56:35 by epillot           #+#    #+#             */
/*   Updated: 2017/02/03 19:13:47 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_push(t_ll **on, t_ll **from)
{
	t_ll	*tmp;

	if (!*from)
		return ;
	tmp = *from;
	if ((*from)->size > 1)
	{
		(*from)->prev->next = (*from)->next;
		(*from)->next->prev = (*from)->prev;
		(*from) = (*from)->next;
		ll_size_rec(*from, (*from)->size - 1);
	}
	else
		(*from) = NULL;
	ll_addfront(on, tmp);
}

void		exec_cmd_p(char *cmd, t_ll **la, t_ll **lb)
{
	if (*cmd == 'a')
		exec_push(la, lb);
	else
		exec_push(lb, la);
}
