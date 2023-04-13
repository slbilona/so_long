/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fenetre.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:10:49 by ilselbon          #+#    #+#             */
/*   Updated: 2023/04/13 16:04:55 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_all(t_vars *vars)
{
	int	i;

	i = 0;
	mlx_destroy_image(vars->mlx, vars->mur);
	mlx_destroy_image(vars->mlx, vars->collec);
	mlx_destroy_image(vars->mlx, vars->sol);
	mlx_destroy_image(vars->mlx, vars->perso);
	mlx_destroy_image(vars->mlx, vars->exit);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	while (vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	free(vars->mlx);
	return (0);
}

int	ft_initialisation_images(t_vars *vars)
{
	int	x;
	int	y;
	int i;
	int j;

	i = 0;
	j = 0;
	x = (ft_strlen(vars->map[0]) * 50);
	y = (ft_trouve_y(vars->map) * 50);

	vars->mlx = mlx_init();
	mlx_get_screen_size(vars->mlx, &i, &j);
	if(i < x || j < y)
		return (1);
	ft_printf("%d, %d\n", i, j);
	vars->mur = mlx_xpm_file_to_image(vars->mlx,
			"./img/murclaires_2_0.xpm", &vars->img_width, &vars->img_height);
	vars->collec = mlx_xpm_file_to_image(vars->mlx,
			"./img/bonbons_et_sol.xpm", &vars->img_width, &vars->img_height);
	vars->sol = mlx_xpm_file_to_image(vars->mlx,
			"./img/sol.xpm", &vars->img_width, &vars->img_height);
	vars->perso = mlx_xpm_file_to_image(vars->mlx,
			"./img/perso_et_sol.xpm", &vars->img_width, &vars->img_height);
	vars->exit = mlx_xpm_file_to_image(vars->mlx,
			"./img/arrivee.xpm", &vars->img_width, &vars->img_height);
	vars->win = mlx_new_window(vars->mlx, x, y, "Hello world!");
	return (0);
}

void	ft_placement_px(int j, int y, t_vars *vars)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (vars->map[j][i])
	{
		if (vars->map[j][i] == '1')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->mur, x, y);
		else if (vars->map[j][i] == 'C' || vars->map[j][i] == 'c')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->collec, x, y);
		else if (vars->map[j][i] == '2' || vars->map[j][i] == '0')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->sol, x, y);
		else if (vars->map[j][i] == 'P')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, x, y);
		else if (vars->map[j][i] == 'e')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, x, y);
		x = x + 50;
		i++;
	}
}

int	ft_croix(t_vars *vars)
{
	exit(ft_free_all(vars));
	return (0);
}

int	ft_ouverture_fenetre(char **map, t_vars *vars)
{
	int	y;
	int	j;

	if(ft_initialisation_images(vars))
		return (1);
	mlx_hook(vars->win, 2, 1L << 0, ft_mouvements_et_close, vars);
	mlx_hook(vars->win, 17, 1L << 17, ft_croix, vars);
	y = 0;
	j = 0;
	while (map[j])
	{
		ft_placement_px(j, y, vars);
		y = y + 50;
		j++;
	}
	mlx_loop(vars->mlx);
	return (0);
}
