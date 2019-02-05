SRC = ft_printf.c parser.c ft_format_create.c ft_print_type.c print_utils.c

HEAD = ft_printf.h

NAME = ft_printf

CC = clang

LIB_SRC = libft

.PHONY: all clean fclean re
all: $(NAME)

$(NAME):
	@make -C $(LIB_SRC)
	$(CC) -O3 $(SRC) -L $(LIB_SRC) -lft  -o $(NAME)

#clean: $(CLEAN_SUB_DIR)

clean: 
	@$(MAKE) -C $(LIB_SRC) clean

run:
	$(CC) -O3 $(SRC) -L $(LIB_SRC) -lft -o $(NAME)

debug:
	$(CC) -g -O3 $(SRC) -L $(LIB_SRC) -lft -o $(NAME)

fclean: clean
	@$(MAKE) -C $(LIB_SRC) fclean
	rm -rf $(NAME)

re_debug: debug

re: fclean all



#

#flags = [
#    '-x',
    #'c',
    #'-Ilibft.h',
    #'-Wall',
    #'-Werror',
    #'-Wextra',
    #'-lm',
 #   '-Llibft/',
 #   '-lft',
 #   '-L/usr/lib/X11', 
 #   'minilibx/libmlx_Linux.a',
 #   '-lXext',
#    '-lX11'
#]
#
#
#
