/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:39:36 by epillot           #+#    #+#             */
/*   Updated: 2017/02/08 18:01:33 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ll	*ll_new(int n)
{
	t_ll	*output;

	if (!(output = ft_memalloc(sizeof(t_ll))))
		exit(EXIT_FAILURE);
	output->val = n;
	output->size = 1;
	output->next = output;
	output->prev = output;
	return (output);
}

void	ll_addback(t_ll *l, t_ll *elem)
{
	int		i;
	int		size;

	i = 1;
	size = l->size;
	while (i++ < size)
	{
		l->size++;
		l = l->next;
	}
	l->size++;
	elem->next = l->next;
	l->next->prev = elem;
	l->next = elem;
	elem->prev = l;
	elem->size = l->size;
}

void	ll_size_rec(t_ll *l, int new_size)
{
	int		i;

	i = 0;
	while (i++ < new_size)
	{
		l->size = new_size;
		l = l->next;
	}
}

void	ll_addfront(t_ll **l, t_ll *elem)
{
	if (*l)
	{
		elem->next = *l;
		elem->prev = (*l)->prev;
		(*l)->prev->next = elem;
		(*l)->prev = elem;
		ll_size_rec(elem, (*l)->size + 1);
	}
	else
	{
		elem->next = elem;
		elem->prev = elem;
		elem->size = 1;
	}
	*l = elem;
}

void	ll_swap(t_ll *l)
{
	int		tmp;

	tmp = l->val;
	l->val = l->next->val;
	l->next->val = tmp;
}
