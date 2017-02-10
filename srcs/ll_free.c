/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:37:15 by epillot           #+#    #+#             */
/*   Updated: 2017/02/09 14:20:17 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ll_free(t_ll **l)
{
	t_ll	*tmp1;
	t_ll	*tmp2;
	int		size;

	if (!*l)
		return ;
	size = (*l)->size;
	tmp1 = *l;
	while (size--)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	*l = NULL;
}
