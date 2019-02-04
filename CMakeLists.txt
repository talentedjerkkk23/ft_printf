cmake_minimum_required(VERSION 3.13)
project(ft_printf C)
set(CMAKE_CXX_STANDARD 99)

file(GLOB C libft/*.c *.c libft/libft.h)

add_executable(ft_printf.c ${C} libft/ft_ltoa.c ft_print_type.c print_utils.c)
#add_executable(ft_printf ft_printf.c ft_printf.h parser.c libft/libft.a)