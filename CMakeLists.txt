cmake_minimum_required(VERSION 3.13)
project(ft_printf C)
set(CMAKE_CXX_STANDARD 99)

file(GLOB C libft/*.c *.c libft/libft.h)

add_executable(ft_printf.c ${C} libft/ft_ltoa.c ft_print_type.c print_utils.c print_decimal.c print_unsigned_decimal.c print_hex.c print_octal.c print_char.c print_float.c hex_utils.c libft/ft_itoa_base.c)
#add_executable(ft_printf ft_printf.c ft_printf.h parser.c libft/libft.a)