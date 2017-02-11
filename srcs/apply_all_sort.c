/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_all_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:06:05 by epillot           #+#    #+#             */
/*   Updated: 2017/02/11 18:57:40 by epillot          ###   ########.fr       */
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

static void	load_ll(t_ll *l, int *tab)
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

static int	get_best_sort(int size, t_list *cmd[])
{
	int		i;
	int		min;

	i = 1;
	min = 0;
	if (size >= 200)
		return (4);
	else if (size >= 30)
	{
		min = 1;
		i = 2;
	}
	while (i < 5)
	{
		if (ft_lst_size(cmd[i]) < ft_lst_size(cmd[min]))
			min = i;
		i++;
	}
	return (min);
}

int			apply_all_sort(t_ll **la, t_ll **lb, t_list *cmd[])
{
	int		*tab;
	int		i;

	tab = save_ll(*la);
	if ((*la)->size >= 200)
		cmd[4] = pu_sw_quick_sort(la, lb);
	else if ((*la)->size >= 30)
	{
		cmd[1] = pu_sw_sel_sort(la, lb);
		load_ll(*la, tab);
		cmd[2] = pu_sw_ins_sort(la, lb);
		load_ll(*la, tab);
		cmd[3] = pu_sw_ins_sort2(la, lb);
		load_ll(*la, tab);
		cmd[4] = pu_sw_quick_sort(la, lb);
	}
	else
	{
		cmd[0] = pu_sw_bubble_sort(*la);
		load_ll(*la, tab);
		cmd[1] = pu_sw_sel_sort(la, lb);
		load_ll(*la, tab);
		cmd[2] = pu_sw_ins_sort(la, lb);
		load_ll(*la, tab);
		cmd[3] = pu_sw_ins_sort2(la, lb);
		load_ll(*la, tab);
		cmd[4] = pu_sw_quick_sort(la, lb);
	}
	free(tab);
	i = get_best_sort((*la)->size, cmd);
	ll_free(la);
	return (i);
}
