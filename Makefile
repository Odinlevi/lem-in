# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnikifor <mnikifor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 14:58:43 by mnikifor          #+#    #+#              #
#    Updated: 2018/02/19 13:59:38 by mnikifor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

INCLUDE = ./includes/

SRC = main.c algo.c add_func.c run_ants.c \
      sort_del.c add_func2.c save_all.c prints_all.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra 
 
all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	@make -C ./libft/
	@gcc $(FLAGS) $(OBJ) ./libft/libft.a -o $(NAME)

%.o: %.c
	@gcc -c -Wextra -Wall -o $@ $<

clean:
	@make clean -C ./libft/
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C ./libft/
	@rm -rf $(NAME)

re: fclean all
