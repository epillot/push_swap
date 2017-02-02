/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:45:56 by epillot           #+#    #+#             */
/*   Updated: 2017/02/02 16:44:15 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_cmd(char *cmd, t_ll **la, t_ll **lb)
{
	if (*cmd == 's')
		exec_cmd_s(cmd + 1, *la, *lb);
	else if (*cmd == 'p')
		exec_cmd_p(cmd + 1, la, lb);
	else if (ft_strlen(cmd) == 2 && *cmd == 'r')
		exec_cmd_r(cmd + 1, la, lb);
	else
		exec_cmd_rr(cmd + 2, la, lb);
}
