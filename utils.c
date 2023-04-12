/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:18:57 by ilselbon          #+#    #+#             */
/*   Updated: 2023/04/12 15:39:00 by ilselbon         ###   ########.fr       */
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

int	ft_verif_un(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}
