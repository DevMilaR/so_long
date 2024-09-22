/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromano <lromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:15:09 by lromano           #+#    #+#             */
/*   Updated: 2024/09/19 11:15:17 by lromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_floor(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->image.floor, (x * 100), (y * 100));
}

void	put_place_exit(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->image.exit, (x * 100), (y * 100));
}

void	put_wall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->image.wall, (x * 100), (y * 100));
}

void	put_collectable(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->image.collectable, (x * 100), (y * 100));
}

void	put_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->image.player, (x * 100), (y * 100));
}
