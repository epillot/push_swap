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

static void	insert_elem(t_list **l, t_list *elem)//, int size)
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

void    print_l(t_list *l);

void	del(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

/*void		insertion_sort(t_list **l)
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
}*/


void		insertion_sort(t_list **l)
{
	t_list	*tmplist;
	t_list	*tmp;

	if (!*l)
		return ;
	tmplist = *l;
//	ft_putchar('\n');
	while (tmplist->next)
	{
		if (VALUE(tmplist) > VALUE(tmplist->next))
		{
			tmp = tmplist->next;
			tmplist->next = tmp->next;
//			ft_printf("on prend le maillon: %d\n", VALUE(tmp));
//			print_l(*l);
//			ft_printf("on l'insert avec size = %d\n", size);
			insert_elem(l, tmp);
//			print_l(*l);
//			ft_putchar('\n');
		}
		else	
			tmplist = tmplist->next;
	//	tmplist = ft_lst_at(*l, size);
	}
}
