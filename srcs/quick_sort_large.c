/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_sw_quick_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:42:20 by epillot           #+#    #+#             */
/*   Updated: 2017/02/15 16:30:59 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_pos_piv(t_ll *l, int val)
{
	int		i;

	i = 1;
	if (!l)
		return (0);
	while (l->val != val)
	{
		i++;
		l = l->next;
	}
	return (i);
}

static int	partition2(t_ll **la, t_ll **lb, int piv, t_list **cmd)
{
	t_pos	pos;
	int		i;
	int		size;

	if (!*lb)
		return (0);
	pos.start = 1;
	pos.final = find_pos_piv(*lb, piv);
	ll_go_to(lb, pos, "b", cmd);
	size = (*lb)->size;
	i = 1;
	while (i++ <= size)
	{
		exec_cmd("pa", la, lb);
		add_cmd_in_list("p", "a", cmd);
	}
	return (size);
}

static int	partition(t_ll **la, t_ll **lb, int size, t_list **cmd)
{
	int		piv;
	t_pos	pos;
	int		i;
	t_ll	*begin;

	piv = get_median(*la, size);
	begin = *la;
	pos.start = 1;
	i = 0;
	while ((pos.final = find_lower_elem(begin, piv, size)))
	{
		pos.start = ll_go_to(la, pos, "a", cmd);
		exec_cmd("pb", la, lb);
		add_cmd_in_list("p", "b", cmd);
		if (pos.final == 1)
			begin = (*la);
		size--;
		i++;
	}
	pos.final = 1;
	ll_go_to(la, pos, "a", cmd);
	return (partition2(la, lb, piv, cmd));
}

static void	quick_sort_aux(t_ll **la, t_ll **lb, int size, t_list **cmd)
{
	t_pos	pos;
	int		size_in;

	if (size <= 1)
		return ;
	size_in = size;
	if (size >= 25)
	{
		size = partition(la, lb, size, cmd);
		quick_sort_aux(la, lb, size - 1, cmd);
		pos.start = 1;
		pos.final = size + 1;
		pos.start = ll_go_to(la, pos, "a", cmd);
		quick_sort_aux(la, lb, size_in - size, cmd);
		pos.final = 1;
		ll_go_to(la, pos, "a", cmd);
	}
	else
		sort_little_part(la, lb, size, cmd);
}

t_list		*quick_sort_large(t_ll **la, t_ll **lb)
{
	t_list	*cmd;

	cmd = NULL;
	quick_sort_aux(la, lb, (*la)->size, &cmd);
	return (cmd);
}
