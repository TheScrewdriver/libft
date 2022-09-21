# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 10:15:13 by rbroque           #+#    #+#              #
#    Updated: 2022/09/21 10:32:15 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### NAME

NAME = libft.a

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

SRCS_BONUS += ft_lstadd_back_bonus.c
SRCS_BONUS += ft_lstadd_front_bonus.c
SRCS_BONUS += ft_lstdelone_bonus.c
SRCS_BONUS += ft_lstlast_bonus.c
SRCS_BONUS += ft_lstnew_bonus.c
SRCS_BONUS += ft_lstsize_bonus.c

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

ifeq (bonus, $(findstring bonus, $(MAKECMDGOALS)))
	SRCS += $(SRCS_BONUS)
else ifeq (test, $(findstring test, $(MAKECMDGOALS)))
	SRCS += $(SRCS_BONUS)
endif

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

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

test: $(NAME)
	$(MAKE) -sC $(CHECK_FOLDER) $(IS_BONUS)
	$(CHECK_FOLDER)/run_tests.sh $(CHECK_FOLDER)/exe

clean:
	$(RM) -R $(PATH_OBJS)
	$(MAKE) -sC $(CHECK_FOLDER) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -sC $(CHECK_FOLDER) fclean

re: fclean
	$(MAKE)

.PHONY: all test bonus clean fclean re
.SILENT: test bonus
