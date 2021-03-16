# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 15:41:28 by jacens            #+#    #+#              #
#    Updated: 2021/03/16 17:20:58 by jacens           ###   ########lyon.fr    #
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

all: directories $(NAME)

$(NAME): $(OBJ)
	@echo "\n\033[0;34m  [UPDATE]\033[0m \033[1;30m CREATED:\033[0m \033 \033[0m \033[0;36m $(NAME)\033[0m\n"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

directories:
	@echo  "\n\033[0;35m [BUILDING]\033[0m\033[0m\033[0;36m $(NAME)\033[0m\n"

%.o : %.cpp $(INCS)
	@echo "\033[0;32m   [ OK ] \033[0m \033[0;33m Compiling:\033[0m" $<
	@$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re directories