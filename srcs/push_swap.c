/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:43:34 by epillot           #+#    #+#             */
/*   Updated: 2017/02/02 19:30:18 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_ll	*la;
	t_ll	*lb;
//	char	**cmd;

	if (ac < 2)
		return (0);
	if (!(check_error_param(ac, av)))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	la = NULL;
	lb = NULL;
//	cmd = NULL;
	init_la(ac, av, &la);
	pu_sw_bubble_sort(la);
//	print_cmd(cmd);
	return (0);
}
