/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromano <lromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:16:38 by lromano           #+#    #+#             */
/*   Updated: 2024/09/20 15:14:54 by lromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	charge_xpm(t_game *game)
{
	int	x;
	int	y;

	game->image.coin = mlx_xpm_file_to_image(game->mlx, COIN, &(x), &(y));
	game->image.player = mlx_xpm_file_to_image(game->mlx, PLAYER, &(x), &(y));
	game->image.wall = mlx_xpm_file_to_image(game->mlx, WALL, &(x), &(y));
	game->image.exit = mlx_xpm_file_to_image(game->mlx, DOOR, &(x), &(y));
	game->image.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &(x), &(y));
}

void	put_img(t_game *game, int x, int y)
{
	char	now;

	now = game->map.map[y][x];
	if (now == '1')
		put_wall(game, x, y);
	else if (now == '0')
		put_floor(game, x, y);
	else if (now == 'P')
		put_player(game, x, y);
	else if (now == 'E')
		put_door(game, x, y);
	else if (now == 'C')
		put_coin(game, x, y);
	else if (now == 'D')
		put_player(game, x, y);
}

void	charg_img(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	charge_xpm(game);
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			put_img(game, x, y);
			x++;
		}
		y++;
	}
}
