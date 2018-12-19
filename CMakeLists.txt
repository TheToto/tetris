cmake_minimum_required(VERSION 3.0)
project(my-bittorrent LANGUAGES C)

add_compile_options(-Wall -Wextra -Werror -std=c99 -pedantic -g)

include_directories( ${CMAKE_SOURCE_DIR}/include )

FILE(GLOB_RECURSE CSources src/*.c)

ADD_EXECUTABLE(tetris ${CSources})

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")

