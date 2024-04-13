# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgerwig- <dgerwig-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 19:52:23 by dgerwig-          #+#    #+#              #
#    Updated: 2024/02/01 17:04:33 by dgerwig-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= lib/libasm.a

ASM			= nasm

lowercase 	= $(shell echo $1 | tr 'A-Z' 'a-z')

unamestr 	= $(call lowercase,$(shell uname))

ifeq ($(unamestr),darwin)
    ASM_FLAGS = -f macho64 -g   	
# -f: Command-line option used to specify the output format.
# macho64: This specific argument for -f indicates that the output format should be Mach-O (Mach Object) for 64-bit systems. Mach-O is a file format used by macOS for executables, object code, dynamic libraries, and bundles.
else ifeq ($(unamestr),linux)
    ASM_FLAGS = -f elf64 -g 
# elf64: This particular argument for -f indicates that the output format should be ELF (Executable and Linkable Format) for 64-bit systems. ELF is a common file format for executables, object code, shared libraries, and even core dumps on Unix-like systems.
else
    $(error Unsupported operating system: $(unamestr))
endif
											
SRC_DIR		= src/
OBJ_DIR		= obj/

SRC			= $(wildcard $(wildcard $(SRC_DIR)*.s))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(basename $(SRC))))

NASM 		= $(shell command -v nasm 2> /dev/null)
DOCKER		= $(shell docker info > /dev/null 2>&1 && echo "true" || echo "false")

all: install

install:
ifdef NASM
	@make run
else
	brew install nasm
	brew list
	@make run
endif

run: $(NAME)

$(NAME): $(OBJ)
	@mkdir -p ./lib/
	ar rcs $(NAME) $(OBJ)
	@echo $(C_GREEN)"✅ CREATED: $(NAME)    // Compiled with: $(ASM) $(ASM_FLAGS) \n"$(C_RESET)

$(OBJ_DIR)%.o: %.s
	@mkdir -p $(dir $@)
	$(ASM) $(ASM_FLAGS) -o $@ $<
	
clean:
ifeq ($(DOCKER), true)
	@make -C ./debug/ clean
endif
	@make -C ./test/ clean
	@rm -rf $(OBJ_DIR)
	@rm -rf */*.dSYM
	@rm -rf _file_*.txt
	@echo $(C_RED) "\n 🗑  REMOVED: OBJECT FILES in $(NAME)\n" $(C_RESET)

fclean: clean
	@make -C ./test/ fclean
	@rm -rf $(NAME)
	@rm -rf lib/
	@echo $(C_RED) "🗑  REMOVED: $(NAME)\n" $(C_RESET)

re:	fclean all

test: fclean all
	@make -C ./test/
	@echo $(C_YELLOW) "\r🟡 EXECUTE TEST -> ./test_libasm" $(C_RESET)
	@./test/test_libasm

valgrind: fclean all
	@make -C ./test/
	@echo $(C_YELLOW) "\r🟡 EXECUTE TEST LEAKS WITH VALGRIND -> valgrind ./test_libasm" $(C_RESET)
	@valgrind ./test/test_libasm

debug: fclean
ifeq ($(DOCKER), true)
	@make -C ./debug/
else
	@echo $(C_RED) "❗️ DOCKER is not running\n" $(C_RESET)
endif

.PHONY: all install_nasm clean fclean re test valgrind debug

C_RED 		= 	'\033[0;31m'
C_GREEN 	= 	'\033[0;32m'
C_YELLOW 	= 	'\033[0;33m'
C_BLUE 		= 	'\033[0;34m'
C_PURPLE 	= 	'\033[0;35m'
C_CYAN 		= 	'\033[0;36m'
C_RESET 	= 	'\033[0m'
