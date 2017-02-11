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
	int		size1 = 0, size2 = 0;

	if (size <= 1)
		return ;
	i = 1;
	piv = *la;
	while (size > 0)
	{
		if ((*la)->val < piv->val)
		{
			exec_cmd_p("b", la, lb);
			add_cmd_in_list("p", "b", cmd);
			size1++;
		}
		else
		{
			
			(*la) = (*la)->next;
			add_cmd_in_list("r", "a", cmd);
			size2++;
		}
		size--;
	}
	i = 1;
	pos.start = size2 + 1;
	pos.final = 1;
	ll_go_to(la, pos, "a", cmd);
	while (i++ <= size1)
	{
		exec_cmd_p("a", la, lb);
		add_cmd_in_list("p", "a", cmd);
	}
	quick_sort_aux(la, lb, size1, cmd);
	pos.start = 1;
	pos.final = size1 + 2;
	pos.start = ll_go_to(la, pos, "a", cmd);
	quick_sort_aux(la, lb, size2 - 1, cmd);
	pos.final = 1;
	ll_go_to(la, pos, "a", cmd);
	
}

t_list		*pu_sw_quick_sort(t_ll **la, t_ll **lb)
{
	t_list	*cmd;

	cmd = NULL;
	quick_sort_aux(la, lb, (*la)->size, &cmd);
	return (cmd);
}
