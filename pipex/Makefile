# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 14:39:27 by agheredi          #+#    #+#              #
#    Updated: 2023/12/27 10:00:21 by agusheredia      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
FLAGS = -Wall -Werror -Wextra -g #-fsanitize='address,undefined'
SRC = main.c \
	pipex_utils.c \
	exit.c \
	pipe.c \

SRCS_BONUS = pipex_bonus.c \

CC = gcc
LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a
OBJ_DIR = obj
OBJECTS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
HEADER = pipex.h
OBJS_DIR_BONUS = obj_bonus
OBJS_BONUS = $(addprefix $(OBJS_DIR_BONUS)/,$(SRCS_BONUS:.c=.o))
HEADER_BONUS = pipex_bonus.h 

all: subsystems $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER) Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c -o $@ $<

subsystems:
	make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(LIBFT_LIB) -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

bonus: .bonus

.bonus : $(OBJS_BONUS) $(HEADER_BONUS)
	ar -rcs $(NAME) $(OBJS_BONUS)
	@touch .bonus

.PHONY: all re clean fclean subsystems bonus
