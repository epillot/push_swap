/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:02:40 by epillot           #+#    #+#             */
/*   Updated: 2017/01/26 16:17:14 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "checker.h"

static int	check_error_param(int ac, char **av)
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

static void	init_list_a(int ac, char **av, t_list **la)
{
	int		i;
	t_list	*elem;
	int		arg;

	i = 1;
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

static void	print_list(t_list *l)
{
	if (!l)
	{
		ft_putendl("vide");
		return ;
	}
	while (l)
	{
		ft_printf("%d ", VALUE(l));
		l = l->next;
	}
	ft_putchar('\n');
}

int			main(int ac, char **av)
{
	t_list	*la;
	t_list	*lb;
	char	*cmd;

	if (ac < 2)
		return (0);
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
		{
			exec_cmd(cmd, &la, &lb);
			ft_putstr("la: ");
			print_list(la);
			ft_putstr("lb: ");
			print_list(lb);
		}
	}
	ft_putendl((check_list(la, lb) == 1) ? "OK" : "KO");
	return (0);
}
