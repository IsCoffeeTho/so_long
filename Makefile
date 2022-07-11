# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 16:56:57 by amenadue          #+#    #+#              #
#    Updated: 2022/07/11 15:07:00 by amenadue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRC	= src/*.c

LIBS	= libft

################################################################################

CC		= gcc

CCFLAGS	= -Wall -Wextra -Werror -Iheaders/

MLX_DIR = mlx

# OS Detect ### macOS and Linux use different flags for MLX #

UNAME_S = $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CCFLAGS += -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	MLX_DIR = mlx_linux
endif
ifeq ($(UNAME_S),Darwin)
	CCFLAGS += -Lmlx -lmlx -framework OpenGL -framework AppKit
	MLX_DIR = mlx_linux
endif

all:
	$(foreach LIB,$(LIBS), make -C $(LIB);)
	$(CC) $(SRC) $(foreach LIB,$(LIBS),$(LIB).a )$(CCFLAGS) -o $(NAME)

mlx:
	make -C $(MLX_DIR)

clean:
	make clean -C $(MLX_DIR)
	$(foreach LIB,$(LIBS), make clean -C $(LIB);)

fclean: clean
	$(foreach LIB,$(LIBS), make fclean -C $(LIB);)
	rm -rf $(NAME)

norm:
	norminette src libft headers

re: fclean all

.PHONY: all clean fclean mlx norm re