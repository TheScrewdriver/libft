# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 10:14:45 by rbroque           #+#    #+#              #
#    Updated: 2022/09/03 00:19:32 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exe

########## SRCS

PATH_SRCS += srcs/

CHECK_SRCS += ft_strlen.test.c
CHECK_SRCS += ft_isalpha.test.c
CHECK_SRCS += main.c

########## OBJS

PATH_OBJS += ../objs
PATH_CHECK_OBJS += objs

CHECK_OBJS += $(patsubst %.c, $(PATH_CHECK_OBJS)/%.o, $(CHECK_SRCS))
OBJS += $(CHECK_OBJS)
OBJS += $(PATH_OBJS)/*.o

########## INCLUDES

CHECK_INCLUDES += /usr/include
TEST_INCLUDES += includes/
INCLUDES += ../includes

LIB += /usr/lib/aarch64-linux-gnu/libcheck.a

vpath %.h $(INCLUDES)
vpath %test.h $(TEST_INCLUDES)

########## COMPILER

CC = clang

CFLAGS += -Wall
CFLAGS += -Wextra

LINKS += -lcheck
LINKS += -lsubunit
LINKS += -lm
LINKS += -lpthread

ifeq ($(debug), true)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
endif

########## RULES

all: $(NAME)

$(NAME): $(CHECK_OBJS) $(OBJS)
	$(CC) $(CFLAGS) $^ -L $(LIB) $(LINKS) -o $@ -I $(INCLUDES) -I $(CHECK_INCLUDES)
	@echo $(NAME) COMPILED !

$(CHECK_OBJS): $(PATH_CHECK_OBJS)/%.o: $(PATH_SRCS)/%.c
	mkdir -p $(PATH_CHECK_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) -I $(CHECK_INCLUDES) -I $(TEST_INCLUDES)

clean:
	$(RM) -R $(PATH_CHECK_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re
