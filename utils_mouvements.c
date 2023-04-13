/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mouvements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:50:34 by ilselbon          #+#    #+#             */
/*   Updated: 2023/04/13 21:29:26 by ilselbon         ###   ########.fr       */
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

void	ft_else(t_vars *vars, int px, int py)
{
	if (vars->droite_gauche == 1)
		vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/fee_et_drap_d.xpm",
				&vars->img_width, &vars->img_height);
	else
		vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/fee_et_drap_g.xpm",
				&vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->perso, (vars->x + px), (vars->y + py));
	ft_printf("Felicitation tu a finis en .. mouvements !\n");
	sleep(1);
	exit(ft_free_all(vars));
}
