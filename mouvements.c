#include "so_long.h"

void ft_haut(t_vars *vars, int i)
{
	ft_printf("%d\n", i);
	if (!ft_verif_sortie(vars->map, (vars->x/50), (vars->y/50)))
		mlx_put_image_to_window(vars->mlx, vars->win, vars->sol, vars->x, vars->y);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, vars->x, vars->y);
	mlx_destroy_image(vars->mlx, vars->perso);
	if(ft_verif_mouvement(vars->map, ((vars->x-50)/50), (vars->y/50)) != 2)
	{	
		vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/perso_et_sol.xpm", &vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->x, vars->y - 50);
	}
	else
	{
		vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/fee_et_drapeau.xpm", &vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->x, vars->y - 50);
	}
	vars->y = vars->y - 50;
}

void ft_bas(t_vars *vars, int i)
{
	ft_printf("%d\n", i);
	if (!ft_verif_sortie(vars->map, (vars->x/50), (vars->y/50)))
		mlx_put_image_to_window(vars->mlx, vars->win, vars->sol, vars->x, vars->y);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, vars->x, vars->y);
	mlx_destroy_image(vars->mlx, vars->perso);
	if(ft_verif_mouvement(vars->map, ((vars->x+50)/50), (vars->y/50)) != 2)
	{	
		vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/perso_et_sol.xpm", &vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->x, vars->y + 50);
	}
	else
	{
		vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/fee_et_drapeau.xpm", &vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->x, vars->y + 50);
	}
	vars->y = vars->y + 50;
}