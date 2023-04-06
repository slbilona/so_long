/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mouvements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:50:34 by ilselbon          #+#    #+#             */
/*   Updated: 2023/04/06 19:18:29 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verif_mouvement(char **map, int i, int j, t_vars *vars)
{
	if (map[j][i] == '1')
		return (0);
	if (map[j][i] == 'c' || map[j][i] == 'C')
	{
		map[j][i] = 'b';
		return (1);
	}
	if (map[j][i] == 'e')
	{
		if (ft_nombre_de_e_c(map, 'c') == 0)
		{
			vars->booleen = 1;
			ft_printf("tu geres ma go !\n");
			return (2);
		}
		else
		{
			ft_printf("pas encore mon coco\n");
			return (1);
		}
	}
	return (1);
}

int	ft_verif_sortie(char **map, int i, int j)
{
	if ((map[j][i] == 'e' || map[j][i] == 'E')
		&& (ft_nombre_de_e_c(map, 'c') + ft_nombre_de_e_c(map, 'b')) != 0)
		return (1);
	if (map[j][i] == 'b')
		map[j][i] = '0';
	return (0);
}
