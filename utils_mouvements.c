/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mouvements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:50:34 by ilselbon          #+#    #+#             */
/*   Updated: 2023/04/14 20:09:29 by ilselbon         ###   ########.fr       */
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
			return (2);
		}
		else
			return (1);
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

void	ft_else(t_vars *vars, int px, int py, int i)
{
	if (vars->arrivee == -1)
		vars->arrivee = 4;
	if (vars->droite_gauche == 0)
		vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/fee_et_drap_d.xpm",
				&vars->img_width, &vars->img_height);
	else
		vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/fee_et_drap_g.xpm",
				&vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->perso, (vars->x + px), (vars->y + py));
	if (vars->arrivee == 4)
		ft_printf("Felicitation tu a finis en %d mouvements !\n", i);
	if (vars->arrivee == 0)
		exit(ft_free_all(vars));
	vars->arrivee -= 1;
}
