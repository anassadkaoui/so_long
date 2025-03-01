/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:04:51 by asadkaou          #+#    #+#             */
/*   Updated: 2025/03/01 16:02:28 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup_images(t_game *game)
{
	if (game->wall_img)
	{
		mlx_destroy_image(game->mlx, game->wall_img);
		game->wall_img = NULL;
	}
	if (game->collectible_img)
	{
		mlx_destroy_image(game->mlx, game->collectible_img);
		game->collectible_img = NULL;
	}
	if (game->exit_img)
	{
		mlx_destroy_image(game->mlx, game->exit_img);
		game->exit_img = NULL;
	}
	if (game->player_img)
	{
		mlx_destroy_image(game->mlx, game->player_img);
		game->player_img = NULL;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_game(t_game *game)
{
	void	*images[4];
	int		i;
	int		num_images;

	images[0] = game->player_img;
	images[1] = game->wall_img;
	images[2] = game->collectible_img;
	images[3] = game->exit_img;
	num_images = 4;
	free_images(game, images, num_images);
	if (game->map)
	{
		i = 0;
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
