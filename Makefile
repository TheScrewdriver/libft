# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 10:15:13 by rbroque           #+#    #+#              #
#    Updated: 2022/08/31 10:17:53 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### NAME

LIB_NAME = libft.a

### SRCS

PATH_SRCS += srcs/

SRCS += ft_strlen.c

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

### RULES

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	ar rc $(LIB_NAME) $(OBJS)

$(OBJS): $(PATH_OBJS)/%.o: $(PATH_SRCS)/%.c $(HEADER)
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

test: $(LIB_NAME)
	$(MAKE) -sC $(CHECK_FOLDER)
	@echo "<--------- TEST ---------->\n\n"
	$(CHECK_FOLDER)/run_tests.sh $(CHECK_FOLDER)/exe

clean:
	$(RM) -R $(PATH_OBJS)

fclean: clean
	$(RM) -R $(LIB_NAME)
	$(MAKE) -C $(CHECK_FOLDER) fclean

re: fclean
	$(MAKE)

.PHONY: all test clean fclean re
.SILENT: test
