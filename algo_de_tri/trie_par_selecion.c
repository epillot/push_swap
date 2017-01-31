/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_par_selecion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:27:31 by epillot           #+#    #+#             */
/*   Updated: 2017/01/27 14:36:46 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tri.h"

int		find_max_index(int *tab, int size)
{
	int i = 0;
	int i_max = 0;

	while (i < size)
	{
		if (tab[i] > tab[i_max])
			i_max = i;
		i++;
	}
	return (i_max);
}

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	tri_par_selection(int *tab, int size)
{
	int ind;
	int i = 0;

	if (size == 0)
		return ;
	while (i < size)
	{
		ind = find_max_index(tab, size - i);
		ft_swap(tab + size -i - 1, tab + ind);
		i++;
	}
}
