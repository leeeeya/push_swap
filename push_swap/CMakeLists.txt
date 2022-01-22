cmake_minimum_required(VERSION 3.20)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap
        commands.c
        push_swap.c
        errors.c
        check_arguments.c
        lib/libft.h)

target_link_libraries(push_swap /Users/cstefany/Desktop/push_swap/lib/libft.a)