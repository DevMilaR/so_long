#include "so_long.h"

void	put_floor(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->image.floor, (x * 100), (y * 100));
}

void	put_door(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->image.exit, (x * 100), (y * 100));
}

void	put_wall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->image.wall, (x * 100), (y * 100));
}

void	put_coin(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->image.coin, (x * 100), (y * 100));
}

void	put_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->image.player, (x * 100), (y * 100));
}

