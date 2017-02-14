/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_sw_quick_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:42:20 by epillot           #+#    #+#             */
/*   Updated: 2017/02/11 20:22:29 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_lower_elem(t_ll *l, int val, int size)
{
	int		pos;

	pos = 1;
	while (pos <= size)
	{
		if (l->val <= val)
			return (pos);
		l = l->next;
		pos++;
	}
	return (0);;
}

static int	cmp(const void *elem1, const void *elem2)
{
	const int *t1 = elem1;
	const int *t2 = elem2;

	return (*t1 - *t2);
}

int	get_pivot(t_ll *l, int size)
{
	int		*tab;
	int		i;
	int 	val;

	i = 0;
	tab = malloc(sizeof(int) * size);
	while (i < size)
	{
		tab[i++] = l->val;
		l = l->next;
	}
	qsort(tab, size, 4, &cmp);
	val = tab[size / 2];
	free(tab);
	return (val);
/*	i = 1;
	while (++i < size)
		ft_printf("%d ", tab[i]);
	ft_putchar('\n');
	while (l->val != val)
	{
		i++;
		l = l->next;
	}
	*piv = l;
	free(tab);
	return (i);*/
}

int	find_pos_piv(t_ll *l, int val)
{
	int i;

	i = 1;
	if (!l)
		return (0);
	while (l->val != val)
	{
		i++;
		l = l->next;
	}
	return (i);
}

void    print_list(t_ll *l);

static int	partition(t_ll **la, t_ll **lb, int size, t_list **cmd)
{
	int	piv;
	t_pos	pos;
	int		i;
	t_ll	*begin;

	piv = get_pivot(*la, size);
//	ft_putstr("la: ");
//	print_list(*la);
//	ft_printf("%d ", piv);
	begin = *la;
	pos.start = 1;
	i = 0;
	while ((pos.final = find_lower_elem(begin, piv, size)))
	{
		pos.start = ll_go_to(la, pos, "a", cmd);
		exec_cmd_p("b", la, lb);
		add_cmd_in_list("p", "b", cmd);
		if (pos.final == 1)
			begin = (*la);
		size--;
		i++;
	}
	pos.final = 1;
	ll_go_to(la, pos, "a", cmd);
/*	pos.start = 1;
	pos.final = find_pos_piv(*lb, piv);
	ll_go_to(lb, pos, "b", cmd);
	size = 0;
	if (*lb)
		size = (*lb)->size;
	i = 1;
	if (size <= 50 && size >= 2)
		rev_sort_little(lb, la, cmd);
	while (i++ <= size)
	{
		exec_cmd_p("a", la, lb);
		add_cmd_in_list("p", "a", cmd);
	}*/
	return (i);
}

void		quick_sort_aux(t_ll **la, t_ll **lb, int size, t_list **cmd)
{
//	t_pos	pos;
//	int		sizeb = 0;

	if (size <= 1)
		return ;
	while ((*la)->size >= 3)
	{
		partition(la, lb, size, cmd);
	}
	/*	quick_sort_aux(la, lb, size - 1, cmd);
		pos.start = 1;
        	pos.final = size + 1;
       		pos.start = ll_go_to(la, pos, "a", cmd);
        	quick_sort_aux(la, lb, size_in - size, cmd);
        	pos.final = 1;
        	ll_go_to(la, pos, "a", cmd);*/
//	}
//	else
//		little_sort(la, lb, size, cmd);
}

t_list		*pu_sw_quick_sort(t_ll **la, t_ll **lb)
{
	t_list	*cmd;

	cmd = NULL;
	quick_sort_aux(la, lb, (*la)->size, &cmd);
//	little_sort(la, lb, (*la)->size, &cmd);
	return (cmd);
}
