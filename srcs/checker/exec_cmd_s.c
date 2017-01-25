/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:59:47 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 20:02:55 by epillot          ###   ########.fr       */
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

static void	exec_sa(t_list *la)
{
	if (ft_lst_size(la) < 2)
		return ;
	swap_value(la, la->next);
}

static void	exec_sb(t_list *lb)
{
	if (ft_lst_size(lb) < 2)
		return ;
	swap_value(lb, lb->next);
}

void		exec_cmd_s(char *cmd, t_list *la, t_list *lb)
{
	if (*cmd == 'a')
		exec_sa(la);
	else if (*cmd == 'b')
		exex_sb(lb);
	else
	{
		exec_sa(la);
		exec_sb(lb);
	}
}
