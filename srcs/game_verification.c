/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_verification.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromano <lromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:15:27 by lromano           #+#    #+#             */
/*   Updated: 2024/09/20 13:12:03 by lromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_status_check(t_game *game)
{
	if (game->player.collectable != game->player.totalcollected || game->player.exit == false)
	{
		ft_error("\n map is unplayable \n");
	}
	ft_free_game(game);
}

void	map_recursive_check(t_game *game, int y, int x)
{
	if (game->map.map[y][x] == '1' || game->map.map[y][x] == 'X')
		return ;
	if (game->map.map[y][x] == 'C')
		game->player.totalcollected++;
	if (game->map.map[y][x] == 'E')
		game->player.exit = true;
	game->map.map[y][x] = 'X';
	map_recursive_check(game, y + 1, x);
	map_recursive_check(game, y - 1, x);
	map_recursive_check(game, y, x + 1);
	map_recursive_check(game, y, x - 1);
}

void	verificate_check(t_game *game)
{
	map_recursive_check(game, game->player.y, game->player.x);
}
