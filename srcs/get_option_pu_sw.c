/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option_pu_sw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:25:19 by epillot           #+#    #+#             */
/*   Updated: 2017/02/16 15:24:53 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pu_sw_usage(char c)
{
	ft_printf_fd(2, "checker: illegal option -- %c\n", c);
	ft_printf_fd(2, "usage: checker [-nv] [arg ...]\n");
	exit(EXIT_FAILURE);
}

int			get_option_pu_sw(int ac, char **av, t_psopt *opt)
{
	int		i;
	int		j;

	i = 1;
	ft_bzero(opt, sizeof(t_psopt));
	while (i < ac && av[i][0] == '-')// && av[i][1])
	{
		if (!av[i][1] || ft_isdigit(av[i][1]))
			return (i);
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
				pu_sw_usage(av[i][j]);
			j++;
		}
		i++;
	}
	return (i);
}
