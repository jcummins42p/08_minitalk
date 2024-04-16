# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcummins <jcummins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 18:08:59 by jcummins          #+#    #+#              #
#    Updated: 2024/04/16 21:36:39 by jcummins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CLIENT = client
SERVER = server

HEADER_DIR = include
SRC_DIR = src
OBJ_DIR = obj
CC = cc
CFLAGS = -g -Werror -Wextra -Wall -pedantic -I$(HEADER_DIR)
LIB = lib/libft.a

CLIENT_SRCS = $(shell find $(SRC_DIR)/client -name '*.c')
SERVER_SRCS = $(shell find $(SRC_DIR)/server -name '*.c')

CLIENT_OBJS = $(CLIENT_SRCS:$(SRC_DIR)/client/%.c=$(OBJ_DIR)/client/%.o)
SERVER_OBJS = $(SERVER_SRCS:$(SRC_DIR)/server/%.c=$(OBJ_DIR)/server/%.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIB)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIB)

$(OBJ_DIR)/client/%.o:	$(SRC_DIR)/client/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/server/%.o:	$(SRC_DIR)/server/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing all object files"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Removing all object files and executable"
	@rm -rf $(CLIENT) $(SERVER)

re:	fclean all

.PHONY: all clean fclean re
