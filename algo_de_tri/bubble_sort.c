/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:28:35 by epillot           #+#    #+#             */
/*   Updated: 2017/02/01 14:02:58 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void	bubble_sort(t_list *l, int (*cmp)(t_list *, t_list *))
{
	int		nb_swap;
	t_list	*tmp;

	nb_swap = 1;
	while (nb_swap != 0)
	{
		nb_swap = 0;
		tmp = l;
		while (tmp->next)
		{
			if ((*cmp)(tmp, tmp->next) > 0)
			{
				ft_lst_swap_cnt(tmp, tmp->next);
				nb_swap++;
			}
			tmp = tmp->next;
		}
	}
}
