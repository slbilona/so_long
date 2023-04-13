/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:51:55 by ilselbon          #+#    #+#             */
/*   Updated: 2023/04/13 17:36:39 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(t_vars *vars, int *i, int px, int py)
{
	ft_printf("%d\n", *i);
	if (!ft_verif_sortie(vars->map, (vars->x / 50), (vars->y / 50)))
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sol, vars->x, vars->y);
	else
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->exit, vars->x, vars->y);
	mlx_destroy_image(vars->mlx, vars->perso);
	if (vars->booleen == 0)
	{	
		if (vars->droite_gauche == 1)
			vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/perso_d.xpm",
					&vars->img_width, &vars->img_height);
		else
			vars->perso = mlx_xpm_file_to_image(vars->mlx,
					"img/perso_g.xpm", &vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso,
			(vars->x + px), (vars->y + py));
	}
	else
		ft_else(vars, px, py);
	vars->x = vars->x + px;
	vars->y = vars->y + py;
	*i += 1;
}

int	ft_mouvements_et_close(int keycode, t_vars *vars)
{
	static int	i = 1;

	if (keycode == 'w')
	{
		if (ft_verif_mouvement(vars->map, (vars->x / 50),
				((vars->y - 50) / 50), vars))
			ft_move(vars, &i, 0, (-50));
	}
	else if (keycode == 'a')
	{
		if (ft_verif_mouvement(vars->map, ((vars->x - 50) / 50),
				(vars->y / 50), vars))
		{
			vars->droite_gauche = 0;
			ft_move(vars, &i, (-50), 0);
		}
	}
	else if (keycode == 's')
	{
		if (ft_verif_mouvement(vars->map, (vars->x / 50),
				((vars->y + 50) / 50), vars))
			ft_move(vars, &i, 0, 50);
	}
	else if (keycode == 'd')
	{
		if (ft_verif_mouvement(vars->map, ((vars->x + 50) / 50),
				(vars->y / 50), vars))
		{
			vars->droite_gauche = 1;
			ft_move(vars, &i, 50, 0);
		}
	}
	else if (keycode == 65307)
		exit(ft_free_all(vars));
	return (0);
}
