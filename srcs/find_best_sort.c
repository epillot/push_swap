/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:00:01 by epillot           #+#    #+#             */
/*   Updated: 2017/02/15 18:37:48 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*save_ll(t_ll *l)
{
	int		*out;
	int		size;
	int		i;

	if (!l)
		return (NULL);
	size = l->size;
	i = 0;
	out = (int*)malloc(sizeof(int) * size);
	while (size--)
	{
		out[i++] = l->val;
		l = l->next;
	}
	return (out);
}

static int	get_best_sort(t_ll *la, int size, t_list *cmd[])
{
	int		i;
	int		min;

	i = 1;
	min = 0;
	if (is_mini_revlist(la) || size >= 300)
		return (4);
	else if (size >= 100)
	{
		min = 3;
		i = 4;
	}
	while (i < 5)
	{
		if (ft_lst_size(cmd[i]) < ft_lst_size(cmd[min]))
			min = i;
		i++;
	}
	return (min);
}

int			find_best_sort(t_ll **la, t_ll **lb, t_list *cmd[])
{
	int		*tab;
	int		i;

	tab = save_ll(*la);
	apply_good_sort(la, lb, tab, cmd);
	free(tab);
	i = get_best_sort(*la, (*la)->size, cmd);
	ll_free(la);
	return (i);
}
