/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:15:36 by epillot           #+#    #+#             */
/*   Updated: 2017/01/26 16:14:19 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	exec_rot(t_list **l)
{
	t_list	*tmp;

	if (!*l)
		return ;
	tmp = ft_lstnew((*l)->content, sizeof(int));
	ft_lstadd_back(*l, tmp);
	tmp = *l;
	*l = (*l)->next;
	free(tmp);
}

void		exec_cmd_r(char *cmd, t_list **la, t_list **lb)
{
	if (*cmd == 'a')
		exec_rot(la);
	else if (*cmd == 'b')
		exec_rot(lb);
	else
	{
		exec_rot(la);
		exec_rot(lb);
	}
}
