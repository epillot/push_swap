/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:45:56 by epillot           #+#    #+#             */
/*   Updated: 2017/01/26 15:24:58 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exec_cmd(char *cmd, t_list **la, t_list **lb)
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
