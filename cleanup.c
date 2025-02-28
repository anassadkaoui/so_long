/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:04:51 by asadkaou          #+#    #+#             */
/*   Updated: 2025/02/27 17:48:07 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void cleanup_images(t_game *game)
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
    int i;
	
	i = 0;
    while (map[i])
	{
        free(map[i]);
        i++;
    }
    free(map);
}

void free_game(t_game *game)
{
    if (game->player_img)
        mlx_destroy_image(game->mlx, game->player_img);
    if (game->wall_img)
        mlx_destroy_image(game->mlx, game->wall_img);
    if (game->collectible_img)
        mlx_destroy_image(game->mlx, game->collectible_img);
    if (game->exit_img)
        mlx_destroy_image(game->mlx, game->exit_img);
    
    if (game->map)
    {
        int i = 0;
        while (game->map[i])
        {
            free(game->map[i]);
            i++;
        }
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
