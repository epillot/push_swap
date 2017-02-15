/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_la.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:58:44 by epillot           #+#    #+#             */
/*   Updated: 2017/02/15 16:52:03 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_int(char *param, int neg)
{
	char	*limit;

	if (param[10 + neg] != '\0')
		return (0);
	limit = (neg == 0 ? ft_itoa(INT_MAX) : ft_itoa(INT_MIN));
	if (limit)
	{
		if (ft_strcmp(param, limit) > 0)
		{
			free(limit);
			return (0);
		}
		free(limit);
		return (1);
	}
	exit(EXIT_FAILURE);
}

static int	nb_parser(char *param)
{
	int		i;
	int		neg;

	neg = 0;
	if (param[0] == '-')
		neg = 1;
	i = 0;
	while (param[i + neg] && i < 10)
	{
		if (!ft_isdigit(param[i + neg]))
			return (0);
		i++;
	}
	if (i == 10)
	{
		if (!(is_int(param, neg)))
			return (0);
	}
	return (1);
}

static void	free_param(char **param)
{
	int		i;

	i = 0;
	while (param[i])
		free(param[i++]);
	free(param);
}

static int	add_elem(t_ll **la, char *param)
{
	t_ll	*elem;

	if ((nb_parser(param)))
		elem = ll_new(ft_atoi(param));
	else
		return (0);
	if (*la)
		ll_addback(*la, elem);
	else
		*la = elem;
	return (1);
}

int			init_la(int ac, char **av, t_ll **la)
{
	int		i;
	int		j;
	char	**param;

	i = 0;
	while (i < ac)
	{
		j = 0;
		if (!(param = ft_split_whitespace(av[i])))
			exit(EXIT_FAILURE);
		if (!*param)
			return (0);
		while (param[j])
		{
			if (!(add_elem(la, param[j])))
				return (0);
			j++;
		}
		free_param(param);
		i++;
	}
	return (1);
}
