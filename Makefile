# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 20:57:32 by bboutoil          #+#    #+#              #
#    Updated: 2019/02/09 20:59:22 by bboutoil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=ft_ls

NAME_DIR:= .
INC_DIR:= inc
SRC_DIR:= src
OBJ_DIR:= obj
DEBUG_DIR:= .vscode/debug

DEBUG_TARGET:= debug.out
DEBUG_LAUNCHER:= $(DEBUG_DIR)/main.c
DEBUG_OBJ= $(DEBUG_SRC:$(DEBUG_DIR)%.c=$(OBJ_DIR)%.o)

SRC+= $(SRC_DIR)/param.c
SRC+= $(SRC_DIR)/main.c
SRC+= $(SRC_DIR)/file.c
OBJ= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CC = gcc
LINK = gcc
CFLAGS += -Wall
# CFLAGS += -Werror
CFLAGS += -Wextra
CFLAGS += -g
CFLAGS += -I $(INC_DIR)/

MKDIR:= mkdir -p


.PHONY: all clean fclean re test debug
.SUFFIXES:
.SUFFIXES: .c .o

all : $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	$(LINK) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

# $(OBJ_DIR)/%.o : $(TEST_DIR)/%.c
# 	$(CC) $(CFLAGS) -c $^ -o $@

# $(OBJ_DIR)/%.o : $(DEBUG_DIR)/%.c
# 	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJ_DIR):
	$(MKDIR) $@

clean:
	$(RM) $(OBJ) $(DEBUG_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# test: $(TEST)
# 	-@./$(TEST)

# $(TEST) : $(ALL) $(OBJ) $(TEST_OBJ)
# 	$(LINK) $(CFLAGS) $^ -o $@

# debug: $(ALL)
# 	$(LINK) -g -I $(INC_DIR) -L $(NAME_DIR) $(DEBUG_LAUNCHER) \
# 	-o $(DEBUG_DIR)/$(DEBUG_TARGET) -$(NAME_LIBNAME)
