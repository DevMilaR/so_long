#include "so_long.c"

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx, game->image.exit);
	mlx_destroy_image(game->mlx, game->image.coin);
	mlx_destroy_image(game->mlx, game->image.floor);
	mlx_destroy_image(game->mlx, game->image.player);
	ft_free(game);
	exit(EXIT_SUCCESS);
}

void	hooks(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 1, destroy_window, game);
	mlx_hook(game->mlx_win, 2, 1, handler_keys, game);
}
