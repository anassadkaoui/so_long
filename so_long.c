/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:24:56 by asadkaou          #+#    #+#             */
/*   Updated: 2025/03/01 15:48:30 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_images(t_game *game)
{
	load_image(game, &game->wall_img, "imgs/wall.xpm");
	load_image(game, &game->collectible_img, "imgs/collect.xpm");
	load_image(game, &game->exit_img, "imgs/exit.xpm");
	load_image(game, &game->player_img, "imgs/player.xpm");
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

	if (setup_game(&game, argc, argv))
		return (1);
	render_game(&game);
	mlx_key_hook(game.win, key_handler, &game);
	mlx_hook(game.win, 17, 0, close_hook, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
