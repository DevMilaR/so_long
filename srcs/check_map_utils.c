#include "so_long.h"

void	check_elements(t_game *game, int x, int y) /*Verificar que cada carácter sea válido*/
{
	if (game->map.map[y][x] != '1' && game->map.map[y][x] != '0'
		&& game ->map.map[y][x] != '\n')
		ft_error("Error: invalid caracter");
}

void	count_elements(t_game *game) /*Cuenta y verifica los elementos importantes en el map*/
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
				game->map.player++;
			else if (game->map.map[y][x] == 'C')
				game->player.coin++;
			else if (game->map.map[y][x] == 'E')
				game->map.exit++;
			else
				check_elements(game, x, y);
			x++;
		}
		y++;
	}
	if (game->map.player != 1 || game->map.exit != 1)
		ft_error("Invalid number of player or exit");
	if (game->player.coin < 1)
		ft_error("Invalid number of coins");
}

void	check_wall_map(t_game *game) /*Verifica que el mapa esté completamente cerrado con paredes*/
{
	int	x;
	int	y;

	x = game->map.x; /*Número de columnas*/
	y = game->map.y; /*Número de filas*/
	while (x--) /*Verifica la primera y última fila recorriendo las filas*/
	{
		if (game->map.map[0][x] != '1' || /*Verifica la pared superior*/
			game->map.map[y - 1][x] != '1') /*Verifica la pared inferior*/
			ft_error("\nError: Map is not closed\n");
	}
	while (y--) /*Verifica la primera y última columna*/
	{
		if (game->map.map[y][0] != '1' || /*Verfica la pared izquierda*/
			game->map.map[y][game ->map.x - 1] != '1') /*Verifica la pared derecha*/
			ft_error("\nError: Map is not closed\n");
	}
}

/*Primero: Verificar .ber y alamcenar en game->map.path*/
void	check_format(char *argv1, t_game *game)
{
	int	i; /*Almacena la longitud del nombre del archivo*/

	i = ft_strlen(argv1); /*Calcula la longitud del nombre del archivo y lo guarda en la variable i*/
	if (ft_strncmp(&argv1[i - 4], ".ber", 4) != 0) /*Compara si los últimos 4 caracteres son .ber*/
	{
		ft_error("\nError\n Map file must have .ber\n");
	}
	game->map.path = argv1;
}

/*Verificar que el mapa sea rectangular: que todas las filas tengan la misma
cantidad de columnas*/

void	check_size(t_game *game)
{
	char	*line;
	char	*temp;
	int		fd;

	fd = open (game->map.path, O_RDONLY);
	if (fd < 0)
		ft_error("\nError: Unable to open the map\n");
	line = get_next_line(fd); /*lee la primera linea*/
	if (!line)
		ft_error("\nError: Empty Map\n");
	game->map.x = ft_strlen(line) - 1; /*Se calcula la longitud de la primera línea usando ft_strlen y se guarda en game->map.x*/
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n') /*Verificar si cada línea termina en un salto de línea*/
			line[ft_strlen(line) - 1] = '\0'; /*si es asi lo elimina y reemplaza por el de fin de cadena*/
		if (ft_strlen(line) != game->map.x) /*Verifica si la longitud de la fila coincide con la primera*/
			ft_error("\nError: Map is irregular on x\n"); 
		game->map.y++; /*Incrementa el contador de filas*/
		temp = line; /*Almacena la linea en temp*/
		line = get_next_line(fd); /*lee la siguiente linea*/
		free(temp); /*libera la memoria*/
	}
	close(fd);
}
