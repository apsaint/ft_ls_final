# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/23 21:47:01 by bboutoil          #+#    #+#              #
#    Updated: 2019/02/19 16:52:37 by bboutoil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= libftprintf.a
NAME_LIBNAME := lftprintf

NAME_DIR:= .
INC_DIR:= inc
SRC_DIR:= src
OBJ_DIR:= obj
DEBUG_DIR:= .vscode/debug

# TEST:= test.out
# TEST_DIR:=test
# TEST_SRC+=$(TEST_DIR)/test.c
# TEST_SRC+=$(TEST_DIR)/unity.c
# TEST_OBJ= $(TEST_SRC:$(TEST_DIR)%.c=$(OBJ_DIR)%.o)

DEBUG_TARGET:= debug.out
DEBUG_LAUNCHER:= $(DEBUG_DIR)/main.c
DEBUG_OBJ= $(DEBUG_SRC:$(DEBUG_DIR)%.c=$(OBJ_DIR)%.o)

SRC+= $(SRC_DIR)/ft_printf.c
SRC+= $(SRC_DIR)/numerics.c
SRC+= $(SRC_DIR)/eval_attr.c
SRC+= $(SRC_DIR)/eval_spec.c
SRC+= $(SRC_DIR)/integers.c
SRC+= $(SRC_DIR)/utils.c
SRC+= $(SRC_DIR)/format_num.c
SRC+= $(SRC_DIR)/format_text.c
SRC+= $(SRC_DIR)/floats.c
SRC+= $(SRC_DIR)/display.c
SRC+= $(SRC_DIR)/buffer.c

OBJ= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CC:= gcc
LINK:= gcc
AR:= ar
ARFLAGS:= rcvs
CFLAGS+= -Wall
CFLAGS+= -Wextra
CFLAGS+= -Werror
# CFLAGS += -g
CFLAGS+= -I $(INC_DIR)/

MKDIR:= mkdir -p

.PHONY: all clean fclean re test debug
.SUFFIXES:
.SUFFIXES: .c .o

all : $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $?

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJ_DIR)/%.o : $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJ_DIR)/%.o : $(DEBUG_DIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJ_DIR):
	$(MKDIR) $@

clean:
	$(RM) $(OBJ) $(DEBUG_OBJ)

fclean: clean
	$(RM) $(NAME) $(DEBUG_DIR)/$(DEBUG_TARGET)

re: fclean all

test: $(TEST)
	-@./$(TEST)

$(TEST) : $(ALL) $(OBJ) $(TEST_OBJ)
	$(LINK) $(CFLAGS) $^ -o $@

debug: $(ALL)
	$(LINK) -g -I $(INC_DIR) -L $(NAME_DIR) $(DEBUG_LAUNCHER) \
	-o $(DEBUG_DIR)/$(DEBUG_TARGET) -$(NAME_LIBNAME)
