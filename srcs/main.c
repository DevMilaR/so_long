/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromano <lromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:17:01 by lromano           #+#    #+#             */
/*   Updated: 2024/09/20 13:00:11 by lromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	validate_arg(argc);
	ft_bzero(&game, sizeof(t_game));
	check_format(argv[1], &game);
	check_size(&game);
	read_map(&game);
	check_wall_map(&game);
	count_elements(&game);
	player_initial_position(&game);
	verification(&game);
	verification_of_playalibtly(&game);
	read_map(&game);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.map.x * 100,
			game.map.y * 100, "So_long");
	hooks(&game);
	charg_img(&game);
	mlx_loop(game.mlx);
	return (0);
}
