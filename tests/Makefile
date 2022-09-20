# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 10:14:45 by rbroque           #+#    #+#              #
#    Updated: 2022/09/21 01:33:51 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exe

########## SRCS

PATH_SRCS += srcs/
PATH_SRCS += srcs/ctype
PATH_SRCS += srcs/list
PATH_SRCS += srcs/memory
PATH_SRCS += srcs/output
PATH_SRCS += srcs/strings

# ctype

CHECK_SRCS += ft_isalnum.test.c
CHECK_SRCS += ft_isalpha.test.c
CHECK_SRCS += ft_isascii.test.c
CHECK_SRCS += ft_isdigit.test.c
CHECK_SRCS += ft_islower.test.c
CHECK_SRCS += ft_isprint.test.c
CHECK_SRCS += ft_isupper.test.c
CHECK_SRCS += ft_tolower.test.c
CHECK_SRCS += ft_toupper.test.c

# list

CHECK_SRCS += ft_lstadd_back_bonus.test.c
CHECK_SRCS += ft_lstadd_front_bonus.test.c
CHECK_SRCS += ft_lstlast_bonus.test.c
CHECK_SRCS += ft_lstnew_bonus.test.c
CHECK_SRCS += ft_lstsize_bonus.test.c

# memory

CHECK_SRCS += ft_bzero.test.c
CHECK_SRCS += ft_calloc.test.c
CHECK_SRCS += ft_memchr.test.c
CHECK_SRCS += ft_memcmp.test.c
CHECK_SRCS += ft_memcpy.test.c
CHECK_SRCS += ft_memmove.test.c
CHECK_SRCS += ft_memset.test.c

# output

CHECK_SRCS += ft_putchar_fd.test.c
CHECK_SRCS += ft_putendl_fd.test.c
CHECK_SRCS += ft_putnbr_fd.test.c
CHECK_SRCS += ft_putstr_fd.test.c

# strings

CHECK_SRCS += ft_atoi.test.c
CHECK_SRCS += ft_itoa.test.c
CHECK_SRCS += ft_split.test.c
CHECK_SRCS += ft_strchr.test.c
CHECK_SRCS += ft_strcpy.test.c
CHECK_SRCS += ft_strdup.test.c
CHECK_SRCS += ft_striteri.test.c
CHECK_SRCS += ft_strjoin.test.c
CHECK_SRCS += ft_strlcat.test.c
CHECK_SRCS += ft_strlcpy.test.c
CHECK_SRCS += ft_strlen.test.c
CHECK_SRCS += ft_strmapi.test.c
CHECK_SRCS += ft_strncmp.test.c
CHECK_SRCS += ft_strndup.test.c
CHECK_SRCS += ft_strnstr.test.c
CHECK_SRCS += ft_strrchr.test.c
CHECK_SRCS += ft_strtrim.test.c
CHECK_SRCS += ft_substr.test.c

# main

CHECK_SRCS += main.c

vpath %.c $(PATH_SRCS)

########## OBJS

PATH_CHECK_OBJS += objs

CHECK_OBJS += $(patsubst %.c, $(PATH_CHECK_OBJS)/%.o, $(CHECK_SRCS))

########## INCLUDES

CHECK_INCLUDES += /usr/include
TEST_INCLUDES += includes/
INCLUDES += ../includes

########## INCLUDES

LIB += /usr/lib/aarch64-linux-gnu/libcheck.a # Must be changed according with the OS
LIB += ../libft.a

vpath %.h $(INCLUDES)
vpath %test.h $(TEST_INCLUDES)

########## COMPILER

CC = clang

CFLAGS += -Wall
CFLAGS += -Wextra

LINKS += -lcheck
LINKS += -lbsd
LINKS += -lsubunit
LINKS += -lm
LINKS += -lpthread

ifeq ($(debug), true)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
endif

########## RULES

all: $(NAME)

bonus: $(NAME)

$(NAME): $(CHECK_OBJS)
	$(CC) $(CFLAGS) $^ -L $(LIB) $(LINKS) -o $@ -I $(INCLUDES) -I $(CHECK_INCLUDES)
	@echo $(NAME) COMPILED !

$(CHECK_OBJS): $(PATH_CHECK_OBJS)/%.o: %.c
	mkdir -p $(PATH_CHECK_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) -I $(CHECK_INCLUDES) -I $(TEST_INCLUDES)

clean:
	$(RM) -R $(PATH_CHECK_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re
