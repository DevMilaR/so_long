#include "so_long.h"

/*leer el archivo .ber y almacenarlo en la estructura t_map*/
void    read_map(t_game *game)
{
    int		fd;
	char	line; /*Almacenar temporalmente cada línea que se lee del archivo*/
	int		i;


	fd = open(game->map.path, O_RDONLY); /*la ruta del archivo está almacenada en map.path*/
	if (fd < 0)
			ft_error("Error: Failed to open the map.");
	game->map.map = (char **)malloc(sizeof(char *)*(game->map.y +1)); /*map.y = número de líneas del mapa*/
	if(!(game->map.map))
			ft_error("\nError: Failed to assigned memory.\n");
	line = get_next_line(fd); 
	if (!line)
			ft_error(\n"Error: line is empty"\n)
	i= 0;
	while (i < game->map.y)
	{
		game->map.map[i] = line; /*Contiene una línea del archivo que se almacena en game->map.map[i] (la posición i del array map)*/
		line = get_next_line(fd); /*leer la siguiente línea y actualizar */
		i++;
	}
	game->map.map[i] = NULL; /*indica el final del array*/
	close(fd);
}
