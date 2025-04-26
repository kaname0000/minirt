# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okaname <okaname@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 21:37:38 by okaname           #+#    #+#              #
#    Updated: 2025/02/28 13:22:34 by okaname          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
# CFLAGS = -O2 -I./includes 
CFLAGS = -Wall -Wextra -Werror -I./includes 
LDFLAGS = -lm

MANDATORY = minirt

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

PRINTFDIR = ./ft_printf
PRINTF = $(PRINTFDIR)/libftprintf.a

MLXDIR = ./mlx
MLX = $(MLXDIR)/libmlx.a
LMLX = -L$(MLXDIR) -lmlx -lXext -lX11

SRCS = main.c\
		hit_point.c\
		diffuse_reflection.c\
		specular_reflection.c\
		ambient_light.c\
		is_zerovec.c\
		print_vec.c\
		color/color_add.c\
		color/color_const_mult.c\
		color/color_init.c\
		color/color_mult.c\
		color/color_normalize.c\
		color/diffuse_color.c\
		vector/vec_add.c\
		vector/vec_cross.c\
		vector/vec_dot.c\
		vector/vec_init.c\
		vector/vec_mag.c\
		vector/vec_mult.c\
		vector/vec_normalize.c\
		vector/vec_sub.c\

OBJS = $(SRCS:.c=.o)

all: $(MANDATORY)

$(MANDATORY): $(LIBFT) $(PRINTF) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(LMLX) $(LDFLAGS) -o $@

$(LIBFT):
	make -C $(LIBFTDIR)

$(PRINTF):
	make -C $(PRINTFDIR)

$(MLX):
	make -C $(MLXDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run:all
	./$(MANDATORY)

clean:
	rm -f $(OBJS) 
	make -C $(LIBFTDIR) clean
	make -C $(PRINTFDIR) clean
	make -C $(MLXDIR) clean

fclean: clean
	rm -f $(MANDATORY) 
	make -C $(LIBFTDIR) fclean
	make -C $(PRINTFDIR) fclean
	make -C $(MLXDIR) clean

re: fclean all

.PHONY: all clean fclean re