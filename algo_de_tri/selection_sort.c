/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:09:44 by epillot           #+#    #+#             */
/*   Updated: 2017/01/31 15:33:15 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

static t_list	*find_lst_min(t_list *l)
{
	t_list	*min;

	min = l;
	l = l->next;
	while (l)
	{
		if (VALUE(min) > VALUE(l))
			min = l;
		l = l->next;
	}
	return (min);
}

void			selection_sort(t_list *l)
{
	t_list *min;

	while (l)
	{
		min = find_lst_min(l);
		if (l != min)
			ft_lst_swap_cnt(l, min);
		l = l->next;
	}
}
