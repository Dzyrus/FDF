cmake_minimum_required(VERSION 3.15)
project(FDF C)

set(CMAKE_C_STANDARD 99)

add_executable(FDF main.c fdf.h ./libft/libft.h ./minilibx_macos/mlx.h read_file.c draw.c menu.c options.c)
target_link_libraries(FDF
        LINK_PUBLIC ${CMAKE_SOURCE_DIR}/libft/libft.a
        LINK_PUBLIC ${CMAKE_SOURCE_DIR}/minilibx_macos/libmlx.a "-framework OpenGL" "-framework AppKit")

