/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:34:42 by epillot           #+#    #+#             */
/*   Updated: 2017/02/02 19:47:20 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"

# define VALUE(list) *(int*)(list->content)

typedef struct s_ll
{
	int			val;
	int			size;
	struct s_ll	*next;
	struct s_ll	*prev;
}		t_ll;

int		check_error_param(int ac, char **av);
void	init_la(int ac, char **av, t_ll **la);
t_ll	*ll_new(int n);
void	ll_addback(t_ll *l, t_ll *elem);
void    ll_swap(t_ll *l);
void	ll_addfront(t_ll **l, t_ll *elem);
void	ll_size_rec(t_ll *l, int new_size);
int     l_is_sort(t_ll *l, int way);
void	exec_cmd(char *cmd, t_ll **la, t_ll **lb);
void	exec_cmd_s(char *cmd, t_ll *la, t_ll *lb);
void	exec_cmd_p(char *cmd, t_ll **la, t_ll **lb);
void	exec_cmd_r(char *cmd, t_ll **la, t_ll **lb);
void	exec_cmd_rr(char *cmd, t_ll **la, t_ll **lb);
void	pu_sw_bubble_sort(t_ll *l);

#endif
