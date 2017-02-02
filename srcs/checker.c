/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:02:40 by epillot           #+#    #+#             */
/*   Updated: 2017/02/02 18:45:59 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	print_list(t_ll *l)
{
	int size;

	if (!l)
	{
		ft_putendl("vide");
		return ;
	}
	size = l->size;
	while (size--)
	{
		ft_printf("%d ", l->val);
		l = l->next;
	}
	ft_putchar('\n');
}

int			main(int ac, char **av)
{
	t_ll	*la;
	t_ll	*lb;
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
	init_la(ac, av, &la);
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
	ft_putendl(l_is_sort(la, 0) && !lb ? "OK" : "KO");
	return (0);
}
