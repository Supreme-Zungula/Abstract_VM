# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzungula <yzungula@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 12:43:00 by yzungula          #+#    #+#              #
#    Updated: 2019/07/04 15:13:52 by yzungula         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm
COMPILER= clang++ -Wall -Wextra -Werror -std=c++11
SRC= sources/*.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(COMPILER) $(SRC) -o $(NAME)

clean: 
	rm -rf $(NAME)

fclean:  clean

re: fclean all
