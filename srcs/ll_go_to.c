/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_go_to.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:07:33 by epillot           #+#    #+#             */
/*   Updated: 2017/02/08 19:50:57 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ll_go_to_ins(t_ll **l, int diff, char *str, t_list **cmd)
{
	if (diff > 0)
	{
		while (diff--)
		{
			(*l) = (*l)->next;
			add_cmd_in_list("r", str, cmd);
		}
	}
	else
	{
		while (diff++)
		{
			(*l) = (*l)->prev;
			add_cmd_in_list("rr", str, cmd);
		}
	}
}

static void	ll_go_to_out(t_ll **l, int diff, char *str, t_list **cmd)
{
	int		size;

	size = (*l)->size;
	if (diff > 0)
	{
		diff = size - diff;
		while (diff--)
		{
			(*l) = (*l)->prev;
			add_cmd_in_list("rr", str, cmd);
		}
	}
	else
	{
		diff = size + diff;
		while (diff--)
		{
			(*l) = (*l)->next;
			add_cmd_in_list("r", str, cmd);
		}
	}
}

int			ll_go_to(t_ll **l, t_pos pos, char *list_name, t_list **cmd)
{
	int		diff;
	int		size;

	if (!*l)
		return (1);
	size = (*l)->size;
	diff = pos.final - pos.start;
	if (ft_abs(diff) <= size / 2)
		ll_go_to_ins(l, diff, list_name, cmd);
	else
		ll_go_to_out(l, diff, list_name, cmd);
	return (pos.final);
}
