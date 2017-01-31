/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:09:44 by epillot           #+#    #+#             */
/*   Updated: 2017/01/31 19:41:19 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

static int	find_elem_non_sorted(t_list *l)
{
	int		ind;

	ind = 2;
	while (l->next)
	{
		if (VALUE(l) > VALUE(l->next))
			return (ind);
		ind++;
		l = l->next;
	}
	return (0);
}

static void insert_elem(t_list **l, t_list *elem, int size)
{
	int     i;
	t_list  *tmp;

	i = 1;
	tmp = *l;
	while (i <= size && VALUE(tmp) < VALUE(elem))
	{
		tmp = tmp->next;
		i++;
	}
	ft_lst_insert(l, elem, i);
}

void		print_l(t_list *l);

void		insertion_sort(t_list **l)
{
	int		ind;
	t_list	*tmp, *tmp2;

	while ((ind = find_elem_non_sorted(*l)) != 0)
	{
		tmp = ft_lst_at(*l, ind - 1);
		tmp2 = tmp->next;
		tmp->next = tmp2->next;
		insert_elem(l, tmp2, ind - 1);
	}
}
