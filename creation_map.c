/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:16:03 by ilselbon          #+#    #+#             */
/*   Updated: 2023/04/12 15:40:06 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_creation_map(int fd)
{
	char		*str;
	static char	**map;

	str = get_next_line(fd);
	map = NULL;
	while (str)
	{
		map = ft_add_line(map, str);
		free(str);
		str = get_next_line(fd);
	}
	return (map);
}

void	ft_derniere_ligne(char *str, char **map, int y)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		map[y][i] = str[i];
		i++;
	}
	map[y][i] = 0;
	map[y + 1] = NULL;
}

char	**ft_add_line(char **temp, char *str)
{
	static int	y = 0;
	char		**map;
	int			j;

	j = y - 1;
	map = malloc(sizeof(char *) * (y + 2));
	if (!map)
		return (ft_free_temp(temp, y));
	map[y] = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!map[y])
	{
		ft_free_map(map, y);
		return (ft_free_temp(temp, y));
	}
	while (j >= 0)
	{
		map[j] = ft_strdup(temp[j]);
		j--;
	}
	ft_derniere_ligne(str, map, y);
	ft_free_temp(temp, y);
	y++;
	return (map);
}

char	**ft_free_map(char **map, int y)
{
	while (y >= 0)
	{
		free(map[y]);
		y--;
	}
	free(map);
	return (NULL);
}

char	**ft_free_temp(char **temp, int y)
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
	return (NULL);
}
