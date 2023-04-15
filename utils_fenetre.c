/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fenetre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 22:12:29 by ilselbon          #+#    #+#             */
/*   Updated: 2023/04/15 16:52:25 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_croix(t_vars *vars)
{
	exit(ft_free_all(vars));
	return (0);
}

int	ft_juste_un_if(t_vars *vars, int x, int y)
{
	if (vars->mur && vars->collec && vars->sol
		&& vars->perso && vars->exit)
	{
		vars->win = mlx_new_window(vars->mlx, x, y, "Preciosa Hada");
		if (vars->win)
			return (0);
	}
	return (1);
}
