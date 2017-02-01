/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:09:44 by epillot           #+#    #+#             */
/*   Updated: 2017/02/01 13:43:00 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

static t_list	*find_lst_min(t_list *l, int (*cmp)(t_list *, t_list *))
{
	t_list	*min;

	min = l;
	l = l->next;
	while (l)
	{
		if ((*cmp)(min, l) > 0)
			min = l;
		l = l->next;
	}
	return (min);
}

void			selection_sort(t_list *l, int (*cmp)(t_list *, t_list *))
{
	t_list *min;

	while (l)
	{
		min = find_lst_min(l, cmp);
		if (l != min)
			ft_lst_swap_cnt(l, min);
		l = l->next;
	}
}
