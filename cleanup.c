/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:43:03 by asadkaou          #+#    #+#             */
/*   Updated: 2025/02/23 19:12:23 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// void cleanup(t_game *game)
// {
// 	// Free the game map if dynamically allocated
// 	if (game->map)
// 	{
// 		int i = 0;
// 		while (game->map[i])
// 		{
// 			free(game->map[i]);
// 			i++;
// 		}
// 		free(game->map);
// 	}

// 	// Destroy images
// 	if (game->wall_img)
// 		mlx_destroy_image(game->mlx, game->wall_img);
// 	if (game->collectible_img)
// 		mlx_destroy_image(game->mlx, game->collectible_img);
// 	if (game->exit_img)
// 		mlx_destroy_image(game->mlx, game->exit_img);
// 	if (game->player_img)
// 		mlx_destroy_image(game->mlx, game->player_img);

// 	// Destroy window
// 	if (game->win)
// 		mlx_destroy_window(game->mlx, game->win);

// 	// Free the mlx pointer if necessary (optional for most cases)
// 	if (game->mlx)
// 		free(game->mlx);
// }
