/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:59:47 by epillot           #+#    #+#             */
/*   Updated: 2017/01/27 14:37:58 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap_value(t_list *elem1, t_list *elem2)
{
	void	*tmp;

	tmp = elem1->content;
	elem1->content = elem2->content;
	elem2->content = tmp;
}

static void	exec_swap(t_list *l)
{
	if (ft_lst_size(l) < 2)
		return ;
	swap_value(l, l->next);
}

void		exec_cmd_s(char *cmd, t_list *la, t_list *lb)
{
	if (*cmd == 'a')
		exec_swap(la);
	else if (*cmd == 'b')
		exec_swap(lb);
	else
	{
		exec_swap(la);
		exec_swap(lb);
	}
}
