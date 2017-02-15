# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epillot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/04 16:40:08 by epillot           #+#    #+#              #
#    Updated: 2017/02/15 17:57:32 by epillot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

FLAG = -Wall -Wextra -Werror

SRC_NAME =  init_la.c\
			get_option_pu_sw.c\
			check_double.c\
			get_cmd_list.c\
			exec_all.c\
			ll_tools.c\
			ll_free.c\
			l_is_sort.c\
			push_elem.c\
			find_best_sort.c\
			apply_good_sort.c\
			exec_cmd.c\
			ll_go_to.c\
			add_cmd_in_list.c\
			is_mini_revlist.c\
			get_median.c\
			find_lower_elem.c\
			pu_sw_bubble_sort.c\
			pu_sw_sel_sort.c\
			pu_sw_ins_sort.c\
			quick_sort_medium.c\
			quick_sort_large.c\
			sort_little_part.c

MAIN1_NAME = checker.c

MAIN1_OBJ = $(addprefix $(OBJ_PATH), $(MAIN1_NAME:.c=.o))

MAIN2_NAME = push_swap.c

MAIN2_OBJ = $(addprefix $(OBJ_PATH), $(MAIN2_NAME:.c=.o))

SRC_PATH = srcs/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj/

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INC = ./includes/

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ) $(MAIN1_OBJ)
	@make -C libft/
	gcc $(FLAG) -o $(NAME1) $(OBJ) $(MAIN1_OBJ) -I $(INC) -L ./libft/ -lft
	
$(NAME2): $(OBJ) $(MAIN2_OBJ)
	@make -C libft/
	gcc $(FLAG) -o $(NAME2) $(OBJ) $(MAIN2_OBJ) -I $(INC) -L ./libft/ -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p obj
	gcc $(FLAG) -c -I $(INC) $< -o $@

clean:
	@make fclean -C libft/
	/bin/rm -f $(OBJ) $(MAIN2_OBJ) $(MAIN1_OBJ)

fclean: clean
	/bin/rm -f $(NAME1) $(NAME2)

re: fclean all
