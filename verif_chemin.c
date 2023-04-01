/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_chemin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:47:13 by ilselbon          #+#    #+#             */
/*   Updated: 2023/04/01 15:57:45 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_trouve_p(char **map, char c, t_vars *vars)
{
	int	j;
	int	i;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				vars->y = j * 50;
				vars->x = i * 50;
				if (c == 'i')
					return (i);
				else if (c == 'j')
					return (j);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_nombre_de_e_c(char **map, char c)
{
	int	j;
	int	i;
	int	compte;

	j = 0;
	compte = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c)
				compte++;
			i++;
		}
		j++;
	}
	return (compte);
}

int	verif_emplacement(char *map)
{
	if(*map == '0' || *map == 'C' || *map == 'E')
	{
		if (*map == 'E')
			*map = 'e';
		if(*map == 'C')
			*map = 'c';
		if(*map == '0')
			*map = '2';
		return (0);
	}
	return (1);
}

int	ft_verification_chemin(char **map, int i, int j)
{
	int	dr[4] = {0, 0, -1, 1};
	int	dc[4] = {1, -1, 0, 0};
	int	i2;
	int	j2;
	int	o;

	if (ft_nombre_de_e_c(map, 'E') != 0 || ft_nombre_de_e_c(map, 'C') != 0)
	{
		o = 0;
		while (o < 4)
		{
			j2 = j + dr[o];
			i2 = i + dc[o];
			if (verif_emplacement((&map[j2][i2])) == 0)
				ft_verification_chemin(map, i2, j2);
			o++;
		}
	}
	if (ft_nombre_de_e_c(map, 'E') > 0 || ft_nombre_de_e_c(map, 'C') > 0)
		return (1);
	return (0);
}
