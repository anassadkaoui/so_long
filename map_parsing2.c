/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:28:38 by asadkaou          #+#    #+#             */
/*   Updated: 2025/02/26 14:57:56 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_right(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->height)
	{
		if (game->map[y][game->width - 1] != '1')
			exit_with_error(game, "Error\nInput Problem\n");
		y++;
	}
}

void	check_left(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != '1')
			exit_with_error(game, "Error\nInput Problem\n");
		y++;
	}
}

void	check_top_bottom(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			exit_with_error(game, "Error\nInput Problem\n");
		x++;
	}
}

void	is_map_enclosed(t_game *game)
{
	check_top_bottom(game);
	check_left(game);
	check_right(game);
}

void	check_map_elements_number(t_game *game)
{
	int	counts[3];

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	game->y = -1;
	while (game->map[++game->y])
	{
		game->x = -1;
		while (game->map[game->y][++game->x])
		{
			if (game->map[game->y][game->x] == 'E')
				counts[0]++;
			else if (game->map[game->y][game->x] == 'P')
				counts[1]++;
			else if (game->map[game->y][game->x] == 'C')
				counts[2]++;
		}
	}
	if (counts[0] != 1 || counts[1] != 1 || counts[2] <= 0)
		exit_with_error(game, "Error\nInput Problem\n");
	game->total_collectibles = counts[2];
}
