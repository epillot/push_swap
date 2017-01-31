/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:09:44 by epillot           #+#    #+#             */
/*   Updated: 2017/01/31 19:59:47 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

static void	insert_elem(t_list **l, t_list *elem, int size)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = *l;
	while (i <= size && VALUE(tmp) < VALUE(elem))
	{
		tmp = tmp->next;
		i++;
	}
	ft_lst_insert(l, elem, i);
}

void    print_l(t_list *l);

static void	del(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

void		insertion_sort(t_list **l)
{
	t_list	*sortedlist;
	t_list	*tmplist;
	t_list	*tmp;
	int		size;

	if (!*l)
		return ;
	sortedlist = ft_lstnew((*l)->content, sizeof(int));
	tmplist = (*l)->next;
	size = 1;
	while (tmplist)
	{
		tmp = ft_lstnew(tmplist->content, sizeof(int));
		insert_elem(&sortedlist, tmp, size);
		//	print_l(sortedlist);
		size++;
		tmplist = tmplist->next;
	}
	ft_lstdel(l, del);
	*l = sortedlist;
}


/*void		insertion_sort(t_list **l)
{
	t_list	*tmplist;
	t_list	*tmp;
	int		size;

	if (!*l)
		return ;
	tmplist = *l;
	tmp = (*l)->next;
	size = 1;
	while (tmplist->next)
	{
		tmp = tmplist->next;
		tmplist->next = tmp->next;
//		print_l(*l);
		insert_elem(l, tmp, size);
//		print_l(*l);
		size++;
		tmplist = ft_lst_at(*l, size);
	}
}*/
