/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 14:52:13 by epillot           #+#    #+#             */
/*   Updated: 2017/02/01 19:17:45 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    print_l(t_list *l);

static int	*init_tab(t_list *l, int size)
{
	int		*tab;
	int		i;

	i = 0;
	tab = (int*)malloc(size * sizeof(int));
	while (l)
	{
		tab[i] = VALUE(l);
		l = l->next;
		i++;
	}
	return (tab);
}

void		quick_sort_tab(int *tab, int start, int end)
{
	int		pivot;
	int		left;
	int		right;
	int		tmp;

	if (start >= end)
		return ;
	pivot = tab[start];
	left = start - 1;
	right = end + 1;
	while (1)
	{
		while (1)
		{
			left++;
			if (tab[left] >= pivot)
				break ;
		}
		while (1)
		{
			right--;
			if (tab[right] <= pivot)
				break ;
		}
		if (left < right)
		{
			tmp = tab[left];
			tab[left] = tab[right];
			tab[right] = tmp;
		}
		else
			break ;
	}
	quick_sort_tab(tab, start, right);// - 1);
	quick_sort_tab(tab, right + 1, end);

}

void		quick_sort(t_list *l)
{
	int		*tab;
	int		i;
	int		size;

	size = ft_lst_size(l);
	tab = init_tab(l, size);
	quick_sort_tab(tab, 0, size - 1);
	i = 0;
	while (l)
	{
		VALUE(l) = tab[i];
		i++;
		l = l->next;
	}
	free(tab);
}
