/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:56:11 by asadkaou          #+#    #+#             */
/*   Updated: 2025/02/27 16:39:30 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void initialize_game(t_game *game)
{
    game->mlx = NULL;
    game->win = NULL;
    game->img = NULL;
    game->map = NULL;
    game->width = 0;
    game->height = 0;
    game->tile = 50;
    game->w = 0;
    game->h = 0;
    game->player_width = 0;
    game->player_height = 0;
    game->wall_img = NULL;
    game->player_img = NULL;
    game->collectible_img = NULL;
    game->exit_img = NULL;
    game->player_x = 0;
    game->player_y = 0;
    game->total_collectibles = 0;
    game->exit_unlocked = 0;
    game->x = 0;
    game->y = 0;
    game->move_count = 0;
	game->screen_height = 0;
	game->screen_width = 0;
}
