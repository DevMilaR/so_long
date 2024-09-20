/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromano <lromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:17:33 by lromano           #+#    #+#             */
/*   Updated: 2024/09/20 13:12:42 by lromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx, game->image.exit);
	mlx_destroy_image(game->mlx, game->image.coin);
	mlx_destroy_image(game->mlx, game->image.floor);
	mlx_destroy_image(game->mlx, game->image.player);
	ft_free_game(game);
	exit(EXIT_SUCCESS);
}

void	hooks(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 1, destroy_window, game);
	mlx_hook(game->mlx_win, 2, 1, handler_keys, game);
}
