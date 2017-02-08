/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:04:36 by epillot           #+#    #+#             */
/*   Updated: 2017/02/08 18:28:44 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_ll	*la;
	t_ll	*lb;
	t_list	*cmd;
	t_psopt	opt;
	int		i;

	i = get_option_pu_sw(ac, av, &opt);
	ac -= i;
	av += i;
	if (!ac)
		return (0);
	la = NULL;
	lb = NULL;
	if (!(init_la(ac, av, &la)) || !(check_double(la)))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	if (!(get_cmd_list(&cmd)))
		return (1);
	exec_all(cmd, &la, &lb, opt);
	ft_putendl(l_is_sort(la, 0) && !lb ? "OK" : "KO");
	return (0);
}
