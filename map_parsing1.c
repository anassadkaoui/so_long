/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:38:52 by asadkaou          #+#    #+#             */
/*   Updated: 2025/02/28 12:17:10 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ber_to_array(t_game *game, const char *file_path)
{
	int		fd;
	char	**lines;
	char	*line;
	int		i;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		exit_with_error(game, "Error\nA system call error\n");
	lines = malloc(sizeof(char *) * 1024);
	if (!lines)
	{
		close(fd);
		return (NULL);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines[i++] = line;
		line = get_next_line(fd);
	}
	lines[i] = NULL;
	game->width = ft_strlen(lines[0]) - 1;
	game->height = i;
	close(fd);
	return (lines);
}

void	does_the_file_exist(t_game *game, char *argv1)
{
	int	fd;

	fd = open(argv1, O_RDONLY);
	if (fd == -1)
	{
		exit_with_error(game, "Error\nA system call error.\n(mostly the file is not exist)\n");
	}
	close(fd);
}

void	is_file_empty(t_game *game, char *file_path)
{
	int		fd;
	char	buffer[1];
	int		bytes_read;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		exit_with_error(game, "A system call error.\n");
	bytes_read = read(fd, buffer, 1);
	if (bytes_read == -1)
	{
		ft_printf("A system call error.\n");
		close(fd);
		// exit(1);
	}
	close(fd);
	if (bytes_read == 0)
		exit_with_error(game, "Error\nInput Problem\n");
}

void	is_map_rectangular(t_game *game)
{
	int		i;
	int		j;
	size_t	last_row_width;
	size_t	row_width;

	if (!game->map || !game->map[0])
		exit_with_error(game, "Error\nInput Problem\n");
	last_row_width = ft_strlen(game->map[game->height - 1]) + 1;
	i = 0;
	j = 0;
	while (j < (game->height - 1))
	{
		row_width = ft_strlen(game->map[i]);
		if (row_width != last_row_width)
			exit_with_error(game, "Error\nInput Problem\n");
		i++;
		j++;
	}
}

void	map_parsing(t_game *game, int argc, char *argv1)
{
	if (argc != 2)
	{
		exit_with_error(game, "Error\nInput Problem\n");
	}
	check_dot_ber(game, argv1);
	does_the_file_exist(game, argv1);
	is_file_empty(game, argv1);
	game->map = ber_to_array(game, argv1);
	is_map_rectangular(game);
	is_map_enclosed(game);
	check_map_elements_number(game);
	validate_map(game, 1, 1);
}
