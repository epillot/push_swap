/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:02:40 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 18:58:58 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "checker.h"

static int	check_error_param(int ac, char **av)
{
	int		i;
	int		j;
	long	arg;
	long	prev;

	i = 0;
	prev = INT_MAX + 1;
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

static int	check_error_cmd(char *cmd)
{
	if (ft_strcmp(cmd, "sa") == 0)
		return (1);
	if (ft_strcmp(cmd, "sb") == 0)
		return (1);
	if (ft_strcmp(cmd, "ss") == 0)
		return (1);
	if (ft_strcmp(cmd, "pa") == 0)
		return (1);
	if (ft_strcmp(cmd, "pb") == 0)
		return (1);
	if (ft_strcmp(cmd, "ra") == 0)
		return (1);
	if (ft_strcmp(cmd, "rb") == 0)
		return (1);
	if (ft_strcmp(cmd, "rr") == 0)
		return (1);
	if (ft_strcmp(cmd, "rra") == 0)
		return (1);
	if (ft_strcmp(cmd, "rrb") == 0)
		return (1);
	if (ft_strcmp(cmd, "rrr") == 0)
		return (1);
	return (0);
}

static void	inti_list_a(int ac, char **av, t_list **la)
{
	int		i;
	t_list	*elem;
	int		arg;

	i = 0;
	while (i < ac)
	{
		arg = ft_atoi(av[i]);
		elem = ft_lstnew(&arg, sizeof(int));
		if (*la)
			ft_lstadd_back(*la, elem);
		else
			*la = elem;
		i++;
	}
}

static int	check_list(t_list *la, t_list *lb)
{
	int		act;
	int		prev;

	prev = INT_MIN;
	while (la)
	{
		act = VALUE(la);
		if (act < prev)
			return (0);
		prev = act;
		la = la->next;
	}
	if (lb)
		return (0);
	return (1);
}

int			main(int ac, char **av)
{
	t_list	*la;
	t_list	*lb;
	char	*cmd;

	if (!(check_error_param(ac, av)))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	la = NULL;
	lb = NULL;
	init_list_a(ac, av, &la);
	while (get_next_line(0, &cmd) > 0)
	{
		if (!(check_error_cmd(cmd)))
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
		else
			exec_cmd(cmd, la, lb);
	}
	ft_putendl((check_list(la, lb) == 1) ? "OK" : "KO");
	return (0);
}
