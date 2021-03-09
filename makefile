# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 15:41:28 by jacens            #+#    #+#              #
#    Updated: 2021/03/09 12:23:27 by jacens           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME    =   libft.a

CC      =   gcc 
CFLAGS  =   -Wall -Wextra -Werror
HEADER 	=    include/
LFLAGS  =   -I $(HEADER)
INCS 	=  $(shell find . -name "*.hpp")

SRCS 	=  $(shell find . -name "*.cpp")

OBJ    	=   $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.cpp $(INCS)
	$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re