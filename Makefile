# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/09 13:01:16 by frcugy            #+#    #+#              #
#    Updated: 2015/01/02 11:32:06 by frcugy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC =	count_files.c		fetch_files.c	fetch_option.c		first_check.c
SRC +=	free_tab.c			hub_dir.c		print_dir.c
SRC +=	get_name_size.c		get_nb_size.c	get_spaces_size.c	get_stat.c
SRC +=	init_int.c			init_struct.c	len_tab.c			main.c
SRC +=	print_dir_l.c		print_files.c	print_files_l.c		realloc_tab.c
SRC +=	recursive.c			sort_ascii.c	sort_time.c			sort_tab.c
SRC +=	tab_split.c			write_atx.c		write_l.c			write_link.c
SRC +=	write_nb.c			write_right.c	write_str.c			write_time.c
SRC +=	write_min_maj.c		write_types.c	sort_dir_files.c	get_hide.c
SRC += 	write_nb_gid.c

OBJ = $(patsubst %.c, %.o, $(SRC))

CFLAGS = -Wall -Wextra -Werror

.PHONY : all, $(NAME), clean, fclean, proper
.SILENT :

all: $(NAME)

$(NAME): $(OBJ)
	echo "\033[31; 1mCreation des objets terminee\033[0m"
	make -C libft
	echo "\033[32; 1mCreation de la lib terminee\033[0m"
	gcc $(CFLAGS) $(OBJ) -L libft -lft -o $(NAME)
	echo "\033[33; 1mCompilation terminee\033[0m"

proper: $(NAME) clean

clean:
	rm -f $(OBJ)
	make clean -C libft/
	echo "\033[34; 1mSupression des objets terminee\033[0m"

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a
	echo "\033[36; 1mSupression des exe terminee\033[0m"

re: fclean all

%.o: %.c
	gcc -c $(CFLAGS) $< -o $@

