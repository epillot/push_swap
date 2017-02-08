/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option_pu_sw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:25:19 by epillot           #+#    #+#             */
/*   Updated: 2017/02/08 17:07:36 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_option_pu_sw(int ac, char **av, t_psopt *opt)
{
	int		i;
	int		j;

	i = 1;
	ft_bzero(opt, sizeof(t_psopt));
	while (i < ac && av[i][0] == '-' && av[i][1])
	{
		j = 1;
		if (av[i][1] == '-' && !av[i][2])
			return (i + 1);
		while (av[i][j])
		{
			if (av[i][j] == 'v')
				opt->v = 1;
			else if (av[i][j] == 'n')
				opt->n = 1;
			else
			{
				ft_printf_fd(2, "checker: illegal option -- %c\n", av[i][j]);
				ft_printf_fd(2, "usage: checker [-nv] [arg ...]\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (i);
}
