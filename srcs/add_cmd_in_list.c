/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_in_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:57:32 by epillot           #+#    #+#             */
/*   Updated: 2017/02/16 12:43:44 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_usefull1(char *cmd_prev, char *cmd)
{
	if (ft_strcmp(cmd_prev, "ra") == 0)
	{
		if (ft_strcmp(cmd, "rra") == 0)
			return (0);
		else
			return (1);
	}
	if (ft_strcmp(cmd_prev, "rb") == 0)
	{
		if (ft_strcmp(cmd, "rrb") == 0)
			return (0);
		else
			return (1);
	}
	if (ft_strcmp(cmd_prev, "rra") == 0)
	{
		if (ft_strcmp(cmd, "ra") == 0)
			return (0);
		else
			return (1);
	}
	return (0);
}

static int	is_usefull2(char *cmd_prev, char *cmd)
{
	if (ft_strcmp(cmd_prev, "rrb") == 0)
	{
		if (ft_strcmp(cmd, "rb") == 0)
			return (0);
		else
			return (1);
	}
	if (ft_strcmp(cmd_prev, "pa") == 0)
	{
		if (ft_strcmp(cmd, "pb") == 0)
			return (0);
		else
			return (1);
	}
	if (ft_strcmp(cmd_prev, "pb") == 0)
	{
		if (ft_strcmp(cmd, "pa") == 0)
			return (0);
		else
			return (1);
	}
	return (0);
}

static int	is_usefull(char *cmd_prev, char *cmd)
{
	if (ft_strcmp(cmd_prev, "sa") == 0 || ft_strcmp(cmd_prev, "sb") == 0)
		return (1);
	if (is_usefull1(cmd_prev, cmd))
		return (1);
	if (is_usefull2(cmd_prev, cmd))
		return (1);
	return (0);
}

static void	remove_cmd(t_list **list, t_list *cmd_prev, t_list **cmd1,
		t_list **cmd2)
{
	if (cmd_prev)
	{
		ft_lstdelone(cmd1, &ft_lstfree_cnt);
		cmd_prev->next = NULL;
	}
	else
		ft_lstdelone(list, &ft_lstfree_cnt);
	ft_lstdelone(cmd2, &ft_lstfree_cnt);
}

void		add_cmd_in_list(char *str, char *list_name, t_list **list)
{
	char	cmd[4];
	t_list	*new;
	t_list	*tmp1;
	t_list	*tmp2;

	ft_strcpy(cmd, str);
	ft_strcat(cmd, list_name);
	if (!(new = ft_lstnew(cmd, ft_strlen(cmd) + 1)))
		exit(EXIT_FAILURE);
	if (*list)
	{
		tmp2 = NULL;
		tmp1 = *list;
		while (tmp1->next)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
		}
		if ((is_usefull((char*)tmp1->content, (char*)new->content)))
			tmp1->next = new;
		else
			remove_cmd(list, tmp2, &tmp1, &new);
	}
	else
		*list = new;
}
