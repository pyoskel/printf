# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/05 02:30:07 by pabartoc          #+#    #+#              #
#    Updated: 2026/10/26 04:45:01 by pabartoc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT :

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

# Directory-structur
SRC_DIR     = src
INC_DIR     = inc

SRCS        = $(SRC_DIR)/ft_printf.c \
			  $(SRC_DIR)/ft_printf_add_ons.c

OBJS        = $(SRCS:.c=.o)

# Default rule
all: $(NAME)

# Create the static library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "\033[1;32m ✅ [ft_printf created]\033[0m"

# Rule for compiling .c \ files into .o files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean everything (object files and library)
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re

# Ansi colors for output

# BLUE   = "\033[38;5;4m"
# GREEN  = "\033[38;5;2m"
# ORG    = "\033[38;5;214m"
# RED    = "\033[38;5;196m"
# RESET  = "\033[0m"