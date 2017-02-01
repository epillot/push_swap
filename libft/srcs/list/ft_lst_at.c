/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:14:47 by epillot           #+#    #+#             */
/*   Updated: 2017/02/01 16:58:02 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_at(t_list *lst, int nb)
{
	if (nb <= 0)
		return (NULL);
	while (nb != 1 && lst)
	{
		lst = lst->next;
		nb--;
	}
	return (lst);
}
