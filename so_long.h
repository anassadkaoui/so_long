/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:12:46 by asadkaou          #+#    #+#             */
/*   Updated: 2025/02/23 19:14:04 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	int		width;
	int		height;
	int		tile;
	int		w;
	int		h;
	int		player_width;
	int		player_height;
	void	*wall_img;
	void	*player_img;
	void	*collectible_img;
	void	*exit_img;
	int		player_x;
	int		player_y;
	int		total_collectibles;
	int		exit_unlocked;
	int		x;
	int		y;
	int		move_count;
}	t_game;

char	**ber_to_array(t_game *game, const char *file_path);
void	does_the_file_exist(char *argv1);
void	map_parsing(t_game *game, int argc, char *argv1);
void	is_map_rectangular(t_game *game);
void	is_map_enclosed(t_game *game);
void	check_map_elements_number(t_game *game);
void	validate_map(t_game *game, int player_x, int player_y);
char	**copy_map(t_game *game);
void	free_map(char **map);
void	flood_fill(char **map, int x, int y);
void	render_game(t_game *game);
void	move_player(t_game *game, int direction);
int		handle_keys(int key, void *param);
int		close_hook(void *param);
int		ft_strleen(const char *str);
int		key_handler(int key, t_game *game);
void	exit_with_error(char *msg);
int		is_exit(t_game *game, int x, int y);
int		is_wall(t_game *game, int x, int y);

#endif
