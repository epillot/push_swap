/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:29:15 by epillot           #+#    #+#             */
/*   Updated: 2017/02/16 12:44:35 by epillot          ###   ########.fr       */
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

static void	display_cmd(t_ll *la, t_ll *lb, int i, char *cmd)
{
	ft_printf("%s-----command %d:", C_CYAN, i);
	ft_printf("%s %s%s\n", C_RED, cmd, C_NONE);
	ft_printf("%slist a: %s", C_YELLOW, C_NONE);
	print_list(la);
	ft_printf("%slist b: %s", C_YELLOW, C_NONE);
	print_list(lb);
	ft_putchar('\n');
}

void		exec_all(t_list *cmd_list, t_ll **la, t_ll **lb, t_psopt opt)
{
	int		i;

	i = 0;
	if (opt.v)
	{
		ft_printf("%sinitial list: ", C_YELLOW);
		ft_putstr(C_GREEN);
		print_list(*la);
		ft_putstr(C_NONE);
		ft_putchar('\n');
	}
	while (cmd_list)
	{
		i++;
		exec_cmd((char*)cmd_list->content, la, lb);
		if (opt.v)
			display_cmd(*la, *lb, i, (char*)cmd_list->content);
		cmd_list = cmd_list->next;
	}
	if (opt.n)
		ft_printf("push_swap send a programm with %d instructions\n", i);
}
