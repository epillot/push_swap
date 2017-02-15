/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:06:19 by epillot           #+#    #+#             */
/*   Updated: 2017/02/15 16:53:44 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bub_sort_next(t_ll *l, int size, t_list **cmd)
{
	int		i;

	i = 0;
	while (i < size - 1)
	{
		if (l->val > l->next->val)
		{
			ll_swap(l);
			add_cmd_in_list("s", "a", cmd);
		}
		l = l->next;
		add_cmd_in_list("r", "a", cmd);
		i++;
	}
}

static void	bub_sort_prev(t_ll *l, int size, t_list **cmd)
{
	int		i;

	i = 0;
	while (i < size - 1)
	{
		l = l->prev;
		add_cmd_in_list("rr", "a", cmd);
		if (l->val > l->next->val)
		{
			ll_swap(l);
			add_cmd_in_list("s", "a", cmd);
		}
		i++;
	}
}

t_list		*pu_sw_bubble_sort(t_ll *l)
{
	int		size;
	t_ll	*begin;
	t_list	*cmd;

	size = l->size;
	if (size < 2)
		return (NULL);
	begin = l;
	cmd = NULL;
	while (!(l_is_sort(begin, 0)))
	{
		bub_sort_next(l, size, &cmd);
		bub_sort_prev(l->prev, size, &cmd);
	}
	return (cmd);
}
