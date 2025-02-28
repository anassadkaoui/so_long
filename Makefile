NAME := so_long

CC := cc

CFLAGS := -Wall -Wextra -Werror

SRC := so_long.c map_parsing1.c map_parsing2.c \
       ft_strlen.c map_parsing_fill_flood.c ft_strdup.c \
       render_game.c key_handler.c handle_25_line.c \
       get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	   printf/ft_c.c printf/ft_id.c printf/ft_printf.c printf/ft_s.c printf/ft_u.c \
	   printf/ft_Xxp.c cleanup.c initialize_game.c 

LIB_DIR := mlx
LIBRARY := -L$(LIB_DIR) -lmlx -lXext -lX11 -lm -lz
HEADER := so_long.h

all: $(NAME)

$(NAME): $(LIB_DIR)/libmlx.a $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(SRC) $(LIBRARY) -o $(NAME)

$(LIB_DIR)/libmlx.a:
	@$(MAKE) -C $(LIB_DIR)

clean:
	rm -f $(NAME)

fclean: clean
	rm -rf $(LIB_DIR)/*.o $(LIB_DIR)/libmlx.a

re: fclean all
