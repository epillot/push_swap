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

static int      find_good_pos2(t_ll *l, int val)
{
        int pos;
        int size;


        pos = 1;
        if (!l)
                return (1);
        size = l->size;
        while (pos <= size && val < l->val)
        {
                l = l->next;
                pos++;
        }
        return (pos);
}


int	ll_go_to(t_ll **l, int pos_start, int pos_fin, char c)
{
	int	diff;
	int	size;

	if (!*l)
		return (1);
	size = (*l)->size;
	/*if (pos_start > size || pos_fin > size)
	{
		ft_printf("BAD INPUT pos_start: %d, pos_fin: %d for size: %d\n", pos_start, pos_fin, size);
		exit(EXIT_FAILURE);
	}*/
	diff = pos_fin - pos_start;
	if (ft_abs(diff) <= size / 2)
	{
		if (diff > 0)
		{
			while (diff--)
			{
				(*l) = (*l)->next;
				ft_printf("r%c\n", c);
			}
		}
		else
		{
			while (diff++)
			{
				(*l) = (*l)->prev;
				ft_printf("rr%c\n", c);
			}
		}
	}
	else
	{
		if (diff > 0)
                {
			diff = size - diff;
                        while (diff--)
                        {
                                (*l) = (*l)->prev;
				ft_printf("rr%c\n", c);
                        }
                }
		else
		{
			diff = size + diff;
			while (diff--)
                        {
                                (*l) = (*l)->next;
                                ft_printf("r%c\n", c);
                        }
		}
	}
	return (pos_fin);
}

void	pu_sw_ins_sort(t_ll **la, t_ll **lb)
{
	int	i;
	int	size;
	t_ll	*begin, *begin2;
	int	j, j2;

	begin = *la;
	size = (*la)->size;
	j = 1;
	j2 = 1;
	begin2 = NULL;
	while ((i = find_bad_elem(begin)))
	{
		//ft_printf("bad en pos: %d, actuellement en pos: %d\n", i, j);
		j = ll_go_to(la, j, i, 'a');
		i = find_good_pos2(begin2, (*la)->val);
		j2 = ll_go_to(lb, j2, i, 'b');
		if (i == 1)
			begin2 = *la;
		exec_cmd_p("b", la, lb);
		ft_putendl("pb");
	}
	size = 0;
	if (*lb)
	{
		ll_go_to(lb, j2, 1, 'b');
		size = (*lb)->size;
	}
	while (size--)
	{
		i = find_good_pos(begin, (*lb)->val);
	//	ft_printf(" good pos: %d, actuellement en pos: %d\n", i, j);
		j = ll_go_to(la, j, i, 'a');
		if (i == 1)
			begin = (*lb);
		exec_cmd_p("a", la, lb);
                ft_putendl("pa");
	}
	ll_go_to(la, j, 1, 'a');
}
