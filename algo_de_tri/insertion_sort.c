/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:09:44 by epillot           #+#    #+#             */
/*   Updated: 2017/02/01 13:38:48 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

static void	insert_elem(t_list **l, t_list *elem)
{
	int		i;
	t_list	*tmp;
	t_list	*tmp_prev;

	i = 1;
	tmp_prev = NULL;
	tmp = *l;
	while (tmp && VALUE(elem) >= VALUE(tmp))
	{	
		tmp_prev = tmp;
		tmp = tmp->next;
	}
	if (tmp_prev)
	{
		tmp_prev->next = elem;
		elem->next = tmp;
	}
	else
		ft_lstadd(l, elem);
}

void		insertion_sort(t_list **l, int (*cmp)(t_list *, t_list *))
{
	t_list	*tmplist;
	t_list	*tmp;

	if (!*l)
		return ;
	tmplist = *l;
	while (tmplist->next)
	{
		if ((*cmp)(tmplist, tmplist->next) > 0)
		{
			tmp = tmplist->next;
			tmplist->next = tmp->next;
			insert_elem(l, tmp);
		}
		else	
			tmplist = tmplist->next;
	}
}
