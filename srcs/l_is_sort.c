/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_is_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:24:53 by epillot           #+#    #+#             */
/*   Updated: 2017/02/16 12:45:50 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	l_is_sort_right(t_ll *l)
{
	int		act;
	int		prev;
	int		size;

	if (l)
	{
		prev = INT_MIN;
		size = l->size;
		while (size--)
		{
			act = l->val;
			if (act < prev)
				return (0);
			prev = act;
			l = l->next;
		}
	}
	return (1);
}

static int	l_is_sort_left(t_ll *l)
{
	int		act;
	int		prev;
	int		size;

	if (l)
	{
		prev = INT_MAX;
		size = l->size;
		while (size--)
		{
			act = l->val;
			if (act > prev)
				return (0);
			prev = act;
			l = l->prev;
		}
	}
	return (1);
}

int			l_is_sort(t_ll *l, int way)
{
	if (way == 0)
		return (l_is_sort_right(l));
	else
		return (l_is_sort_left(l));
}
