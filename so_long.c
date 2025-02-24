/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:24:56 by asadkaou          #+#    #+#             */
/*   Updated: 2025/02/23 19:47:27 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	initialize_images(t_game *game)
{
	int	img_width;
	int	img_height;

	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"imgs/wall.xpm", &img_width, &img_height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"imgs/collect.xpm", &img_width, &img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"imgs/exit.xpm", &img_width, &img_height);
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"imgs/player.xpm", &img_width, &img_height);
}

int	close_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	exit(0);
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

// void leaks() {
// 	system("leaks so_long");
// 	system("lsof -c so_long");
// }

int	main(int argc, char *argv[])
{
	// atexit(leaks);
	t_game	game;

	game.move_count = 0;
	game.player_x = 0;
	map_parsing(&game, argc, argv[1]);
	game.mlx = mlx_init();
	find_player_position(&game);
	game.tile = 50;
	game.h = game.height * game.tile;
	game.w = game.width * game.tile;
	game.win = mlx_new_window(game.mlx, game.w, game.h, "so_long");
	initialize_images(&game);
	render_game(&game);
	mlx_key_hook(game.win, key_handler, &game);
	mlx_hook(game.win, 17, 0, close_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
