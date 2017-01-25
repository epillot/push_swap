/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:37:39 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 18:58:30 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H

# define VALUE(list) *(int*)(list->content)

void	exec_cmd(char *cmd, t_list *la, t_list *lb);

#endif
