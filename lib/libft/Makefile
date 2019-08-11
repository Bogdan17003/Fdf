# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 18:40:56 by bdeomin           #+#    #+#              #
#    Updated: 2018/10/25 18:41:03 by bdeomin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
C_FILE  = *.c
O_FILE  = *.o
FLAGS   = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):
			gcc $(FLAGS) -c $(C_FILE)
			ar rc $(NAME) $(O_FILE)
			ranlib $(NAME)
clean:
			/bin/rm -f $(O_FILE)
fclean:	clean
			/bin/rm -f $(NAME)
re: 	fclean all