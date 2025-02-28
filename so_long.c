/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:24:56 by asadkaou          #+#    #+#             */
/*   Updated: 2025/02/28 11:08:11 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void initialize_images(t_game *game)
{
    int img_width;
    int img_height;

    game->wall_img = mlx_xpm_file_to_image(game->mlx, "imgs/wall.xpm", &img_width, &img_height);
    if (!game->wall_img)
	{
		free_game(game);
        return;
	}

    game->collectible_img = mlx_xpm_file_to_image(game->mlx, "imgs/collect.xpm", &img_width, &img_height);
    if (!game->collectible_img)
    {
        free_game(game);
        return;
    }

    game->exit_img = mlx_xpm_file_to_image(game->mlx, "imgs/exit.xpm", &img_width, &img_height);
    if (!game->exit_img)
    {
        free_game(game);
        return;
    }

    game->player_img = mlx_xpm_file_to_image(game->mlx, "imgs/player.xpm", &img_width, &img_height);
    if (!game->player_img)
    {
        free_game(game);
        return;
    }
}

int	close_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_game(game);
	exit(EXIT_SUCCESS);
}

void	find_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				break ;
			x++;
		}
		if (game->map[y][x] == 'P')
			break ;
		y++;
	}
	game->player_y = y;
	game->player_x = x;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	initialize_game(&game);
	map_parsing(&game, argc, argv[1]);
	
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (1);
	
	find_player_position(&game);
	game.tile = 50;
	game.h = game.height * game.tile;
	game.w = game.width * game.tile;
    mlx_get_screen_size(game.mlx, &game.screen_width, &game.screen_height);
	if (game.w > game.screen_width || game.h > game.screen_height)
    {
		free_game(&game);
        return (0);
    }
	game.win = mlx_new_window(game.mlx, game.w, game.h, "so_long");
	if (game.win == NULL)
		return (1);

	initialize_images(&game);
	render_game(&game);
	mlx_key_hook(game.win, key_handler, &game);
	mlx_hook(game.win, 17, 0, close_hook, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (1);
}
