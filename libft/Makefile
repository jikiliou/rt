# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/07 15:26:23 by jabadie           #+#    #+#              #
#    Updated: 2015/06/04 07:00:41 by jabadie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ_PATH = ./objs/
SRC_PATH = ./srcs/

INCLUDE = -I ./includes/

CFLAGS = -Wall -Werror -Wextra -g

SRC_NAME = ft_atoi.c \
	   ft_bzero.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_itoa.c \
	   ft_memalloc.c \
	   ft_memccpy.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memdel.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_putchar.c \
	   ft_putchar_fd.c \
	   ft_putendl.c \
	   ft_putendl_fd.c \
	   ft_putnbr.c \
	   ft_putnbr_fd.c \
	   ft_putstr.c \
	   ft_putstr_fd.c \
	   ft_strcat.c \
	   ft_strchr.c \
	   ft_strclr.c \
	   ft_strcmp.c \
	   ft_strcpy.c \
	   ft_strdel.c \
	   ft_strdup.c \
	   ft_strequ.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strjoin.c \
	   ft_strlcat.c \
	   ft_strlen.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strncat.c \
	   ft_strncmp.c \
	   ft_strncpy.c \
	   ft_strnequ.c \
	   ft_strnew.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_strsplit.c \
	   ft_strstr.c \
	   ft_strsub.c \
	   ft_strtrim.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_lstdel.c \
	   ft_lstnew.c \
	   ft_lstdelone.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_btreeapply.c \
	   ft_btreeinsert.c \
	   ft_btreenew.c \
	   ft_btreesearch.c \
	   ft_tabint_sort.c \
	   ft_pow.c \
	   ft_sqrt.c \
	   ft_strmore.c \
	   ft_unsigned_itoa.c \
	   ft_putwchar.c \
	   ft_putwstr.c \
	   ft_wstrlen.c \
	   ft_wstrnew.c \
	   ft_dec_to_bin.c \
	   ft_bin_to_dec.c \
	   ft_wchlen.c \
	   ft_strsplit_nbr.c \
	   ft_new_chlst.c \
	   ft_lstdelall.c \
	   ft_lstlen.c \
	   ft_ptrlen.c \
	   ft_ptrstrnew.c \
	   ft_error.c \
	   ft_chlstnew.c \
	   ft_ch_to_chlst.c \
	   ft_strsplit_lst.c \
	   ft_chch_to_ch.c \
	   ft_chlst_to_ch.c \
	   destroy_last.c \
	   add_last.c \
	   ft_chlst_to_chch.c \
	   ft_tabtospace.c \
	   free_chch.c \
	   float_to_int.c \
	   ft_nblen.c \
	   ft_strsplit_ctab.c \
	   ft_strndup.c \
	   ft_putfloat.c \
	   get_next_line.c \
	   ft_isupper.c \
	   replace_comment.c

OBJ = $(addprefix $(OBJ_PATH), $(SRC_NAME:.c=.o))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

RED=\033[0;31m
LBLUE=\033[1;34m
CYAN=\033[0;36m
ORANGE=\033[0;33m
NC=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	@echo "${ORANGE}Created successfully: $(NAME)${NC}";

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(CFLAGS) $(INCLUDE) -o $@ -c $^
	@echo "${CYAN}Created $@ ${NC}";

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Deleting: $(NAME)${NC}"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)Deleting: $(OBJ_PATH)${NC}"

re : fclean all

.PHONY: all clean fclean re
