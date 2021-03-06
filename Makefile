# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 20:57:32 by bboutoil          #+#    #+#              #
#    Updated: 2019/02/19 21:52:24 by bboutoil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


##### DEPENDENCIES #############################################################

LIB_DIR:= lib
LIBFT_URL:= https://gitlab.com/gigistone/libft.git
LIBFT_DIR:= $(LIB_DIR)/libft
LIBFT_HEADERS:=$(LIBFT_DIR)/includes
LIBFT_NAME:= $(LIBFT_DIR)/libft.a

PRINTF_URL:= https://gitlab.com/gigistone/printf
PRINTF_DIR:= $(LIB_DIR)/printf
PRINTF_HEADERS:=$(PRINTF_DIR)/inc
PRINTF_NAME:= $(PRINTF_DIR)/libftprintf.a


##### PROJECT & ASSETS #########################################################

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
SRC+= $(SRC_DIR)/directory.c
SRC+= $(SRC_DIR)/ft_ls.c
SRC+= $(SRC_DIR)/error.c
OBJ= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)


##### TOOLS ####################################################################

CC = gcc
LINK = gcc
CFLAGS += -Wall
# CFLAGS += -Werror
CFLAGS += -Wextra
CFLAGS += -g
CFLAGS += -I $(INC_DIR)/ -I $(LIBFT_HEADERS)/ -I $(PRINTF_HEADERS)/
CFLAGS += -L $(LIBFT_DIR) -L $(PRINTF_DIR)
MKDIR:= mkdir -p
MAKE:= make -C


################################################################################
################################################################################

.PHONY: all clean fclean re test debug configure
.SUFFIXES:
.SUFFIXES: .c .o

all : $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	$(LINK) $(CFLAGS) $^ -o $@ -lft -lftprintf

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

# $(OBJ_DIR)/%.o : $(TEST_DIR)/%.c
# 	$(CC) $(CFLAGS) -c $^ -o $@

# $(OBJ_DIR)/%.o : $(DEBUG_DIR)/%.c
# 	$(CC) $(CFLAGS) -c $^ -o $@

configure: $(LIBFT_NAME) $(PRINTF_NAME)
	@echo
	@echo "----------------------------"
	@echo "-> Dependencies restored."
	@echo "-> Workspace ready."

$(LIBFT_NAME): $(LIBFT_DIR)
	@make -C $^

$(PRINTF_NAME): $(PRINTF_DIR)
	@make -C $^

$(LIBFT_DIR): $(LIB_DIR)
	@git clone $(LIBFT_URL) $@

$(PRINTF_DIR): $(LIB_DIR)
	@git clone $(PRINTF_URL) $@

$(OBJ_DIR):
	@$(MKDIR) $@

$(LIB_DIR):
	@$(MKDIR) $@

clean:
	$(RM) $(OBJ) $(DEBUG_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all


# debug: $(ALL)
# 	$(LINK) -g -I $(INC_DIR) -L $(NAME_DIR) $(DEBUG_LAUNCHER) \
# 	-o $(DEBUG_DIR)/$(DEBUG_TARGET) -$(NAME_LIBNAME)
