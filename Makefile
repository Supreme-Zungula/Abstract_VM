# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzungula <yzungula@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 12:43:00 by yzungula          #+#    #+#              #
#    Updated: 2019/07/03 12:48:18 by yzungula         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm
COMPILER= clang++ -Wall -Wextra -Werror
SRC= sources/*.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(COMPILER) $(SRC) -o $(NAME)

clean: 
	rm -rf $(NAME)

fclean:  clean

re: fclean all
