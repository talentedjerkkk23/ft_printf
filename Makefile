SRC = ft_printf.c parser.c ft_format_create.c ft_print_type.c print_utils.c \
	  print_char.c print_unsigned_decimal.c print_hex.c print_decimal.c print_octal.c \
	  print_string.c print_ptr.c print_float.c float_utils.c libft/ft_atoi.c libft/ft_ltoa.c libft/ft_ltoa_base.c libft/ft_strchr.c libft/ft_isdigit.c libft/ft_itoa_base.c libft/ft_bzero.c libft/ft_strdup.c libft/ft_itoa.c libft/ft_strlen.c

HEAD = ft_printf.h libft/libft.h

NAME = ft_printf

LIB_NAME = libftprintf.a

CC = clang

FLAGS = -Wall -Wextra -Werror

LIB_SRC = libft

OBJECTS = $(SRC:.c=.o)

.PHONY: all clean fclean re
all: $(LIB_NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $<

$(LIB_NAME): $(OBJECTS)
	#@make -C $(LIB_SRC)
	$(CC) -O3 $(FLAGS) -c $(SRC) -I$(HEAD)
	ar rc $(LIB_NAME) $(OBJECTS) 
	

#clean: $(CLEAN_SUB_DIR)

clean: 
	@$(MAKE) -C $(LIB_SRC) clean

run:
	$(CC) -O3 $(SRC) main.c libftprintf.a -o $(NAME)

debug:
	$(CC) -g -O3 $(SRC) -L $(LIB_SRC) -lft -o $(NAME)

fclean: clean
	@$(MAKE) -C $(LIB_SRC) fclean
	rm -rf $(NAME)

re_debug: debug

re: fclean all

