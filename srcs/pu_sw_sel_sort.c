/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_sw_sel_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:22:45 by epillot           #+#    #+#             */
/*   Updated: 2017/02/16 12:39:49 by epillot          ###   ########.fr       */
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

static void	check_swap(t_ll *l, int size, t_list **cmd)
{
	if (size != 3)
		return ;
	if (l->val > l->next->val)
	{
		ll_swap(l);
		add_cmd_in_list("s", "a", cmd);
	}
}

t_list		*pu_sw_sel_sort(t_ll **la, t_ll **lb)
{
	t_pos	pos;
	int		size;
	t_list	*cmd;

	cmd = NULL;
	size = (*la)->size;
	check_swap(*la, size, &cmd);
	pos.start = 1;
	while (size > 1)
	{
		pos.final = find_ll_min(*la);
		ll_go_to(la, pos, "a", &cmd);
		exec_cmd("pb", la, lb);
		add_cmd_in_list("p", "b", &cmd);
		size--;
	}
	size = 0;
	if (*lb)
		size = (*lb)->size;
	while (size--)
	{
		exec_cmd("pa", la, lb);
		add_cmd_in_list("p", "a", &cmd);
	}
	return (cmd);
}
