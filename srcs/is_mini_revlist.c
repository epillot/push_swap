/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_mini_revlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:56:07 by epillot           #+#    #+#             */
/*   Updated: 2017/02/15 18:02:44 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_mini_revlist(t_ll *l)
{
	if (l->size != 3)
		return (0);
	if (l->val > l->next->val)
	{
		if (l->next->val > l->next->next->val)
			return (1);
	}
	return (0);
}
