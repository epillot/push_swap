/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_param.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:02:16 by epillot           #+#    #+#             */
/*   Updated: 2017/02/02 18:04:05 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_error_param(int ac, char **av)
{
	int		i;
	int		j;
	long	arg;
	long	prev;

	i = 1;
	prev = 2147483648;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		if ((arg = ft_atol(av[i])) > INT_MAX || arg < INT_MIN)
			return (0);
		if (prev == arg)
			return (0);
		prev = arg;
		i++;
	}
	return (1);
}
