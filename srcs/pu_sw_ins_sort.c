/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_sw_ins_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:31:20 by epillot           #+#    #+#             */
/*   Updated: 2017/02/15 17:19:45 by epillot          ###   ########.fr       */
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
	while (i < size && l->val <= l->next->val)
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
	while (pos <= size && val >= l->val)
	{
		l = l->next;
		pos++;
	}
	return (pos);
}

static void	insert_in_a(t_ll **la, t_ll **lb, t_list **cmd)
{
	t_pos	pos;
	int		size;
	t_ll	*begin;

	if (!*lb)
		return ;
	pos.start = 1;
	size = (*lb)->size;
	begin = *la;
	while (size--)
	{
		pos.final = find_good_pos(begin, (*lb)->val);
		pos.start = ll_go_to(la, pos, "a", cmd);
		if (pos.final == 1)
			begin = (*lb);
		exec_cmd("pa", la, lb);
		add_cmd_in_list("p", "a", cmd);
	}
	pos.final = 1;
	ll_go_to(la, pos, "a", cmd);
}

t_list		*pu_sw_ins_sort(t_ll **la, t_ll **lb)
{
	int		size;
	t_ll	*begin;
	t_pos	pos;
	t_list	*cmd;

	cmd = NULL;
	begin = *la;
	size = (*la)->size;
	pos.start = 1;
	while ((pos.final = find_bad_elem(begin)))
	{
		pos.start = ll_go_to(la, pos, "a", &cmd);
		exec_cmd("pb", la, lb);
		add_cmd_in_list("p", "b", &cmd);
	}
	pos.final = 1;
	ll_go_to(la, pos, "a", &cmd);
	insert_in_a(la, lb, &cmd);
	return (cmd);
}
