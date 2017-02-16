/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:45:56 by epillot           #+#    #+#             */
/*   Updated: 2017/02/16 12:44:51 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rotate(char *cmd, t_ll **la, t_ll **lb)
{
	if (*cmd == 'a')
	{
		if (*la)
			*la = (*la)->next;
	}
	else if (*cmd == 'b')
	{
		if (*lb)
			*lb = (*lb)->next;
	}
	else
	{
		if (*la)
			*la = (*la)->next;
		if (*lb)
			*lb = (*lb)->next;
	}
}

static void	do_rev_rotate(char *cmd, t_ll **la, t_ll **lb)
{
	if (*cmd == 'a')
	{
		if (*la)
			*la = (*la)->prev;
	}
	else if (*cmd == 'b')
	{
		if (*lb)
			*lb = (*lb)->prev;
	}
	else
	{
		if (*la)
			*la = (*la)->prev;
		if (*lb)
			*lb = (*lb)->prev;
	}
}

static void	do_swap(char *cmd, t_ll *la, t_ll *lb)
{
	if (*cmd == 'a')
	{
		if (la)
			ll_swap(la);
	}
	else if (*cmd == 'b')
	{
		if (lb)
			ll_swap(lb);
	}
	else
	{
		if (la)
			ll_swap(la);
		if (lb)
			ll_swap(lb);
	}
}

static void	do_push(char *cmd, t_ll **la, t_ll **lb)
{
	if (*cmd == 'a')
		push_elem(la, lb);
	else
		push_elem(lb, la);
}

void		exec_cmd(char *cmd, t_ll **la, t_ll **lb)
{
	if (*cmd == 's')
		do_swap(cmd + 1, *la, *lb);
	else if (*cmd == 'p')
		do_push(cmd + 1, la, lb);
	else if (ft_strlen(cmd) == 2 && *cmd == 'r')
		do_rotate(cmd + 1, la, lb);
	else
		do_rev_rotate(cmd + 2, la, lb);
}
