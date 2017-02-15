/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_medium.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:11:03 by epillot           #+#    #+#             */
/*   Updated: 2017/02/15 16:28:13 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_ll(t_ll **la, t_ll **lb, int size, t_list **cmd)
{
	int		piv;
	t_pos	pos;
	t_ll	*begin;

	piv = get_median(*la, size);
	begin = *la;
	pos.start = 1;
	while ((pos.final = find_lower_elem(begin, piv, size)))
	{
		pos.start = ll_go_to(la, pos, "a", cmd);
		exec_cmd("pb", la, lb);
		add_cmd_in_list("p", "b", cmd);
		if (pos.final == 1)
			begin = (*la);
		size--;
	}
	pos.final = 1;
	ll_go_to(la, pos, "a", cmd);
}

static int	find_ll_max(t_ll *l)
{
	int		pos;
	int		pos_max;
	int		size;
	t_ll	*max;

	if (l->size == 1)
		return (1);
	pos = 2;
	pos_max = 1;
	max = l;
	l = l->next;
	size = l->size;
	while (pos <= size)
	{
		if (l->val > max->val)
		{
			pos_max = pos;
			max = l;
		}
		l = l->next;
		pos++;
	}
	return (pos_max);
}

static void	quick_sort_medium_aux(t_ll **la, t_ll **lb, t_list **cmd)
{
	t_pos	pos;
	int		size;

	if (!*la || (*la)->size == 1)
		return ;
	while ((*la)->size >= 3)
		split_ll(la, lb, (*la)->size, cmd);
	if ((*la)->val > (*la)->next->val)
	{
		ll_swap(*la);
		add_cmd_in_list("s", "a", cmd);
	}
	size = 0;
	if (*lb)
		size = (*lb)->size;
	pos.start = 1;
	while (size--)
	{
		pos.final = find_ll_max((*lb));
		ll_go_to(lb, pos, "b", cmd);
		exec_cmd("pa", la, lb);
		add_cmd_in_list("p", "a", cmd);
	}
}

t_list		*quick_sort_medium(t_ll **la, t_ll **lb)
{
	t_list	*cmd;

	cmd = NULL;
	quick_sort_medium_aux(la, lb, &cmd);
	return (cmd);
}
