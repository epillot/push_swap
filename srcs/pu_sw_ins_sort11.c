#include "push_swap.h"

static int	find_bad_elem(t_ll *l)
{
	int	size;
	int	i;

	if (!l)
		return (0);	
	i = 1;
	size = l->size;
	while (i < size && l->val <= l->next->val)
	{
		l = l->next;
		i++;
	}
	if (i == size)
		return (0);
	return (i + 1);
}

static int	find_good_pos(t_ll *l, int val)
{
	int pos;
	int size;
	
	
	pos = 1;
	if (!l)
		return (1);
	size = l->size;
	while (pos <= size && val >= l->val)
	{
		l = l->next;
		pos++;
	}
	return (pos);
}

void	pu_sw_ins_sort(t_ll **la, t_ll **lb)
{
	int	i;
	int	size;
	t_ll	*begin;
	int	j;

	begin = *la;
	size = (*la)->size;
	j = 1;
	while ((i = find_bad_elem(begin)))
	{
	//	ft_printf("bad en pos: %d, actuellement en pos: %d\n", i, j);
		j = ll_go_to(la, j, i);
		exec_cmd_p("b", la, lb);
		ft_putendl("pb");
		i = find_good_pos(begin, (*lb)->val);
		j = ll_go_to(la, j, i);
		if (i == 1)
                        begin = (*lb);
                exec_cmd_p("a", la, lb);
                ft_putendl("pa");
	}
//	ll_go_to(la, j, 1);
/*	size = 0;
	if (*lb)
		size = (*lb)->size;
	while (size--)
	{
		i = find_good_pos(begin, (*lb)->val);
	//	ft_printf(" good pos: %d, actuellement en pos: %d\n", i, j);
		j = ll_go_to(la, j, i);
		if (i == 1)
			begin = (*lb);
		exec_cmd_p("a", la, lb);
                ft_putendl("pa");
	}*/
	ll_go_to(la, j, 1);
}
