/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_carte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:04:22 by ilselbon          #+#    #+#             */
/*   Updated: 2023/04/14 18:51:43 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	y = ft_trouve_y(map) - 1;
	if (ft_verif_un(map[0]))
		return (1);
	i = ft_strlen(map[0]) - 1;
	while (j < y)
	{
		if (map[j][0] != '1' || map[j][i] != '1')
			return (1);
		j++;
	}
	if (ft_verif_un(map[y]))
		return (1);
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

int	ft_verification_map(t_vars *vars)
{
	if (!vars->map)
		return (1);
	if (ft_isstr(vars->map, "CEP01"))
	{
		ft_printf("1\n");
		return (ft_erreur(vars->map));
	}
	if (ft_verification_cpe(vars->map))
	{
		ft_printf("2\n");
		return (ft_erreur(vars->map));
	}
	if (ft_verif_lignes(vars->map))
	{
		ft_printf("3\n");
		return (ft_erreur(vars->map));
	}
	if (ft_verification_murs(vars->map))
	{
		ft_printf("4\n");
		return (ft_erreur(vars->map));
	}
	if (ft_verification_chemin(vars->map, ft_trouve_p(vars->map, 'i', vars),
			ft_trouve_p(vars->map, 'j', vars)))
	{
		ft_printf("5\n");
		return (ft_erreur(vars->map));
	}
	return (0);
}
