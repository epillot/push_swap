/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:14:51 by epillot           #+#    #+#             */
/*   Updated: 2017/02/16 15:36:48 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition_tab(int *tab, int start, int end)
{
	int		pos_pivot;
	int		pivot;
	int		i;
	int		tmp;

	pos_pivot = start;
	pivot = tab[start];
	i = start + 1;
	while (i <= end)
	{
		if (tab[i] < pivot)
		{
			pos_pivot++;
			tmp = tab[i];
			tab[i] = pivot;
			tab[pos_pivot] = tmp;
		}
		i++;
	}
	tmp = tab[start];
	tab[start] = tab[pos_pivot];
	tab[pos_pivot] = tmp;
	return (pos_pivot);
}

static void	quick_sort_tab(int *tab, int start, int end)
{
	int		pos_pivot;

	if (start < end)
	{
		pos_pivot = partition_tab(tab, start, end);
		quick_sort_tab(tab, start, pos_pivot - 1);
		quick_sort_tab(tab, pos_pivot + 1, end);
	}
}

int			get_median(t_ll *l, int size)
{
	int		*tab;
	int		i;
	int		median;

	i = 0;
	if (!(tab = malloc(sizeof(int) * size)))
		exit(EXIT_FAILURE);
	while (i < size)
	{
		tab[i++] = l->val;
		l = l->next;
	}
	quick_sort_tab(tab, 0, size - 1);
	median = tab[size / 2];
	free(tab);
	return (median);
}
