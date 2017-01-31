/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:56:35 by epillot           #+#    #+#             */
/*   Updated: 2017/01/26 15:11:31 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	exec_push(t_list **on, t_list **from)
{
	t_list	*tmp;
	if (!*from)
		return ;
	tmp = ft_lstnew((*from)->content, sizeof(int));
	if (*on)
		ft_lstadd(on, tmp);
	else
		*on = tmp;
	tmp = *from;
	*from = (*from)->next;
	free(tmp);
}

void		exec_cmd_p(char *cmd, t_list **la, t_list **lb)
{
	if (*cmd == 'a')
		exec_push(la, lb);
	else
		exec_push(lb, la);
}
