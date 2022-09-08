# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 10:15:13 by rbroque           #+#    #+#              #
#    Updated: 2022/09/08 19:00:31 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### NAME

LIB_NAME = libft.a

### SRCS

PATH_SRCS += srcs/
PATH_SRCS += srcs/strings
PATH_SRCS += srcs/ctype

# strings

SRCS += ft_strlen.c
SRCS += ft_memset.c
SRCS += ft_bzero.c
SRCS += ft_memcpy.c

# ctype

SRCS += ft_islower.c
SRCS += ft_isupper.c
SRCS += ft_isalpha.c
SRCS += ft_isdigit.c
SRCS += ft_isalnum.c
SRCS += ft_isascii.c
SRCS += ft_isprint.c

vpath %.c $(PATH_SRCS)

### OBJS

PATH_OBJS = objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

### CHECK_FOLDER

CHECK_FOLDER += tests/

### INCLUDES

INCLUDES += includes/

### COMPILATION

CC = clang

CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra

ifeq ($(everything), true)
	CFLAGS = -Weverything
endif

### RULES

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	ar rc $(LIB_NAME) $(OBJS)

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER)
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

test: $(LIB_NAME)
	$(MAKE) -sC $(CHECK_FOLDER)
	$(CHECK_FOLDER)/run_tests.sh $(CHECK_FOLDER)/exe

clean:
	$(RM) -R $(PATH_OBJS)
	$(MAKE) -sC $(CHECK_FOLDER) clean

fclean: clean
	$(RM) -R $(LIB_NAME)
	$(MAKE) -sC $(CHECK_FOLDER) fclean

re: fclean
	$(MAKE)

.PHONY: all test clean fclean re
.SILENT: test
