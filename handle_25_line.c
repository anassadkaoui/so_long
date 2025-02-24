/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_25_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:45:55 by asadkaou          #+#    #+#             */
/*   Updated: 2025/02/05 21:51:39 by asadkaou         ###   ########.fr       */
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

void	exit_with_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}
