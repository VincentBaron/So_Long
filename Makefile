# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 17:36:15 by vbaron            #+#    #+#              #
#    Updated: 2021/07/29 17:02:18 by vbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_S = srcs
DIR_O = objs

SOURCES = general_functions_1.c \
		map_parsing.c \
		program_main.c \
		starting_info.c \
		virtual_function.c \
		get_next_line.c \
		get_next_line_utils.c \
		map_functions.c \
		textures.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))
HEADERS = headers
LIBFT_DIR = Libft

######################################################
##DIR_MacOS
##MLX_DIR = mlx-macos
######################################################
##DIR_Linux
MLX_DIR = mlx-linux
#######################################################

NAME = so_long

########################################################
##MacOs
##CC = gcc
########################################################
##Linux
CC = clang
########################################################

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

########################################################
##MacOS
#-I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext 
##LIBS = -framework OpenGL -framework Appkit
########################################################
##Linux
LIBS = -lXext -lX11 -lm
########################################################

MLX = $(addprefix $(MLX_DIR)/,libmlx.a)

LIBFT = $(addprefix $(LIBFT_DIR)/,libft.a)

all: $(LIBFT) $(MLX) $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	mkdir -p $(DIR_O)	
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT) $(MLX)
		$(CC) $(CFLAGS) $(LIBS) $^ -o $@

$(LIBFT):
		 make -C $(LIBFT_DIR)

$(MLX):
		 make -C $(MLX_DIR)

clean:
		rm -f $(OBJS)		
	rm -f $(OBJS)/*.o
	rm -rf $(DIR_O)	
	make clean -C $(LIBFT_DIR)	
	make clean -C $(MLX_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: re fclean all clean