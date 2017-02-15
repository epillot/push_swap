/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:25:17 by epillot           #+#    #+#             */
/*   Updated: 2017/02/15 16:25:26 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_elem(t_ll **on, t_ll **from)
{
	t_ll	*tmp;

	if (!*from)
		return ;
	tmp = *from;
	if ((*from)->size > 1)
	{
		(*from)->prev->next = (*from)->next;
		(*from)->next->prev = (*from)->prev;
		(*from) = (*from)->next;
		ll_size_rec(*from, (*from)->size - 1);
	}
	else
		(*from) = NULL;
	ll_addfront(on, tmp);
}
