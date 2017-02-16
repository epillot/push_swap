/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_good_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:38:22 by epillot           #+#    #+#             */
/*   Updated: 2017/02/16 15:35:41 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		load_ll(t_ll *l, int *tab)
{
	int		size;

	if (!l)
		return ;
	size = l->size;
	while (size--)
	{
		l->val = *tab++;
		l = l->next;
	}
}

void			apply_good_sort(t_ll **la, t_ll **lb, int *tab, t_list *cmd[])
{
	if ((*la)->size >= 300)
		cmd[4] = quick_sort_large(la, lb);
	else if ((*la)->size >= 100)
	{
		cmd[3] = quick_sort_medium(la, lb);
		load_ll(*la, tab);
		cmd[4] = quick_sort_large(la, lb);
	}
	else
	{
		cmd[0] = pu_sw_bubble_sort(*la);
		load_ll(*la, tab);
		cmd[1] = pu_sw_sel_sort(la, lb);
		load_ll(*la, tab);
		cmd[2] = pu_sw_ins_sort(la, lb);
		load_ll(*la, tab);
		cmd[3] = quick_sort_medium(la, lb);
		load_ll(*la, tab);
		cmd[4] = quick_sort_large(la, lb);
	}
}
