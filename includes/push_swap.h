/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:34:42 by epillot           #+#    #+#             */
/*   Updated: 2017/02/11 18:57:30 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"

typedef struct s_psopt
{
	int		n;
	int		v;
}		t_psopt;

typedef struct s_ll
{
	int			val;
	int			size;
	struct s_ll	*next;
	struct s_ll	*prev;
}		t_ll;

typedef struct s_pos
{
	int		start;
	int		final;
}		t_pos;

int		get_option_pu_sw(int ac, char **av, t_psopt *opt);
int		init_la(int ac, char **av, t_ll **la);
int     check_double(t_ll *l);
int		get_cmd_list(t_list **cmd);
void	exec_all(t_list *cmd_list, t_ll **la, t_ll **lb, t_psopt opt);
t_ll	*ll_new(int n);
void	ll_addback(t_ll *l, t_ll *elem);
void    ll_swap(t_ll *l);
void	ll_addfront(t_ll **l, t_ll *elem);
void	ll_size_rec(t_ll *l, int new_size);
int     l_is_sort(t_ll *l, int way);
void	ll_free(t_ll **l);
int		apply_all_sort(t_ll **la, t_ll **lb, t_list *cmd[]);
void	exec_cmd(char *cmd, t_ll **la, t_ll **lb);
void	exec_cmd_s(char *cmd, t_ll *la, t_ll *lb);
void	exec_cmd_p(char *cmd, t_ll **la, t_ll **lb);
void	exec_cmd_r(char *cmd, t_ll **la, t_ll **lb);
void	exec_cmd_rr(char *cmd, t_ll **la, t_ll **lb);
int		ll_go_to(t_ll **l, t_pos pos, char *list_name, t_list **cmd);
void	add_cmd_in_list(char *str, char *list_name, t_list **list);
t_list	*pu_sw_bubble_sort(t_ll *l);
t_list	*pu_sw_sel_sort(t_ll **la, t_ll **lb);
t_list	*pu_sw_ins_sort(t_ll **la, t_ll **lb);
t_list	*pu_sw_ins_sort2(t_ll **la, t_ll **lb);
t_list	*pu_sw_quick_sort(t_ll **la, t_ll **lb);

#endif
