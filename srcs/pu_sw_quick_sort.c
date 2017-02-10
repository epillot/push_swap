/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_sw_quick_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:42:20 by epillot           #+#    #+#             */
/*   Updated: 2017/02/10 19:57:08 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		quick_sort_aux(t_ll **la, t_ll **lb, int size, t_list **cmd)
{
	t_ll	*piv;
	t_pos	pos;
	int		i;
	int		size1 = size, size2 = 0;

	if (size <= 1)
		return ;
	i = 1;
	piv = *la;
	*la = (*la)->next;
	add_cmd_in_list("r", "a", cmd);
	while (i < size)
	{
		if ((*la)->val < piv->val)
		{
			exec_cmd_p("b", la, lb);
			add_cmd_in_list("p", "b", cmd);
			size2++;
			size1--;
		}
		else
		{
			(*la) = (*la)->next;
			add_cmd_in_list("r", "a", cmd);
		}
		i++;
	}
	pos.start = size2 + 1;
	pos.final = 1;
	ll_go_to(la, pos, "a", cmd);
	pos.final = pos.start;
	pos.start = 1;
	i = 1;
	while (i++ <= size2)
	{
		exec_cmd_p("a", la, lb);
		add_cmd_in_list("p", "a", cmd);
	}
	ll_go_to(la, pos, "a", cmd);
//	ll_go_to(la, pos, "a", cmd);
//	quick_sort_aux(la, lb, size2, cmd);
/*	pos.start = 1;
	pos.final = size2 + 2;
	pos.start = ll_go_to(la, pos, "a", cmd);
	quick_sort_aux(la, lb, size - size2 - 1, cmd);
	pos.final = 1;
	ll_go_to(la, pos, "a", cmd);*/
}

t_list		*pu_sw_quick_sort(t_ll **la, t_ll **lb)
{
	t_list	*cmd;

	cmd = NULL;
	quick_sort_aux(la, lb, (*la)->size, &cmd);
	return (cmd);
}
