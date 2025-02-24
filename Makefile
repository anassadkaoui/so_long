NAME := so_long

CC := cc

CFLAGS := -Wall -Wextra -Werror -g

SOURCE := so_long.c map_parsing1.c map_parsing2.c ft_strlen.c map_parsing_fill_flood.c ft_strdup.c render_game.c key_handler.c handle_25_line.c
GETNEXTLINE := get_next_line/*.c
PRINTF := printf/*.c

# Correct MiniLibX flags for macOS
LIBRARY := -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(PRINTF) $(LIBRARY) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -rf minilibx/*.o minilibx/libmlx.a

re: fclean all
