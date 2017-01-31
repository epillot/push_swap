/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:44:06 by epillot           #+#    #+#             */
/*   Updated: 2017/01/31 15:13:59 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tri.h"
#include "libft.h"
#include "checker.h"

void	print_l(t_list *l)
{
	while (l)
	{
		ft_printf("%d ", VALUE(l));
		l = l->next;
	}
	ft_putchar('\n');
}

void        selection_sort(t_list *l);
void        insertion_sort(t_list **l);

int		main(void)
{
	t_list *l;
	t_list *elem;
	int i = 1;
	int nb;

	srand(time(NULL));
	nb = rand() % 150;
	l = ft_lstnew(&nb, sizeof(int));
	while (i < TOT)
	{
		nb = rand() % 150;
		elem = ft_lstnew(&nb, sizeof(int));
		ft_lstadd_back(l, elem);
		i++;
	}
	print_l(l);
//	selection_sort(l);
	insertion_sort(&l);
	print_l(l);
//	printf("avant: ");
//	print_tab(tab, TOT);
//	tri_par_selection(tab, TOT);
//	printf("apres: ");
//	print_tab(tab, TOT);
}
