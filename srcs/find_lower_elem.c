/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lower_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:15:53 by epillot           #+#    #+#             */
/*   Updated: 2017/02/15 15:16:21 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_lower_elem(t_ll *l, int val, int size)
{
	int		pos;

	pos = 1;
	while (pos <= size)
	{
		if (l->val <= val)
			return (pos);
		l = l->next;
		pos++;
	}
	return (0);
}
