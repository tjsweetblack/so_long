# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 11:48:27 by badriano          #+#    #+#              #
#    Updated: 2024/08/20 05:57:42 by belmiro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Werror -Wextra -g
CC = cc
UTILS_DIR = ./utils
CORE_DIR = ./core
PRINTF_DIR = ./ft_printf
ERRORS_DIR = ./errors
MINILBX_DIR = ./minilibx-linux
MINILIB_LIB = libmlx.a
#MAIN = main.cexit
COMMON_SRC = $(wildcard ./*c $(ERRORS_DIR)/*.c $(CORE_DIR)/*.c $(UTILS_DIR)/*.c $(PRINTF_DIR)/*.c) # Expands to all .c files in directories
OBJ = $(COMMON_SRC:.c=.o) #$(MAIN:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(MINILBX_DIR)
	$(CC) $(CFLAGS) $(OBJ) -L$(MINILBX_DIR) -lmlx -lX11 -lXext -o $(NAME)
	@echo "Program is ready!!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(MINILBX_DIR)
	@rm -f $(OBJ)
	@echo "Object files have been cleaned successfully"

fclean: clean
	@rm -f $(NAME)
	@echo "Objects and executables removed"

re: fclean all
