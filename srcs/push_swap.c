/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:43:34 by epillot           #+#    #+#             */
/*   Updated: 2017/02/08 20:17:13 by epillot          ###   ########.fr       */
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

int			main(int ac, char **av)
{
	t_ll	*la;
	t_ll	*lb;
	t_list	*cmd[2];

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
	cmd[0] = pu_sw_bubble_sort(la);
//	ft_lstdel(&la, &ft_lstfree_cnt);
	la = NULL;
	init_la(ac, av, &la);
	cmd[1] = pu_sw_sel_sort(&la, &lb);
//	pu_sw_bubble_sort(la);
//	pu_sw_ins_sort(&la, &lb);
//	print_cmd(cmd);
//	pu_sw_sel_sort(&la, &lb);
	if (ft_lst_size(cmd[0]) <= ft_lst_size(cmd[1]))
		print_cmd(cmd[0]);
	else
		print_cmd(cmd[1]);
	return (0);
}
