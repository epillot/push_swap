/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_in_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:57:32 by epillot           #+#    #+#             */
/*   Updated: 2017/02/08 20:10:11 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_cmd_in_list(char *str, char *list_name, t_list **list)
{
	char	cmd[4];
	t_list	*new;

	ft_strcpy(cmd, str);
	ft_strcat(cmd, list_name);
	if (!(new = ft_lstnew(cmd, ft_strlen(cmd) + 1)))
		exit(EXIT_FAILURE);
	if (*list)
		ft_lstadd_back(*list, new);
	else
		*list = new;
}
