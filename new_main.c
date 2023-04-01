#include "so_long.h"

int ft_verif_mouvement(char **map, int i, int j)
{
	if(map[j][i] == '1')
		return (1);
	if(map[j][i] == 'c' || map[j][i] == 'C')
	{
		map[j][i] = '0';
		return (0);
	}
	if(map[j][i] == 'e')
	{
		if(ft_nombre_de_e_c(map, 'c') == 0)
			ft_printf("c'est bueno\n");
		else
			ft_printf("pas fini mon coco\n");
	}
	return (0);
}

int	ft_mouvements_et_close(int keycode, t_vars *vars)
{
	static int i = 1;

	if(keycode == 'w')
	{
		if(!ft_verif_mouvement(vars->map, (vars->x/50), ((vars->y - 50)/50)))
		{
			ft_printf("%d\n", i);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->sol, vars->x, vars->y);
			mlx_destroy_image(vars->mlx, vars->perso);
			vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/perso_et_sol.xpm", &vars->img_width, &vars->img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->x, vars->y - 50);
			vars->y = vars->y - 50;
			i++;
		}
	}
	else if(keycode == 'a')
	{
		if(!ft_verif_mouvement(vars->map, ((vars->x-50)/50), (vars->y/50)))
		{
			ft_printf("%d\n", i);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->sol, vars->x, vars->y);
			mlx_destroy_image(vars->mlx, vars->perso);
			vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/perso_et_sol.xpm", &vars->img_width, &vars->img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->x - 50, vars->y);
			vars->x = vars->x - 50;
			i++;
		}
	}
	else if(keycode == 's')
	{
		if(!ft_verif_mouvement(vars->map, (vars->x/50), ((vars->y+50)/50)))
		{
			ft_printf("%d\n", i);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->sol, vars->x, vars->y);
			mlx_destroy_image(vars->mlx, vars->perso);
			vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/perso_et_sol.xpm", &vars->img_width, &vars->img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->x, vars->y + 50);
			vars->y = vars->y + 50;
			i++;
		}
	}
	else if(keycode == 'd')
	{
		if(!ft_verif_mouvement(vars->map, ((vars->x+50)/50), (vars->y/50)))
		{
			ft_printf("%d\n", i);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->sol, vars->x, vars->y);
			mlx_destroy_image(vars->mlx, vars->perso);
			vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/perso_et_sol.xpm", &vars->img_width, &vars->img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->x + 50, vars->y);
			vars->x = vars->x + 50;
			i++;
		}
	}
	else if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		// i = 0;
		// while(vars->map[i])
		// {
		// 	free(vars->map[i]);
		// 	i++;
		// }
		// free(vars->map);
		exit(EXIT_SUCCESS);
	}
	return (0);
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

int main(int ac, char **av)
{
	int fd;
	t_vars vars;

	if(ac == 2)
	{
		if(!ft_verif_ber(av[1]))
		{
			fd = open(av[1], O_RDONLY);
			vars.map = ft_creation_map(fd);
			close(fd);
			if(ft_verification_map(&vars))
				ft_printf("Error\n");
			else
			{
				ft_ouverture_fenetre(vars.map, &vars);
				ft_printf("TEST\n");
				int i;
				i = 0;
				while(vars.map[i])
				{
					free(vars.map[i]);
					i++;
				}
				free(vars.map);
			}
		}
		else
			ft_printf("Error\n");
	}
	return (0);
}
