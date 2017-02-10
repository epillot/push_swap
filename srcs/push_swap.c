/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:43:34 by epillot           #+#    #+#             */
/*   Updated: 2017/02/10 13:14:51 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_cmd(t_list *cmd)
{
	while (cmd)
	{
		ft_putendl((char*)cmd->content);
		cmd = cmd->next;
	}
}

static void	free_all_cmd(t_list *cmd[])
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (cmd[i])
			ft_lstdel(&cmd[i], &ft_lstfree_cnt);
		i++;
	}
}

static void	print_winner(int i)
{
	if (i == 0)
		ft_putendl("bubble sort");
	else if (i == 1)
		ft_putendl("selection sort");
	else if (i == 2)
		ft_putendl("insertion sort");
	else if (i == 3)
		ft_putendl("quick sort");
}

int			main(int ac, char **av)
{
	t_ll	*la;
	t_ll	*lb;
	t_list	*cmd[4];
	int		i;

	ac--;
	av++;
	if (ac < 1)
		return (0);
	la = NULL;
	lb = NULL;
	if (!(init_la(ac, av, &la)) || !(check_double(la)))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	ft_bzero(cmd, sizeof(cmd));
	i = apply_all_sort(&la, &lb, cmd);
	i = 3;
	print_winner(i);
	print_cmd(cmd[i]);
	free_all_cmd(cmd);
	return (0);
}
