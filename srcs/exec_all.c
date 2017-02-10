/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:29:15 by epillot           #+#    #+#             */
/*   Updated: 2017/02/09 14:39:24 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_list(t_ll *l)
{
	int		size;

	if (!l)
	{
		ft_putendl("empty");
		return ;
	}
	size = l->size;
	while (size--)
	{
		ft_putnbr(l->val);
		if (size != 0)
			ft_putchar(' ');
		l = l->next;
	}
	ft_putchar('\n');
}

void	exec_all(t_list *cmd_list, t_ll **la, t_ll **lb, t_psopt opt)
{
	int		i;

	i = 0;
	if (opt.v)
	{
		ft_putstr("initial list: ");
		print_list(*la);
		ft_putchar('\n');
	}
	while (cmd_list)
	{
		i++;
		if (opt.v)
			ft_printf("-------cmd %d: %s-------\n", i, (char*)cmd_list->content);
		exec_cmd((char*)cmd_list->content, la, lb);
		if (opt.v)
		{
			ft_putstr("list a: ");
			print_list(*la);
			ft_putstr("list b: ");
			print_list(*lb);
			ft_putchar('\n');
		}
		cmd_list = cmd_list->next;
	}
	if (opt.n)
		ft_printf("push_swap send a programm with %d instructuons\n", i);
}
