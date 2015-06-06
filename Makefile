# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jabadie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/21 03:34:53 by jabadie           #+#    #+#              #
#    Updated: 2015/06/06 17:27:46 by jabadie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = raytracer

OBJ_PATH = ./objs/
SRC_PATH = ./srcs/

INCLUDE = -I ./includes
LIBFT = -L ./libft -lft -L ./minilibx_macos/ -framework OPENGL -framework AppKit -lmlx

CFLAGS = -Wall -Werror -Wextra  -g

SRC_NAME = raytracer.c \
		   sphere.c \
		   plan.c \
		   main.c \
		   make_my_cam.c \
		   parser.c \
		   printing.c \
		   vect.c \
		   vect2.c \
		   color.c \
		   cone.c \
		   cylindre.c \
		   create_obj.c \
		   parse_obj.c \
		   parse_material.c \
		   material.c \
		   reflection.c

OBJ = $(addprefix $(OBJ_PATH), $(SRC_NAME:.c=.o))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

RED=\033[0;31m
LBLUE=\033[1;34m
CYAN=\033[0;36m
ORANGE=\033[0;33m
NC=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(CFLAGS) $(INCLUDE) $(LIBFT) -o $(NAME) $(OBJ)
	@echo "${ORANGE}Created successfully: $(NAME)${NC}";

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(CFLAGS) $(INCLUDE) -o $@ -c $^
	@echo "${LBLUE}Created $@ ${NC}";

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Deleting: $(NAME)${NC}"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)Deleting: $(OBJ_PATH)${NC}"

re : fclean all

.PHONY: all clean fclean re

