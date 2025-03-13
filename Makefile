# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 14:26:57 by aimokhta          #+#    #+#              #
#    Updated: 2025/03/13 15:09:14 by aimokhta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g3 -O0 -fsanitize=address -fsanitize-recover=leak
CFLAGS = -Wall -Wextra -Werror -I include -I libft -I ft_printf -g3

SRC_DIR = srcs
BUILD_DIR = build
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
INCLUDE_DIR = include

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a

PUSH_SWAP_SRCS = a_to_b.c \
					b_to_a.c \
					error_handling.c \
					executions.c \
					freeing_exit.c \
					input_into_cdllist.c \
					inputting.c \
					main.c \
					opr_push.c \
					opr_reverse_rotate.c \
					opr_rotate.c \
					opr_swap.c \
					push_swap.c \
					sort_small.c \
					steps_calc.c \
					turk_algo.c \
					utils.c 

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)
PUSH_SWAP_OBJ_PATHS = $(PUSH_SWAP_OBJS:%=$(BUILD_DIR)/%)

CHECKER_SRCS = checker_bonus.c

CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
CHECKER_OBJ_PATHS = $(CHECKER_OBJS:%=$(BUILD_DIR)/%)
				
CHECKER_EXTRA_OBJS = a_to_b.o \
					b_to_a.o \
					error_handling.o \
					executions.o \
					freeing_exit.o \
					input_into_cdllist.o \
					inputting.o \
					opr_push.o \
					opr_reverse_rotate.o \
					opr_rotate.o \
					opr_swap.o \
					sort_small.o \
					steps_calc.o \
					turk_algo.o \
					push_swap.o \
					utils.o 

CHECKER_EXTRA_OBJ_PATHS = $(CHECKER_EXTRA_OBJS:%=$(BUILD_DIR)/%)

# Program Name
NAME = push_swap
CHECKER_NAME = checker

# Colour
GREEN = \033[0;32m
WHITE = \033[0m

all: $(NAME)

$(NAME): $(PUSH_SWAP_OBJ_PATHS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(PUSH_SWAP_OBJ_PATHS) $(LIBFT) $(FT_PRINTF)
	@echo "$(GREEN)----------COMPILED PUSH_SWAP DONE---------\n$(WHITE)"

checker : $(CHECKER_NAME)

$(CHECKER_NAME) : $(CHECKER_OBJ_PATHS) $(CHECKER_EXTRA_OBJ_PATHS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(CHECKER_NAME) $(CHECKER_OBJ_PATHS) $(CHECKER_EXTRA_OBJ_PATHS) $(LIBFT) $(FT_PRINTF)
	@echo "$(GREEN)----------COMPILED CHECKER DONE---------\n$(WHITE)"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(BUILD_DIR)/*.o
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(CHECKER_NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean
	@echo "$(GREEN)----------FULLY REMOVED----------\n$(WHITE)"

re: fclean all

.PHONY: all clean fclean re checkers