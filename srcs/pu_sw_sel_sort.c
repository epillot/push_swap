/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_sw_sel_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:22:45 by epillot           #+#    #+#             */
/*   Updated: 2017/02/09 12:31:56 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_ll_min(t_ll *l)
{
	t_ll	*min;
	int		pos_min;
	int		pos;
	int		size;

	size = l->size;
	min = l;
	pos_min = 1;
	pos = 1;
	while (size--)
	{
		if (min->val > l->val)
		{
			min = l;
			pos_min = pos;
		}
		l = l->next;
		pos++;
	}
	return (pos_min);
}

t_list		*pu_sw_sel_sort(t_ll **la, t_ll **lb)
{
	t_pos	pos;
	int		size;
	t_list	*cmd;

	cmd = NULL;
	size = (*la)->size;
	pos.start = 1;
	while (size > 1)
	{
		pos.final = find_ll_min(*la);
		ll_go_to(la, pos, "a", &cmd);
		exec_cmd_p("b", la, lb);
		add_cmd_in_list("p", "b", &cmd);
		size--;
	}
	size = 0;
	if (*lb)
		size = (*lb)->size;
	while (size--)
	{
		exec_cmd_p("a", la, lb);
		add_cmd_in_list("p", "a", &cmd);
	}
	return (cmd);
}
