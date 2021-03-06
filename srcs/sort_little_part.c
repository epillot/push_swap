/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little_part.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:29:57 by epillot           #+#    #+#             */
/*   Updated: 2017/02/15 17:23:36 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_bad_elem(t_ll *l, int size)
{
	int	i;

	if (!l)
		return (0);
	i = 1;
	while (i < size && l->val < l->next->val)
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

	pos = 1;
	if (!l)
		return (1);
	while (val >= l->val)
	{
		l = l->next;
		pos++;
	}
	return (pos);
}

void		sort_little_part(t_ll **la, t_ll **lb, int size, t_list **cmd)
{
	t_ll	*begin;
	t_pos	pos;
	int		i;

	i = 0;
	begin = *la;
	pos.start = 1;
	while ((pos.final = find_bad_elem(begin, size - i)))
	{
		pos.start = ll_go_to(la, pos, "a", cmd);
		exec_cmd("pb", la, lb);
		add_cmd_in_list("p", "b", cmd);
		i++;
	}
	while (i--)
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
