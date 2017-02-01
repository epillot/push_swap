/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:44:06 by epillot           #+#    #+#             */
/*   Updated: 2017/02/01 19:16:49 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tri.h"
#include "libft.h"
#include "checker.h"

int		ft_lstcmp_int(t_list *elem1, t_list *elem2)
{
	return (VALUE(elem1) - VALUE(elem2));
}

void	print_l(t_list *l)
{
	while (l->next)
	{
		ft_printf("%d ", VALUE(l));
		l = l->next;
	}
	ft_printf("%d ", VALUE(l));
	ft_putchar('\n');
/*	while (l)
	{
		ft_printf("%d ", VALUE(l));
		l = l->prev;
	}
	ft_printf("\n%p\n", l);*/
}

void        selection_sort(t_list *l, int (*cmp)(t_list *, t_list *));
void        insertion_sort(t_list **l, int (*cmp)(t_list *, t_list *));
void		bubble_sort(t_list *l, int (*cmp)(t_list *, t_list *));
void		ft_lst_insert(t_list **list, t_list *elem, int pos);
void		quick_sort(t_list *l);//, int start, int end);

int		main(void)
{
	t_list *l;
	t_list *elem;
	int i = 1;
	int nb;
	t_list	*tmp;

	srand(time(NULL));
	nb = rand() % 1000;
	l = ft_lstnew(&nb, sizeof(int));
//	l->prev = NULL;
	tmp = l;
	while (i < TOT)
	{
		nb = rand() % 1000;
		elem = ft_lstnew(&nb, sizeof(int));
		ft_lstadd_back(l, elem);
		elem->prev = tmp;
		tmp = elem;
		i++;
	}
	print_l(l);
//	quick_sort(l);//, 1, ft_lst_size(l));
//		selection_sort(l, &ft_lstcmp_int);
//		insertion_sort(&l, &ft_lstcmp_int);
	bubble_sort(l, &ft_lstcmp_int);
	//	nb = 1000;
	//	elem = ft_lstnew(&nb, sizeof(int));
	//	ft_lst_insert(&l, elem, 11);
	print_l(l);
	//	printf("avant: ");
	//	print_tab(tab, TOT);
	//	tri_par_selection(tab, TOT);
	//	printf("apres: ");
	//	print_tab(tab, TOT);
}
