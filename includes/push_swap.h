/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:34:42 by epillot           #+#    #+#             */
/*   Updated: 2017/02/15 18:47:56 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"

# define C_NONE "\033[0m"
# define C_RED "\033[31m"
# define C_GREEN "\033[32m"
# define C_YELLOW "\033[33m"
# define C_BLUE "\033[34m"
# define C_MAGENTA "\033[35m"
# define C_CYAN "\033[36m"

typedef struct	s_psopt
{
	int		n;
	int		v;
}				t_psopt;

typedef struct	s_ll
{
	int			val;
	int			size;
	struct s_ll	*next;
	struct s_ll	*prev;
}				t_ll;

typedef struct	s_pos
{
	int		start;
	int		final;
}				t_pos;

int				get_option_pu_sw(int ac, char **av, t_psopt *opt);
int				init_la(int ac, char **av, t_ll **la);
int				check_double(t_ll *l);
int				get_cmd_list(t_list **cmd);
void			exec_all(t_list *cmd_list, t_ll **la, t_ll **lb, t_psopt opt);
t_ll			*ll_new(int n);
void			ll_addback(t_ll *l, t_ll *elem);
void			ll_swap(t_ll *l);
void			ll_addfront(t_ll **l, t_ll *elem);
void			ll_size_rec(t_ll *l, int new_size);
int				l_is_sort(t_ll *l, int way);
void			push_elem(t_ll **on, t_ll **from);
void			ll_free(t_ll **l);
int				is_mini_revlist(t_ll *l);
void			apply_good_sort(t_ll **la, t_ll **lb, int *tab, t_list *cmd[]);
int				find_best_sort(t_ll **la, t_ll **lb, t_list *cmd[]);
void			exec_cmd(char *cmd, t_ll **la, t_ll **lb);
int				ll_go_to(t_ll **l, t_pos pos, char *list_name, t_list **cmd);
void			add_cmd_in_list(char *str, char *list_name, t_list **list);
int				get_median(t_ll *l, int size);
int				find_lower_elem(t_ll *l, int val, int size);
t_list			*pu_sw_bubble_sort(t_ll *l);
t_list			*pu_sw_sel_sort(t_ll **la, t_ll **lb);
t_list			*pu_sw_ins_sort(t_ll **la, t_ll **lb);
t_list			*quick_sort_large(t_ll **la, t_ll **lb);
t_list			*quick_sort_medium(t_ll **la, t_ll **lb);
void			sort_little_part(t_ll **la, t_ll **lb, int size, t_list **cmd);

#endif
