/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_fill_flood.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:40:44 by asadkaou          #+#    #+#             */
/*   Updated: 2025/02/27 17:59:16 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

char	**copy_map(t_game *game)
{
	int		rows;
	int		i;
	char	**new_map;

	rows = 0;
	while (game->map[rows])
		rows++;
	new_map = malloc((rows + 1) * sizeof(char *));
	if (!new_map)
		return (NULL);
	i = -1;
	while (++i < rows)
	{
		new_map[i] = ft_strdup(game->map[i]);
		if (!new_map[i])
		{
			while (--i >= 0)
				free(new_map[i]);
			free(new_map);
			return (NULL);
		}
	}
	new_map[rows] = NULL;
	return (new_map);
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	validate_map(t_game *game, int player_x, int player_y)
{
	int		x;
	int		y;
	char	**map_copy;

	map_copy = copy_map(game);
	flood_fill(map_copy, player_x, player_y);
	y = -1;
	while (map_copy[++y])
	{
		x = -1;
		while (map_copy[y][++x])
		{
			if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
				exit_with_error(game, "Error\nInput Problem\n");
		}
	}
	free_map(map_copy);
}
void	check_dot_ber(t_game *game, const char *filename)
{
	int	i;

	i = 0;
	while (filename[i] != '\0')
		i++;
	if (i < 4)
		exit_with_error(game, "Error\nInput Problem\n");
	if (filename[i - 4] != '.' || 
		filename[i - 3] != 'b' || 
		filename[i - 2] != 'e' || 
		filename[i - 1] != 'r')
		exit_with_error(game, "Error\nInput Problem\n");
}

