/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_in_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:57:32 by epillot           #+#    #+#             */
/*   Updated: 2017/02/09 19:03:53 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_usefull(char *cmd_prev, char *cmd)
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
	return (1);
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
		{
			if (tmp2)
			{
				ft_lstdelone(&tmp1, &ft_lstfree_cnt);
				tmp2->next = NULL;
			}
			else
				ft_lstdelone(list, &ft_lstfree_cnt);
			ft_lstdelone(&new, &ft_lstfree_cnt);
		}

	}
	else
		*list = new;
}
