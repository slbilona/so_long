#include "so_long.h"

void ft_free_all(t_vars *vars)
{
	int i;

	i = 0;
	mlx_destroy_image(vars->mlx, vars->mur);
	mlx_destroy_image(vars->mlx, vars->collec);
	mlx_destroy_image(vars->mlx, vars->sol);
	mlx_destroy_image(vars->mlx, vars->perso);
	mlx_destroy_image(vars->mlx, vars->exit);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	while(vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	free(vars->mlx);
}

void ft_ouverture_fenetre(char **map, t_vars *vars)
{
	int x;
	int y;
	int j;
	int i;

	x = (ft_strlen(map[0]) * 50);
	y = (ft_trouve_y(map) * 50);
	ft_printf("x : %d, y : %d\n", x, y);
	vars->mlx = mlx_init();
	vars->mur = mlx_xpm_file_to_image(vars->mlx, "./img/murclaires_2_0.xpm", &vars->img_width, &vars->img_height);
	vars->collec = mlx_xpm_file_to_image(vars->mlx, "./img/bonbons_et_sol.xpm", &vars->img_width, &vars->img_height);
	vars->sol = mlx_xpm_file_to_image(vars->mlx, "./img/sol.xpm", &vars->img_width, &vars->img_height);
	vars->perso = mlx_xpm_file_to_image(vars->mlx, "./img/perso_et_sol.xpm", &vars->img_width, &vars->img_height);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "./img/arrivee.xpm", &vars->img_width, &vars->img_height);
	vars->win = mlx_new_window(vars->mlx, x, y, "Hello world!");
	mlx_hook(vars->win, 2, 1L<<0, ft_mouvements_et_close, vars);
	y = 0;
	j = 0;
	while(map[j])
	{
		x = 0;
		i = 0;
		while(map[j][i])
		{
			if(map[j][i] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->mur, x, y);
			else if(map[j][i] == 'C' || map[j][i] == 'c')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->collec, x, y);
			else if(map[j][i] == '2' || map[j][i] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->sol, x, y);
			else if(map[j][i] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, x, y);
			else if(map[j][i] == 'e')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, x, y);
			x = x + 50;
			i++;
		}
		y = y + 50;
		j++;
	}
	mlx_loop(vars->mlx);
}