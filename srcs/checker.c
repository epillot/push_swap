/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:04:36 by epillot           #+#    #+#             */
/*   Updated: 2017/02/15 18:51:00 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(t_ll **la, t_ll **lb, t_list **cmd)
{
	ll_free(la);
	ll_free(lb);
	if (*cmd)
		ft_lstdel(cmd, &ft_lstfree_cnt);
}

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
	cmd = NULL;
	if (!(get_cmd_list(&cmd)))
		return (1);
	exec_all(cmd, &la, &lb, opt);
	ft_putendl(l_is_sort(la, 0) && !lb ? "OK" : "KO");
	free_all(&la, &lb, &cmd);
	return (0);
}
