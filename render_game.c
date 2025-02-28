/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:36:42 by asadkaou          #+#    #+#             */
/*   Updated: 2025/02/26 10:35:19 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->wall_img, x * game->tile, y * game->tile);
}

void	draw_collectible(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->collectible_img, x * game->tile, y * game->tile);
}

void	draw_exit(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->exit_img, x * game->tile, y * game->tile);
}

void	draw_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player_img, x * game->tile, y * game->tile);
}

void	render_game(t_game *game)
{
	int	y;
	int	x;

	mlx_clear_window(game->mlx, game->win);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '1')
				draw_wall(game, x, y);
			else if (game->map[y][x] == 'C')
				draw_collectible(game, x, y);
			else if (game->map[y][x] == 'E')
				draw_exit(game, x, y);
			else if (game->map[y][x] == 'P')
				draw_player(game, x, y);
			x++;
		}
		y++;
	}
}
