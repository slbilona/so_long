/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:36:20 by ilselbon          #+#    #+#             */
/*   Updated: 2023/04/04 20:36:20 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mouvements_et_close(int keycode, t_vars *vars)
{
	static int	i = 1;

	if (keycode == 'w')
	{
		if (ft_verif_mouvement(vars->map, (vars->x / 50),
				((vars->y - 50) / 50), vars))
			ft_haut(vars, &i);
	}
	else if (keycode == 'a')
	{
		if (ft_verif_mouvement(vars->map, ((vars->x - 50) / 50),
				(vars->y / 50), vars))
			ft_gauche(vars, &i);
	}
	else if (keycode == 's')
	{
		if (ft_verif_mouvement(vars->map, (vars->x / 50),
				((vars->y + 50) / 50), vars))
			ft_bas(vars, &i);
	}
	else if (keycode == 'd')
	{
		if (ft_verif_mouvement(vars->map, ((vars->x + 50) / 50),
				(vars->y / 50), vars))
			ft_droite(vars, &i);
	}
	else if (keycode == 65307)
		exit(ft_free_all(vars));
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		fd;

	if (ac == 2)
	{
		if (!ft_verif_ber(av[1]))
		{
			fd = open(av[1], O_RDONLY);
			vars.map = ft_creation_map(fd);
			close(fd);
			if (ft_verification_map(&vars))
				ft_printf("Error\n");
			else
			{
				vars.booleen = 0;
				ft_ouverture_fenetre(vars.map, &vars);
			}
		}
		else
			ft_printf("Error\n");
	}
	return (0);
}
