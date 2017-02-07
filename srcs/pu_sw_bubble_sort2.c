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
	int		i;

	size = l->size;
	while (1)
	{
		if (l_is_sort(l, 0))
			break ;
		i = 0;
		while (i < size - 1)
		{
			if (l->val > l->next->val)
			{
				ll_swap(l);
				ft_putendl("sa");
			}
			if (l_is_sort(l, 0))
				break ;
			l = l->next;
			ft_putendl("ra");
			i++;
		}
		if (!(l_is_sort(l, 0)))
		{
			l = l->next;
			ft_putendl("ra");
		}
	}
}
