/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromano <lromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:10:41 by lromano           #+#    #+#             */
/*   Updated: 2024/09/20 13:15:25 by lromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>
# include "mlx/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"
# define WALL "xpm/wall.xpm"
# define PLAYER "xpm/player.xpm"
# define FLOOR "xpm/floor.xpm"
# define EARTH "xpm/exit.xpm"
# define COLLECTABLE "xpm/collectable.xpm"
# define Q XK_q
# define W XK_w
# define A XK_a
# define S XK_s
# define D XK_d
# define ESC XK_Escape
# define KEY_LEFT XK_Left
# define KEY_RIGHT XK_Right
# define KEY_DOWN XK_Down
# define KEY_UP XK_Up

typedef struct s_map
{
	char	**map;
	char	*path;
	int		x;
	int		y;
	int		player;
	int		exit;
}			t_map;

typedef struct s_player
{
	int		coin;
	int		x;
	int		y;
	int		flous;
	bool	exit;
	int		moves;

}			t_player;

typedef struct s_image
{
	void	*player;
	void	*floor;
	void	*collectable;
	void	*exit;
	void	*wall;
}			t_image;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_player	player;
	t_image		image;
}				t_game;

void			read_map(t_game *game);
void			check_elements(t_game *game, int x, int y);
void			count_elements(t_game *game);
void			check_wall_map(t_game *game);
void			check_format(char *argv1, t_game *game);
void			check_size(t_game *game);
void			ft_error(char *message);
void			validate_arg(int argc);
void			ft_free_game(t_game *game);
void			start_player(t_game *game);
void			verification_of_playalibtly(t_game *game);
void			verification_recursivity(t_game *game, int y, int x);
void			verification(t_game *game);
void			put_floor(t_game *game, int x, int y);
void			put_place_exit(t_game *game, int x, int y);
void			put_wall(t_game *game, int x, int y);
void			put_collectable(t_game *game, int x, int y);
void			put_player(t_game *game, int x, int y);
void			charge_xpm(t_game *game);
void			put_img(t_game *game, int x, int y);
void			draw_img(t_game *game);
void			check_0(t_game *game, int my, int mx);
void			check_collects(t_game *game, int my, int mx);
void			move(t_game *game, int my, int mx);
int				handler_keys(int keycode, t_game *game);
int				destroy_window(t_game *game);
void			hooks(t_game *game);
int				main(int argc, char **argv);

#endif
