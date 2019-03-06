.PHONY: clean fclean re
.SUFFIXES:
.SUFFIXES: .c .o

SHELL := /bin/sh

# BUILD PATHS
# SRCDIR := srcs
# BUILD_DIR := build
# OBJDIR := $(BUILD_DIR)/objs
# TARGETDIR := $(BUILD_DIR)/bin
INCDIR := includes

# BUILD TOOLS AND OPTIONS
CC = gcc
LINK = gcc
AR = ar
ARFLAGS = rcvs
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I $(INCDIR)/

# TARGETS AND DEPENDENCIES
NAME = libft.a
# TARGET = $(TARGETDIR)/$(NAME)

SRC += ft_atoi.c ft_bzero.c ft_isalnum.c
SRC += ft_isalpha.c ft_isascii.c ft_isdigit.c
SRC += ft_isprint.c ft_itoa.c ft_lstadd.c
SRC += ft_lst_at.c ft_lstcount.c ft_lstdel.c
SRC += ft_lstdelone.c ft_lst_find.c ft_lstiter.c
SRC += ft_lst_last.c ft_lstmap.c ft_lstnew.c
SRC += ft_memalloc.c ft_memccpy.c
SRC += ft_memchr.c ft_memcmp.c ft_memcpy.c
SRC += ft_memdel.c ft_memmove.c ft_memset.c
SRC += ft_putchar.c ft_putchar_fd.c ft_putendl.c
SRC += ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c
SRC += ft_putstr.c ft_putstr_fd.c ft_sglist_append.c
SRC += ft_sglist_count.c ft_sglist_find.c ft_sglist_find_index.c
SRC += ft_sglist_get_node_at.c ft_sglist_new.c ft_sglist_new_empty.c
SRC += ft_sglist_remove_at.c ft_sglist_remove.c ft_strcat.c
SRC += ft_strchr.c ft_strclr.c ft_strcmp.c
SRC += ft_strcpy.c ft_strdel.c ft_strdup.c
SRC += ft_strequ.c ft_striter.c ft_striteri.c
SRC += ft_strjoin.c ft_strlcat.c ft_strlen.c
SRC += ft_strmap.c ft_strmapi.c ft_strncat.c
SRC += ft_strncmp.c ft_strncpy.c ft_strndup.c
SRC += ft_strnequ.c ft_strnew.c ft_strnlen.c
SRC += ft_strnstr.c ft_strrchr.c
SRC += ft_strsplit.c ft_strstr.c ft_strsub.c
SRC += ft_strtrim.c ft_tolower.c ft_toupper.c
SRC += ft_isspace.c ft_gnl.c ft_stradd.c
SRC += ft_strarr_del.c ft_strrev.c ft_pow.c

OBJ = $(SRC:.c=.o)

# UTILS
RM = rm -f
# MKDIR = mkdir -p

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $@ $?

ft_%.o: ft_%.c
	@$(CC) $(CFLAGS) -o $@ -c $^

clean:
	@$(RM) $(OBJ)
	@echo "Objects removed."

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed."

re: fclean $(NAME)
