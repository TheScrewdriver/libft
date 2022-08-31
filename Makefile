# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: screw <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 12:20:18 by screw             #+#    #+#              #
#    Updated: 2022/08/30 15:27:57 by screw            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### NAME

LIB_NAME = libft.a

### SRCS

SRCS += ft_putstr.c

### OBJS

PATH_OBJS = objs

OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

### CHECK_FOLDER

CHECK_FOLDER += tests/

### COMPILATION

CC = clang

CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra

### RULES

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	ar rc $(LIB_NAME) $(OBJS)

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER)
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(LIB_NAME)
	$(MAKE) -C $(CHECK_FOLDER)
	$(CHECK_FOLDER)/run_tests.sh $(CHECK_FOLDER)/exe

clean:
	$(RM) -R $(OBJS)

fclean: clean
	$(RM) -R $(LIB_NAME)
	$(MAKE) -C $(CHECK_FOLDER) fclean

re: fclean
	$(MAKE)
