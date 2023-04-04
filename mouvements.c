/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:51:55 by ilselbon          #+#    #+#             */
/*   Updated: 2023/04/04 17:05:11 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_haut(t_vars *vars, int *i)
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
		vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/perso_et_sol.xpm",
				&vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso,
			vars->x, vars->y - 50);
	}
	else
	{
		vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/fee_et_drapeau.xpm",
				&vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->perso, vars->x, vars->y - 50);
	}
	vars->y = vars->y - 50;
	*i += 1;
}

void	ft_bas(t_vars *vars, int *i)
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
		vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/perso_et_sol.xpm",
				&vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso,
			vars->x, vars->y + 50);
	}
	else
	{
		vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/fee_et_drapeau.xpm",
				&vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->perso, vars->x, vars->y + 50);
	}
	vars->y = vars->y + 50;
	*i += 1;
}

void	ft_droite(t_vars *vars, int *i)
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
		vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/perso_et_sol.xpm",
				&vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso,
			vars->x + 50, vars->y);
	}
	else
	{
		vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/fee_et_drapeau.xpm",
				&vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->perso, vars->x + 50, vars->y);
	}
	vars->x = vars->x + 50;
	*i += 1;
}

void	ft_gauche(t_vars *vars, int *i)
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
		vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/perso_et_sol.xpm",
				&vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso,
			vars->x - 50, vars->y);
	}
	else
	{
		vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/fee_et_drapeau.xpm",
				&vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->perso, vars->x - 50, vars->y);
	}
	vars->x = vars->x - 50;
	*i += 1;
}
