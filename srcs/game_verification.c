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

void	verification_of_playalibtly(t_game *game)
{
	if (game->player.coin != game->player.flous || game->player.exit == false)
	{
		ft_error("\n map is unplayable \n");
	}
	ft_free_game(game);
}

void	verification_recursivity(t_game *game, int y, int x)
{
	if (game->map.map[y][x] == '1' || game->map.map[y][x] == 'X')
		return ;
	if (game->map.map[y][x] == 'C')
		game->player.flous++;
	if (game->map.map[y][x] == 'E')
		game->player.exit = true;
	game->map.map[y][x] = 'X';
	verification_recursivity(game, y + 1, x);
	verification_recursivity(game, y - 1, x);
	verification_recursivity(game, y, x + 1);
	verification_recursivity(game, y, x - 1);
}

void	verification(t_game *game)
{
	verification_recursivity(game, game->player.y, game->player.x);
}
