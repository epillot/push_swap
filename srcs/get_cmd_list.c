/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 14:44:08 by epillot           #+#    #+#             */
/*   Updated: 2017/02/15 16:39:45 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_error_cmd(char *cmd)
{
	if (ft_strcmp(cmd, "sa") == 0)
		return (1);
	if (ft_strcmp(cmd, "sb") == 0)
		return (1);
	if (ft_strcmp(cmd, "ss") == 0)
		return (1);
	if (ft_strcmp(cmd, "pa") == 0)
		return (1);
	if (ft_strcmp(cmd, "pb") == 0)
		return (1);
	if (ft_strcmp(cmd, "ra") == 0)
		return (1);
	if (ft_strcmp(cmd, "rb") == 0)
		return (1);
	if (ft_strcmp(cmd, "rr") == 0)
		return (1);
	if (ft_strcmp(cmd, "rra") == 0)
		return (1);
	if (ft_strcmp(cmd, "rrb") == 0)
		return (1);
	if (ft_strcmp(cmd, "rrr") == 0)
		return (1);
	return (0);
}

static int	add_cmd(t_list **list, char cmd[4])
{
	t_list	*elem;

	if (!(check_error_cmd(cmd)))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	if (!(elem = ft_lstnew(cmd, ft_strlen(cmd) + 1)))
		return (0);
	if (*list)
		ft_lstadd_back(*list, elem);
	else
		*list = elem;
	return (1);
}

int			get_cmd_list(t_list **cmd_list)
{
	char	buf;
	char	cmd[4];
	int		i;

	i = 0;
	while ((read(0, &buf, 1)) && i < 4)
	{
		cmd[i] = buf;
		if (cmd[i] == '\n')
		{
			cmd[i] = '\0';
			if (!(add_cmd(cmd_list, cmd)))
				return (0);
			buf = '\0';
			i = 0;
		}
		else
			i++;
	}
	if (i == 4 || buf)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	return (1);
}
