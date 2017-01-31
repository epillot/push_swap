# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epillot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/04 16:40:08 by epillot           #+#    #+#              #
#    Updated: 2017/01/27 14:04:20 by epillot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

FLAG = -Wall -Wextra -Werror

SRC_NAME = 	main.c\
			exec_cmd.c\
			exec_cmd_p.c\
			exec_cmd_r.c\
			exec_cmd_rr.c\
			exec_cmd_s.c\

SRC_PATH = srcs/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj/

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INC = ./includes/

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAG) -o $(NAME) $(OBJ) -I $(INC) -L ./libft/ -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p obj
	gcc $(FLAG) -c -I $(INC) $< -o $@

clean:
	make fclean -C libft/
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
