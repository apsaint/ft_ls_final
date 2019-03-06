# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 20:57:32 by bboutoil          #+#    #+#              #
#    Updated: 2019/03/06 13:10:23 by apsaint-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


##### DEPENDENCIES #############################################################

LIB_DIR:= libft
LIBFT_DIR:= $(LIB_DIR)/libft
LIBFT_HEADERS:=$(LIBFT_DIR)/includes
LIBFT_NAME:= $(LIBFT_DIR)/libft.a

PRINTF_DIR:= $(LIB_DIR)/printf
PRINTF_HEADERS:=$(PRINTF_DIR)/inc
PRINTF_NAME:= $(PRINTF_DIR)/libftprintf.a


##### PROJECT & ASSETS #########################################################

NAME:=ft_ls
NAME_DIR:= .
INC_DIR:= inc
SRC_DIR:= src
OBJ_DIR:= obj

HEADERS+= $(INC_DIR)/ls_constants.h
HEADERS+= $(INC_DIR)/ls_types.h
HEADERS+= $(INC_DIR)/ft_ls.h

SRC+= $(SRC_DIR)/param.c
SRC+= $(SRC_DIR)/flag.c
SRC+= $(SRC_DIR)/main.c
SRC+= $(SRC_DIR)/core.c
SRC+= $(SRC_DIR)/directory.c
SRC+= $(SRC_DIR)/error.c
SRC+= $(SRC_DIR)/file_stat.c
SRC+= $(SRC_DIR)/time.c
SRC+= $(SRC_DIR)/file_list.c
SRC+= $(SRC_DIR)/file_list_sorting.c
SRC+= $(SRC_DIR)/display.c
SRC+= $(SRC_DIR)/display_lf.c
SRC+= $(SRC_DIR)/utils.c
SRC+= $(SRC_DIR)/utils_mode.c
SRC+= $(SRC_DIR)/utils_collect.c
SRC+= $(SRC_DIR)/utils_compare.c
SRC+= $(SRC_DIR)/path.c
SRC+= $(SRC_DIR)/path_utils.c
OBJ= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)


##### TOOLS ####################################################################

CC = gcc
LINK = gcc
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra
CFLAGS += -g3
CFLAGS += -I $(INC_DIR)/ -I $(LIBFT_HEADERS)/ -I $(PRINTF_HEADERS)/
CLIBS += -L $(LIBFT_DIR) -L $(PRINTF_DIR)
MKDIR:= mkdir -p
MAKE:= make -C


################################################################################
################################################################################

.PHONY: all clean fclean re test debug configure
.SUFFIXES:
.SUFFIXES: .c .o

all : $(OBJ_DIR) $(LIBFT_NAME) $(PRINTF_NAME) $(NAME) $(HEADERS)

$(NAME): $(OBJ) $(HEADERS)
	$(LINK) $(CFLAGS) $(CLIBS) $(OBJ) -o $@ -lft -lftprintf

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBFT_NAME): $(LIBFT_DIR)
	@make -C $^

$(PRINTF_NAME): $(PRINTF_DIR)
	@make -C $^

$(OBJ_DIR):
	@$(MKDIR) $@

$(LIB_DIR):
	@$(MKDIR) $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
