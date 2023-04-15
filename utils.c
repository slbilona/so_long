/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:18:57 by ilselbon          #+#    #+#             */
/*   Updated: 2023/04/15 16:38:27 by ilselbon         ###   ########.fr       */
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
	char	*ber;
	int		i;
	int		j;
	int		o;

	i = 0;
	ber = ft_strdup(".ber");
	while (str[i])
	{
		j = 0;
		if (str[i] == ber[j])
		{
			o = i;
			while (str[o] == ber[j] && str[o] && ber[j])
			{
				o++;
				j++;
			}
			if (!str[o] && !ber[j])
				return (free(ber), 0);
		}
		i++;
	}
	return (free(ber), 1);
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
