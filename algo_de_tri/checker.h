/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:37:39 by epillot           #+#    #+#             */
/*   Updated: 2017/01/26 14:12:36 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H

# include "libft.h"

# define VALUE(list) *(int*)(list->content)

void	exec_cmd(char *cmd, t_list **la, t_list **lb);
void	exec_cmd_s(char *cmd, t_list *la, t_list *lb);
void	exec_cmd_p(char *cmd, t_list **la, t_list **lb);
void	exec_cmd_r(char *cmd, t_list **la, t_list **lb);
void	exec_cmd_rr(char *cmd, t_list **la, t_list **lb);

#endif
