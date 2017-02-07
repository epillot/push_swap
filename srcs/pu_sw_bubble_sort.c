/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:06:19 by epillot           #+#    #+#             */
/*   Updated: 2017/02/02 19:47:23 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pu_sw_bubble_sort(t_ll *l)//, char ***cmd)
{
	int		size;
	int		i, j;
	t_ll		*begin;

	size = l->size;
	begin = l;
	j = 1;
	while (!(l_is_sort(begin, 0)))
	{
		i = 0;
		while (i < size - j)
		{
			if (l->val > l->next->val)
			{
				ll_swap(l);
				ft_putendl("sa");
			}
			l = l->next;
			ft_putendl("ra");
			i++;
		}
		i = 0;
		while (i < size - j)
                {
			l = l->prev;
			ft_putendl("rra");
                        if (l->val > l->next->val)
                        {
                                ll_swap(l);
                                ft_putendl("sa");
                        }
                        l = l->next;
                        i++;
                }
		j++;
	}
}
