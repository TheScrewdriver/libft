# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 10:14:45 by rbroque           #+#    #+#              #
#    Updated: 2022/09/12 11:07:41 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exe

########## SRCS

PATH_SRCS += srcs/
PATH_SRCS += srcs/ctype
PATH_SRCS += srcs/strings

# ctype

CHECK_SRCS += ft_islower.test.c
CHECK_SRCS += ft_isupper.test.c
CHECK_SRCS += ft_isalpha.test.c
CHECK_SRCS += ft_isdigit.test.c
CHECK_SRCS += ft_isalnum.test.c
CHECK_SRCS += ft_isascii.test.c
CHECK_SRCS += ft_isprint.test.c
CHECK_SRCS += ft_toupper.test.c
CHECK_SRCS += ft_tolower.test.c

# strings

CHECK_SRCS += ft_strlen.test.c
CHECK_SRCS += ft_memset.test.c
CHECK_SRCS += ft_bzero.test.c
CHECK_SRCS += ft_memcpy.test.c
CHECK_SRCS += ft_memmove.test.c
CHECK_SRCS += ft_strlcpy.test.c
CHECK_SRCS += ft_strlcat.test.c
CHECK_SRCS += ft_strchr.test.c
CHECK_SRCS += ft_strrchr.test.c
CHECK_SRCS += ft_strncmp.test.c
CHECK_SRCS += ft_memchr.test.c

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

LIB += /usr/lib/aarch64-linux-gnu/libcheck.a
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
