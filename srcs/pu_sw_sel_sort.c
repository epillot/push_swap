/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_sw_sel_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:22:45 by epillot           #+#    #+#             */
/*   Updated: 2017/02/03 19:41:06 by epillot          ###   ########.fr       */
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

void		pu_sw_sel_sort(t_ll **la, t_ll **lb)
{
	int		pos_min;
	int		size;
	int		diff;
//	int		i;

//	i = 1;
	size = (*la)->size;
	while (size > 1)
	{
		pos_min = find_ll_min(*la);
		if ((diff = size - pos_min) >= size / 2)
		{
			while (diff < size - 1)
			{
				*la = (*la)->next;
				ft_putendl("ra");
				diff++;
			}
		}
		else
		{
			while (diff >= 0)
			{
				*la = (*la)->prev;
				ft_putendl("rra");
				diff--;
			}
		}
		exec_cmd_p("b", la, lb);
		ft_putendl("pb");
		size--;
	}
	size = (*lb)->size;
	while (size--)
	{
		exec_cmd_p("a", la, lb);
		ft_putendl("pa");
	}
}
