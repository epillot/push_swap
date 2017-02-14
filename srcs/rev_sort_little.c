/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_sw_ins_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:31:20 by epillot           #+#    #+#             */
/*   Updated: 2017/02/11 18:53:38 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_bad_elem(t_ll *l)
{
	int	size;
	int	i;

	if (!l)
		return (0);	
	i = 1;
	size = l->size;
	while (i < size && l->val > l->next->val)
	{
		l = l->next;
		i++;
	}
	if (i == size)
		return (0);
	return (i + 1);
}

static int	find_good_pos(t_ll *l, int val)
{
	int pos;
	int size;
	
	
	pos = 1;
	if (!l)
		return (1);
	size = l->size;
	while (pos <= size && val <= l->val)
	{
		l = l->next;
		pos++;
	}
	return (pos);
}

void	rev_sort_little(t_ll **lb, t_ll **la, t_list **cmd)
{
	t_ll	*begin;
	t_pos	pos;
	int	i;

	i = 0;
	begin = *lb;
	pos.start = 1;
	while ((pos.final = find_bad_elem(begin)))
	{
		pos.start = ll_go_to(lb, pos, "b", cmd);
		exec_cmd_p("a", la, lb);
		add_cmd_in_list("p", "a", cmd);
		i++;
	}
	while (i--)
	{
		pos.final = find_good_pos(begin, (*la)->val);
		pos.start = ll_go_to(lb, pos, "b", cmd);
		if (pos.final == 1)
			begin = (*lb);
		exec_cmd_p("b", la, lb);
		add_cmd_in_list("p", "b", cmd);
	}
	pos.final = 1;
	ll_go_to(lb, pos, "b", cmd);
}
