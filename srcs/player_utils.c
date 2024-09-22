/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromano <lromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:14:54 by lromano           #+#    #+#             */
/*   Updated: 2024/09/20 13:26:06 by lromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_player(t_game *game)
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
			{
				game->player.y = y;
				game->player.x = x;
				game->map.map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

void	update_player_pos(t_game *game, int my, int mx)
{
	if (game->map.map[game->player.y][game->player.x] != 'D')
		game->map.map[game->player.y][game->player.x] = '0';
	else
		game->map.map[game->player.y][game->player.x] = 'E';
	game->map.map[game->player.y + my][game->player.x + mx] = 'P';
	game->player.y += my;
	game->player.x += mx;
	draw_img(game);
	ft_printf("moves ---> %d\n", game->player.moves++);
}

void	check_collects(t_game *game, int my, int mx)
{
	game->player.collectable--;
	if (game->map.map[game->player.y][game->player.x] != 'D')
		game->map.map[game->player.y][game->player.x] = '0';
	else
		game->map.map[game->player.y][game->player.x] = 'E';
	game->map.map[game->player.y + my][game->player.x + mx] = 'P';
	game->player.y += my;
	game->player.x += mx;
	draw_img(game);
	ft_printf("moves ---> %d\n", game->player.moves++);
}

void	move(t_game *game, int my, int mx)
{
	int	py;
	int	px;

	py = game->player.y;
	px = game->player.x;
	if (game->map.map[py + my][px + mx] == '1')
		return ;
	if (game->map.map[py + my][px + mx] == '0')
		return (update_player_pos(game, my, mx));
	if (game->map.map[py + my][px + mx] == 'E' && game->player.collectable == 0)
		return ((void)(destroy_window(game)));
	if (game->map.map[py + my][px + mx] == 'C')
		return (check_collects(game, my, mx));
	else
		game->map.map[py][px] = '0';
	if (game->map.map[py + my][px + mx] == 'E')
	{
		game->map.map[game->player.y + my][game->player.x + mx] = 'D';
		game->player.y += my;
		game->player.x += mx;
	}
	draw_img(game);
	ft_printf("moves ---> %d\n", game->player.moves++);
}

int	handler_keys(int keycode, t_game *game)
{
	if (game->player.moves == 0)
		game->player.moves++;
	if (keycode == Q || keycode == ESC)
		destroy_window(game);
	else if (keycode == W || keycode == KEY_UP)
		move(game, -1, 0);
	else if (keycode == S || keycode == KEY_DOWN)
		move(game, 1, 0);
	else if (keycode == A || keycode == KEY_LEFT)
		move(game, 0, -1);
	else if (keycode == D || keycode == KEY_RIGHT)
		move(game, 0, 1);
	return (0);
}
