# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pstein <pstein@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/12 15:20:52 by jterrazz          #+#    #+#              #
#    Updated: 2019/12/25 12:20:55 by pstein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = ./srcs

SRC_NAME =	ft_printf.c checker.c display.c \
			flags.c take_str2.c colors.c\
			ft_itoa_base.c libf_f.c \
			libft_modf.c libft_modf2.c \
			maxnbr.c num_str.c num_str2.c \
			long_doudle.c take_str.c \
			ld_1.c ld_2.c ld_3.c ld_4.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OFILES = $(SRC_NAME:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)
	@echo "Compilation:\033[92m OK\033[0m"

%.o: $(SRC_PATH)/%.c
	$(CC) -c $(CFLAGS) -o $@ $< -I includes

clean:
	@rm -rf $(OFILES)
	@echo "Deleting:\n\033[33m $(OFILES)\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "Deleting:\n\033[33m $(NAME)\033[0m"

re : fclean all

.PHONY: all clean fclean re