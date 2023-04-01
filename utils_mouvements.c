#include "so_long.h"

int ft_verif_mouvement(char **map, int i, int j)
{
	if(map[j][i] == '1')
		return (0);
	if(map[j][i] == 'c' || map[j][i] == 'C')
	{
		map[j][i] = '0';
		return (1);
	}
	if(map[j][i] == 'e')
	{
		if(ft_nombre_de_e_c(map, 'c') == 0)
			return (2);
		else
		{
			ft_printf("pas encore mon coco\n");
			return (1);
		}
	}
	return (1);
}

int ft_verif_sortie(char **map, int i, int j)
{
	if(map[j][i] == 'e' && ft_nombre_de_e_c(map, 'c') != 0)
		return (1);
	else
		return (0);
}

