# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 10:49:20 by romannbroque      #+#    #+#              #
#    Updated: 2022/08/31 09:48:37 by screw            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exe

########## SRCS

CHECK_SRCS += check.c

########## OBJS

PATH_OBJS += ../objs

CHECK_OBJS += $(patsubst %.c, $(PATH_OBJS)/%.o, $(CHECK_SRCS))
OBJS += $(CHECK_OBJS)
OBJS += $(PATH_OBJS)/*.o

########## INCLUDES

CHECK_INCLUDES += /usr/include
INCLUDES += ../includes/

LIB += /usr/lib/aarch64-linux-gnu/libcheck.a

vpath %.h $(INCLUDES)

########## COMPILER

CC = clang

CFLAGS += -Wall
CFLAGS += -Werror
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

$(CHECK_OBJS):
	$(CC) $(CFLAGS) -c $(CHECK_SRCS) -o $(CHECK_OBJS) -I $(INCLUDES) -I $(CHECK_INCLUDES)

clean:
	$(RM) -R $(PATH_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re
