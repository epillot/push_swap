/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:24:51 by epillot           #+#    #+#             */
/*   Updated: 2017/01/26 16:14:17 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	exec_rev_rot(t_list **l)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (ft_lst_size(*l) < 2)
		return ;
	tmp1 = *l;
	while (tmp1->next)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	ft_lstadd(l, tmp1);
	tmp2->next = NULL;
}

void		exec_cmd_rr(char *cmd, t_list **la, t_list **lb)
{
	if (*cmd == 'a')
		exec_rev_rot(la);
	else if (*cmd == 'b')
		exec_rev_rot(lb);
	else
	{
		exec_rev_rot(la);
		exec_rev_rot(lb);
	}
}
