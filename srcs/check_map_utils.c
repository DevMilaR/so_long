/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromano <lromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:15:55 by lromano           #+#    #+#             */
/*   Updated: 2024/09/20 13:24:51 by lromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_format(char *argv1, t_game *game)
{
	int	i;

	i = ft_strlen(argv1);
	if (ft_strncmp(&argv1[i - 4], ".ber", 4) != 0)
	{
		ft_error("\nError\n Map file must have .ber\n");
	}
	game->map.path = argv1;
}

void	check_elements(t_game *game, int x, int y)
{
	if (game->map.map[y][x] != '1' && game->map.map[y][x] != '0'
		&& game ->map.map[y][x] != '\n')
		ft_error("Error: invalid caracter");
}

void	count_elements(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
				game->map.player++;
			else if (game->map.map[y][x] == 'C')
				game->player.collectable++;
			else if (game->map.map[y][x] == 'E')
				game->map.exit++;
			else
				check_elements(game, x, y);
			x++;
		}
		y++;
	}
	if (game->map.player != 1 || game->map.exit != 1)
		ft_error("Invalid number of player or exit");
	if (game->player.collectable < 1)
		ft_error("Invalid number of collectables");
}

void	check_wall_map(t_game *game)
{
	int	x;
	int	y;

	x = game->map.x;
	y = game->map.y;
	while (x--)
	{
		if (game->map.map[0][x] != '1' ||
			game->map.map[y - 1][x] != '1')
			ft_error("\nError: Map is not closed\n");
	}
	while (y--)
	{
		if (game->map.map[y][0] != '1' ||
			game->map.map[y][game ->map.x - 1] != '1')
			ft_error("\nError: Map is not closed\n");
	}
}

void	check_size(t_game *game)
{
	char	*line;
	char	*temp;
	int		fd;

	fd = open(game->map.path, O_RDONLY);
	if (fd < 0)
		ft_error("\nError: Unable to open the map\n");
	line = get_next_line(fd);
	if (!line)
		ft_error("\nError: Empty Map\n");
	game->map.x = (int)ft_strlen(line) - 1;
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if ((int)ft_strlen(line) != game->map.x)
			ft_error("\nError: Map is irregular on x\n");
		game->map.y++;
		temp = line;
		line = get_next_line(fd);
		free(temp);
	}
	close(fd);
}
