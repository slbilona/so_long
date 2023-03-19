/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_carte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:04:22 by ilselbon          #+#    #+#             */
/*   Updated: 2023/03/18 19:25:34 by ilselbon         ###   ########.fr       */
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

int	ft_verif_lignes(char **map)
{
	int	j;
	int	temp;

	j = 0;
	temp = ft_strlen(map[0]);
	while (map[j])
	{
		if (temp != (int)ft_strlen(map[j]))
			return (1);
		j++;
	}
	if (j == temp)
		return (1);
	return (0);
}

int	ft_isstr(char **map, const char *s2)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (ft_strchr(s2, map[j][i]) == 0)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_verification_murs(char **map)
{
	int	j;
	int	i;
	int	y;

	j = 1;
	i = 0;
	y = ft_trouve_y(map) - 1;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (1);
		i++;
	}
	i--;
	while (j < y)
	{
		if (map[j][0] != '1' || map[j][i] != '1')
			return (1);
		j++;
	}
	i = 0;
	while (map[y][i])
	{
		if (map[y][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_verification_cpe(char **map)
{
	int	j;
	int	c;
	int	p;
	int	e;

	j = 0;
	c = 0;
	p = 0;
	e = 0;
	while (map[j])
	{
		e += ft_new_strchr(map[j], 'E');
		c += ft_new_strchr(map[j], 'C');
		p += ft_new_strchr(map[j], 'P');
		j++;
	}
	if (e != 1 || p != 1 || c <= 0)
		return (1);
	return (0);
}

int	ft_verification_map(char **map)
{
	if (ft_isstr(map, "CEP01"))
		return (ft_erreur(map));
	if (ft_verification_cpe(map))
		return (ft_erreur(map));
	if (ft_verif_lignes(map))
		return (ft_erreur(map));
	if (ft_verification_murs(map))
		return (ft_erreur(map));
	if (ft_verification_chemin(map, ft_trouve_p(map, 'i'),
			ft_trouve_p(map, 'j')))
		return (ft_erreur(map));
	int i;
	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}
