/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_sw_quick_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:42:20 by epillot           #+#    #+#             */
/*   Updated: 2017/02/10 19:57:11 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		partition(t_ll **la, t_ll **lb, t_pos pos, t_list **cmd)
{
	int		piv;
	int		size;
	t_pos	pos2;

	size = pos.final - pos.start;
	if (size <= 0)
		return ;
	pos2.start = 1;
	pos2.final = pos.start;
	ll_go_to(la, pos2, "a", cmd);
	piv = (*la)->val;
	exec_cmd_p("b", la, lb);
	add_cmd_in_list("p", "b", cmd);
	while (size--)
	{
		if ((*la)->val < piv)
		{
			exec_cmd_p("b", la, lb);
			add_cmd_in_list("p", "b", cmd);
		}
		else
		{
			(*la) = (*la)->next;
			add_cmd_in_list("r", "a", cmd);
		}
	}
	size = (*la)->size;
	pos2.start = 1;
	pos2.final = 1;
	while (size--)
	{
		exec_cmd_p("b", la, lb);
		add_cmd_in_list("p", "b", cmd);
		pos2.final++;

	}
	ll_go_to(lb, pos2, "b", cmd);
	size = (*lb)->size;
	while (size--)
	{
		(*lb) = (*lb)->prev;
		add_cmd_in_list("rr", "b", cmd);
		exec_cmd_p("a", la, lb);
		add_cmd_in_list("p", "a", cmd);
	}
}

void		quick_sort_aux(t_ll **la, t_ll **lb, t_list **cmd)
{
	t_pos	pos;

	pos
}

t_list		*pu_sw_quick_sort(t_ll **la, t_ll **lb)
{
	t_list	*cmd;
	t_pos	pos;

	cmd = NULL;
	pos.start = 1;
	pos.final = (*la)->size;
	partition(la, lb, pos, &cmd);
	return (cmd);
}
