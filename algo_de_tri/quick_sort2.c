/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 14:52:13 by epillot           #+#    #+#             */
/*   Updated: 2017/02/01 17:53:19 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    print_l(t_list *l);

void	quick_sort(t_list *l, int start, int end)
{
	int		pivot;
	int		left;
	int		right;
	t_list	*l_start;
	t_list	*l_end;

	ft_printf("start: %d ", start);
	ft_printf("end: %d\n", end);
	l_start = ft_lst_at(l, start);
	l_end = ft_lst_at(l, end);
	if (!l_start || !l_end || start >= end)
		return ;
	pivot = VALUE(l_start);
	left = start;
	right = end;
	while (1)
	{
		ft_putchar('\n');
		print_l(l);
		ft_printf("pivot: %d\n", pivot);
		while (l_start && VALUE(l_start) < pivot)
		{
			l_start = l_start->next;
			left++;
		}
		while (l_end && VALUE(l_end) > pivot)
		{
			l_end = l_end->prev;
			right--;
		}
		if (l_start && l_end && left < right)// && VALUE(l_start) != VALUE(l_end))
			ft_lst_swap_cnt(l_start, l_end);
		else
			break ;
	}
	ft_printf("left: %d ", left);
	ft_printf("right: %d\n", right);
	quick_sort(l, start, right - 1);
	quick_sort(l, right + 1, end);
}
