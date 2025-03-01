/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:28:17 by asadkaou          #+#    #+#             */
/*   Updated: 2025/03/01 16:43:02 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(t_game *game, void **img, char *path)
{
    int img_width;
    int img_height;

    *img = mlx_xpm_file_to_image(game->mlx, path, &img_width, &img_height);
    if (!(*img))
    {
        free_game(game);
        exit_with_error(game, "Error\n.xpm file error\n");
    }
}

int	setup_game(t_game *game, int argc, char *argv[])
{
	initialize_game(game);
	map_parsing(game, argc, argv[1]);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	find_player_position(game);
	game->tile = 50;
	game->h = game->height * game->tile;
	game->w = game->width * game->tile;
	mlx_get_screen_size(game->mlx, &game->screen_width, &game->screen_height);
	if (game->w > game->screen_width || game->h > game->screen_height)
	{
		free_game(game);
		return (0);
	}
	initialize_images(game);
	game->win = mlx_new_window(game->mlx, game->w, game->h, "so_long");
	if (!game->win)
		return (1);
	return (0);
}

void	free_images(t_game *game, void *images[], int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (images[i])
			mlx_destroy_image(game->mlx, images[i]);
		i++;
	}
}

int is_adjacent_blocked(t_game *game, int y, int x)
{
    int up;
    int down;
    int left;
    int right;

    up = (game->map[y - 1][x] == '1' || game->map[y - 1][x] == 'E');
    down = (game->map[y + 1][x] == '1' || game->map[y + 1][x] == 'E');
    left = (game->map[y][x - 1] == '1' || game->map[y][x - 1] == 'E');
    right = (game->map[y][x + 1] == '1' || game->map[y][x + 1] == 'E');
    
    return (up && down && left && right);
}