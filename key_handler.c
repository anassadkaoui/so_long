/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:32:46 by asadkaou          #+#    #+#             */
/*   Updated: 2025/03/01 16:11:50 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	iss_wall(t_game *game, int x, int y)
{
	return (game->map[y][x] == '1');
}

int	iss_collectible(t_game *game, int x, int y)
{
	return (game->map[y][x] == 'C');
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	if (iss_wall(game, new_x, new_y))
		return ;
	if (new_x < 0 || new_y < 0
		|| new_x >= game->width || new_y >= game->height)
		return ;
	if (iss_collectible(game, new_x, new_y))
	{
		game->total_collectibles--;
		game->map[new_y][new_x] = '0';
	}
	if (is_exit(game, new_x, new_y) && game->total_collectibles == 0)
	{
		ft_printf("Moves: %d\n", ++game->move_count);
		free_game(game);
		exit (1);
	}
	if (is_exit(game, new_x, new_y) && game->total_collectibles != 0)
		return ;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	game->move_count++;
	ft_printf("Moves: %d\n", game->move_count);
	render_game(game);
}

int	key_handler(int key, t_game *game)
{
	if (key == 65307)
	{
		free_game(game);
		exit(1);
	}
	else if (key == 65361)
		update_player_position(game, game->player_x - 1, game->player_y);
	else if (key == 65362)
		update_player_position(game, game->player_x, game->player_y - 1);
	else if (key == 65363)
		update_player_position(game, game->player_x + 1, game->player_y);
	else if (key == 65364)
		update_player_position(game, game->player_x, game->player_y + 1);
	return (0);
}
