# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 10:15:13 by rbroque           #+#    #+#              #
#    Updated: 2022/09/17 00:27:47 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### NAME

LIB_NAME = libft.a

### SRCS

PATH_SRCS += srcs/
PATH_SRCS += srcs/ctype
PATH_SRCS += srcs/list
PATH_SRCS += srcs/memory
PATH_SRCS += srcs/output
PATH_SRCS += srcs/strings

# ctype

SRCS += ft_isalnum.c
SRCS += ft_isalpha.c
SRCS += ft_isascii.c
SRCS += ft_isdigit.c
SRCS += ft_islower.c
SRCS += ft_isprint.c
SRCS += ft_isupper.c
SRCS += ft_tolower.c
SRCS += ft_toupper.c

# list

SRCS += ft_lstnew_bonus.c

# memory

SRCS += ft_bzero.c
SRCS += ft_calloc.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_memcpy.c
SRCS += ft_memmove.c
SRCS += ft_memset.c

# output

SRCS += ft_putchar_fd.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr_fd.c
SRCS += ft_putstr_fd.c

# strings

SRCS += ft_atoi.c
SRCS += ft_itoa.c
SRCS += ft_split.c
SRCS += ft_strchr.c
SRCS += ft_strcpy.c
SRCS += ft_strdup.c
SRCS += ft_striteri.c
SRCS += ft_strjoin.c
SRCS += ft_strlcat.c
SRCS += ft_strlcpy.c
SRCS += ft_strlen.c
SRCS += ft_strmapi.c
SRCS += ft_strncmp.c
SRCS += ft_strndup.c
SRCS += ft_strnstr.c
SRCS += ft_strrchr.c
SRCS += ft_strtrim.c
SRCS += ft_substr.c

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
CFLAGS += -Wextra

ifneq ($(noerr), true)
	CFLAGS += -Werror
endif

ifeq ($(everything), true)
	CFLAGS += -Weverything
endif

### RULES

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	ar rcs $(LIB_NAME) $(OBJS)

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
	$(RM) $(LIB_NAME)
	$(MAKE) -sC $(CHECK_FOLDER) fclean

re: fclean
	$(MAKE)

.PHONY: all test clean fclean re
.SILENT: test
