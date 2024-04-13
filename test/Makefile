# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgerwig- <dgerwig-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 19:19:43 by dgerwig-          #+#    #+#              #
#    Updated: 2024/01/22 20:18:53 by dgerwig-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	test_libasm

CC          = 	gcc
CFLAGS		= 	-Wall -Wextra -Werror -g #-Wno-format # used to suppress warnings related to formatting in the source code when compiling with GCC

SRC			=	main.c

OBJ_DIR		= 	obj/

OBJ 		:=	$(addsuffix .o, $(basename $(SRC)))

all: $(NAME)

$(NAME): $(OBJ) 
	@cp ../lib/libasm.a .
	@echo "abcdefghijklmnopqrstuvwxyz " > ../_file_read_test1.txt
	$(CC) $(CFLAGS) $(OBJ) -L. -lasm -o $(NAME)
	@echo $(C_GREEN)"✅ CREATED: $(NAME)    // Compiled with: $(CC) $(CFLAGS) \n"$(C_RESET)
	@mkdir -p $(OBJ_DIR)
	@mv *.o $(OBJ_DIR)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)
	@rm -rf libasm.a
	
fclean: clean
	@rm -f $(NAME)
	@echo $(C_RED) "🗑  REMOVED: $(NAME)\n" $(C_RESET)

re:	fclean all

.PHONY: all clean fclean re

C_RED 		= 	'\033[0;31m'
C_GREEN 	= 	'\033[0;32m'
C_YELLOW 	= 	'\033[0;33m'
C_BLUE 		= 	'\033[0;34m'
C_PURPLE 	= 	'\033[0;35'
C_CYAN 		= 	'\033[0;36m'
C_RESET 	= 	'\033[0m'