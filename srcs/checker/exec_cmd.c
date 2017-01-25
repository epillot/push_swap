/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:45:56 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 20:03:02 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exec_cmd(char *cmd, t_list *la, t_list *lb)
{
	if (*cmd++ == 's')
		exex_cmd_s(cmd, la, lb);
	else if (*cmd++ == 'p')
		exec_cmd_p(cmd, la, lb);
	else if (ft_strlen(cmd) == 2 && *cmd++ == 'r')
		exex_cmd_r(cmd, la, lb);
	else
		exex_cmd_rr(cmd + 2, la, lb);
}
