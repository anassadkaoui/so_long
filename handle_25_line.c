/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_25_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:45:55 by asadkaou          #+#    #+#             */
/*   Updated: 2025/03/01 16:04:42 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_exit(t_game *game, int x, int y)
{
	return (game->map[y][x] == 'E');
}

int	is_wall(t_game *game, int x, int y)
{
	return (game->map[y][x] == '1');
}

int	is_collectible(t_game *game, int x, int y)
{
	return (game->map[y][x] == 'C');
}

void	exit_with_error(t_game *game, char *msg)
{
	(void)game;
	ft_printf("%s", msg);
	exit(1);
}
