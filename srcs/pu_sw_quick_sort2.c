/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_sw_quick_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:42:20 by epillot           #+#    #+#             */
/*   Updated: 2017/02/11 19:14:06 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_lower_elem(t_ll *l, int val, int size)
{
	int		pos;

	pos = 1;
	while (pos <= size)
	{
		if (l->val < val)
			return (pos);
		l = l->next;
		pos++;
	}
	return (0);
}

static int	partition(t_ll **la, t_ll **lb, int size, t_list **cmd)
{
	t_ll	*piv;
	t_pos	pos;
	int		i;
	t_ll	*tmp;

	piv = *la;
	tmp = *la;
	pos.start = 1;
	while ((pos.final = find_lower_elem(tmp, piv->val, size)))
	{
		pos.start = ll_go_to(la, pos, "a", cmd);
		exec_cmd_p("b", la, lb);
		add_cmd_in_list("p", "b", cmd);
		size--;
	}
	i = 1;
	pos.final = 1;
	ll_go_to(la, pos, "a", cmd);
	size = 0;
	if (*lb)
		size = (*lb)->size;
	while (i++ <= size)
	{
		exec_cmd_p("a", la, lb);
		add_cmd_in_list("p", "a", cmd);
	}
	return (size);
}

void		quick_sort_aux(t_ll **la, t_ll **lb, int size, t_list **cmd)
{
	t_pos	pos;
	int		size_in;

	if (size <= 1)
		return ;
	size_in = size;
	size = partition(la, lb, size, cmd);
	quick_sort_aux(la, lb, size, cmd);
	pos.start = 1;
	pos.final = size + 2;
	pos.start = ll_go_to(la, pos, "a", cmd);
	quick_sort_aux(la, lb, size_in - size - 1, cmd);
	pos.final = 1;
	ll_go_to(la, pos, "a", cmd);
}

/*static int      cmp(const void *elem1, const void *elem2)
{
        const int *t1 = elem1;
        const int *t2 = elem2;

        return (*t1 - *t2);
}

int     get_pivot(t_ll *l, int size)
{
        int             *tab;
        int             i;
        int     val;

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
      i = 1;
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
        return (i);
}

int     find_pos_piv(t_ll *l, int val)
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
}*/

t_list		*pu_sw_quick_sort(t_ll **la, t_ll **lb)
{
	t_list	*cmd;

	cmd = NULL;
/*	t_pos pos;
	pos.start = 1;
	pos.final = find_pos_piv(*la, get_pivot(*la, (*la)->size));
	ll_go_to(la, pos, "a", &cmd);*/
	quick_sort_aux(la, lb, (*la)->size, &cmd);
	return (cmd);
}
