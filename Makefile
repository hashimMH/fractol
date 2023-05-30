# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 16:16:14 by hmohamed          #+#    #+#              #
#    Updated: 2023/02/05 18:51:18 by hmohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol
SRC = fractol.c mandelbrot.c julia.c parc.c keyhook.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx -fsanitize=address -g
LIBS  = ./libmlx.dylib  ./libft/libft.a 
all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	cp mlx/libmlx.dylib  libmlx.dylib 
	$(CC) $(CFLAGS)  $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit $(LIBS)  -o $(NAME) 
# $(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBS)  -framework OpenGL -framework AppKit
	

clean:
		rm -f *.o
		make clean -C \libft

fclean: clean
		rm -f fractol
		make fclean -C \libft
re: fclean all