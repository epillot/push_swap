/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_la.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:58:44 by epillot           #+#    #+#             */
/*   Updated: 2017/02/02 18:01:03 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_la(int ac, char **av, t_ll **la)
{
	int		i;
	t_ll	*elem;

	i = 1;
	while (i < ac)
	{
		elem = ll_new(ft_atoi(av[i]));
		if (*la)
			ll_addback(*la, elem);
		else
			*la = elem;
		i++;
	}
}
