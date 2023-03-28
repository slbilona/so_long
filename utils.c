/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:18:57 by ilselbon          #+#    #+#             */
/*   Updated: 2023/03/28 19:47:34 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_new_strchr(char *str, char c)
{
	int	i;
	int	compte;

	i = 0;
	compte = 0;
	while (str[i])
	{
		if (str[i++] == c)
			compte++;
	}
	return (compte);
}

char	**ft_add_line(char **temp, char *str)
{
	static int	y = 0;
	char		**map;
	int			i;
	int			j;

	j = y - 1;
	map = malloc(sizeof(char *) * (y + 2));
	map[y] = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (j >= 0)
	{
		i = 0;
		map[j] = malloc(sizeof(char) * (ft_strlen(temp[j]) + 1));
		while (temp[j][i])
		{
			map[j][i] = temp[j][i];
			i++;
		}
		map[j][i] = 0;
		j--;
	}
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		map[y][i] = str[i];
		i++;
	}
	map[y][i] = 0;
	map[y + 1] = NULL;
	ft_free_temp(temp, y);
	y++;
	return (map);
}

void	ft_free_temp(char **temp, int y)
{
	if (y > 0)
	{
		while (y >= 0)
		{
			free(temp[y]);
			y--;
		}
		free(temp);
	}
}

int	ft_erreur(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (1);
}

int	ft_trouve_y(char **map)
{
	int	j;

	j = 0;
	while (map[j])
		j++;
	return (j);
}

int	ft_verif_ber(char *str)
{
	char	ber[4];
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	ber[0] = '.';
	ber[1] = 'b';
	ber[2] = 'e';
	ber[3] = 'r';
	ber[4] = 0;
	while (str[i])
	{
		if (str[i] == ber[j])
			j++;
		i++;
	}
	if (!ber[j])
		return (0);
	return (1);
}