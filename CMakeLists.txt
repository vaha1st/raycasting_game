CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

SET(CMAKE_C_STANDARD 11)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY /Users/ruslan/Documents/cub3d)
SET(CMAKE_C_FLAGS "-lz")

PROJECT(cub3D)

ADD_EXECUTABLE(cub3D
        srcs/cub3d.c srcs/gnl/get_next_line.c srcs/utils/parser_utils.c srcs/parser.c srcs/layers/minimap.c
        srcs/utils/screen_utils.c srcs/utils/player_utils.c srcs/utils/parser_map_checker.c srcs/utils/ray_utils.c
        srcs/layers/first_view.c srcs/layers/floor_ceiling.c srcs/events.c srcs/utils/init_structures.c
        srcs/utils/texture_utils.c srcs/save.c srcs/utils/shutdown.c srcs/sprite.c srcs/utils/events_utils.c)
target_link_libraries(cub3D
        "/Users/ruslan/Documents/cub3d/srcs/libft/libft.a"
        "/Users/ruslan/Documents/cub3d/srcs/minilibx/libmlx.a"
        "-framework OpenGL"
        "-framework Appkit")
