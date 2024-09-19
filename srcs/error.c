#include "so_long.h"

void	ft_error(char *message)
{
	ft_printf("%s", message);
	exit(1); /*El número 1 señala que el programa termina de manera anormal debido a un problema*/
}

void	validate_arg(int argc) /*Verificar que sean dos argumentos*/
{
	if (argc != 2) /*Si es diferente de dos*/
		ft_error("\n Error: Invalid arguments number\n");
}

void	ft_free(t_game *game) /*Libera la memoria asignada dinámicamente*/
{
	int	y; /*indice en el ciclo para recorrer el mapa*/

	y = -1; /*se inicializa en -1 para que el incremento comience en 0*/
	while (game->map.map[++y]) /*Mientras recorre las filas*/
		free(game->map.map[y]); /*libera la memoria asignada para la fila y*/
	free(game->map.map); /*Liberar memoria asignada para el arreglo de punteros*/
	game->map.map = NULL; /*Se asigna NULL para evitar que apunte a una ubicación ya liberada*/
}

