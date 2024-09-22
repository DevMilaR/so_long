/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromano <lromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:13:10 by lromano           #+#    #+#             */
/*   Updated: 2024/09/20 13:22:24 by lromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(game->map.path, O_RDONLY);
	if (fd < 0)
		ft_error("Error: Failed to open the map.");
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.y + 1));
	if (!(game->map.map))
		ft_error("\nError: Failed to allocate memory.\n");
	line = get_next_line(fd);
	if (!line)
		ft_error("\nError: line is empty.\n");
	i = 0;
	while (i < game->map.y && line)
	{
		game->map.map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->map.map[i] = NULL;
	close(fd);
}
