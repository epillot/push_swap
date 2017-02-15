/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:05:08 by epillot           #+#    #+#             */
/*   Updated: 2017/02/15 16:37:05 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_double(t_ll *l)
{
	int		size;
	int		size2;
	t_ll	*tmp;
	int		val;
	int		i;

	if (!l)
		return (0);
	size = l->size;
	i = 1;
	while (i <= size)
	{
		val = l->val;
		tmp = l->next;
		size2 = size - i;
		while (size2--)
		{
			if (val == tmp->val)
				return (0);
			tmp = tmp->next;
		}
		i++;
		l = l->next;
	}
	return (1);
}
