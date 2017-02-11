/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_sw_quick_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:42:20 by epillot           #+#    #+#             */
/*   Updated: 2017/02/11 19:14:06 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_lower_elem(t_ll *l, int val, int size)
{
	int		pos;

	pos = 1;
	while (pos <= size)
	{
		if (l->val < val)
			return (pos);
		l = l->next;
		pos++;
	}
	return (0);
}

static int	partition(t_ll **la, t_ll **lb, int size, t_list **cmd)
{
	t_ll	*piv;
	t_pos	pos;
	int		i;
	t_ll	*tmp;
	int		pos_piv;

	pos_piv = piv = *la;
	tmp = *la;
	pos.start = 1;
	while ((pos.final = find_lower_elem(tmp, piv->val, size)))
	{
		pos.start = ll_go_to(la, pos, "a", cmd);
		exec_cmd_p("b", la, lb);
		add_cmd_in_list("p", "b", cmd);
		size--;
	}
	i = 1;
	pos.final = 1;
	ll_go_to(la, pos, "a", cmd);
	size = 0;
	if (*lb)
		size = (*lb)->size;
	while (i++ <= size)
	{
		exec_cmd_p("a", la, lb);
		add_cmd_in_list("p", "a", cmd);
	}
	return (size);
}

void		quick_sort_aux(t_ll **la, t_ll **lb, int size, t_list **cmd)
{
	t_pos	pos;
	int		size_in;

	if (size <= 1)
		return ;
	size_in = size;
	size = partition(la, lb, size, cmd);
	quick_sort_aux(la, lb, size, cmd);
	pos.start = 1;
	pos.final = size + 2;
	pos.start = ll_go_to(la, pos, "a", cmd);
	quick_sort_aux(la, lb, size_in - size - 1, cmd);
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
