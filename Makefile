# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcummins <jcummins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 18:08:59 by jcummins          #+#    #+#              #
#    Updated: 2024/04/17 13:21:15 by jcummins         ###   ########.fr        #
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
LIB = libft.a
LIB_DIR = lib
LIB_PATH = $(LIB_DIR)/$(LIB)

CLIENT_SRCS = $(shell find $(SRC_DIR)/client -name '*.c')
SERVER_SRCS = $(shell find $(SRC_DIR)/server -name '*.c')

CLIENT_OBJS = $(CLIENT_SRCS:$(SRC_DIR)/client/%.c=$(OBJ_DIR)/client/%.o)
SERVER_OBJS = $(SERVER_SRCS:$(SRC_DIR)/server/%.c=$(OBJ_DIR)/server/%.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS) $(LIB_PATH)
	$(CC) $(CFLAGS) $^ -o $@ -L$(LIB_PATH)

$(SERVER): $(SERVER_OBJS) $(LIB_PATH)
	$(CC) $(CFLAGS) $^ -o $@ -L$(LIB_PATH)

$(OBJ_DIR)/client/%.o:	$(SRC_DIR)/client/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/server/%.o:	$(SRC_DIR)/server/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_PATH):
	@echo "Running libft make"
	@(cd $(LIB_DIR) && make)

clean:
	@echo "Removing all object files"
	@rm -rf $(OBJ_DIR)
	@(cd $(LIB_DIR) && make clean)

fclean: clean
	@echo "Removing all object files and executable"
	@rm -rf $(CLIENT) $(SERVER)
	@(cd $(LIB_DIR) && make fclean)

re:	fclean all

.PHONY: all clean fclean re
