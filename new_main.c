#include "so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*mur;
	void	*collec;
	void	*sol;
	void	*perso;
	char	*mon_perso;
	char	*mon_sol;
	char	*mon_mur;
	char	*mes_collectibles;
	int		img_width;
	int		img_height;
}				t_vars;

int	ft_mouvements_et_close(int keycode, t_vars *vars, char **map)
{
	static int i = 1;
	if(keycode == 'w' || keycode == 'a' ||  keycode == 's' || keycode == 'd')
	{
		ft_printf("%d\n", i);
		i++;
	}
	else if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		i = 0;
		while(map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
		free(vars->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void ft_ouverture_fenetre(char **map)
{
	t_vars	vars;
	int x;
	int y;
	
	vars.mon_mur = "/mnt/nfs/homes/ilselbon/Cursus/Cercle_3/so_long/img/murclaires_2_0.xpm";
	vars.mes_collectibles = "/mnt/nfs/homes/ilselbon/Cursus/Cercle_3/so_long/img/bonbons_et_sol.xpm";
	vars.mon_sol = "/mnt/nfs/homes/ilselbon/Cursus/Cercle_3/so_long/img/sol.xpm";
	vars.mon_perso = "/mnt/nfs/homes/ilselbon/Cursus/Cercle_3/so_long/img/AnyConv.com__perso.xpm";
	x = (ft_strlen(map[0]) * 50);
	y = (ft_trouve_y(map) * 50);
	ft_printf("x : %d, y : %d\n", x, y);
	vars.mlx = mlx_init();
	vars.mur = mlx_xpm_file_to_image(vars.mlx, vars.mon_mur, &vars.img_width, &vars.img_height);
	vars.collec = mlx_xpm_file_to_image(vars.mlx, vars.mes_collectibles, &vars.img_width, &vars.img_height);
	vars.sol = mlx_xpm_file_to_image(vars.mlx, vars.mon_sol, &vars.img_width, &vars.img_height);
	vars.perso = mlx_xpm_file_to_image(vars.mlx, vars.mon_perso, &vars.img_width, &vars.img_height);
	vars.win = mlx_new_window(vars.mlx, x, y, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, ft_mouvements_et_close, &vars);
	int j = 0;
	int i;
	y = 0;
	while(map[j])
	{
		x = 0;
		i = 0;
		while(map[j][i])
		{
			if(map[j][i] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.mur, x, y);
			else if(map[j][i] == 'C' || map[j][i] == 'c')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.collec, x, y);
			else if(map[j][i] == '2' || map[j][i] == '0')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.sol, x, y);
			else if(map[j][i] == 'P')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.perso, x, y);
			x = x + 50;
			i++;
		}
		y = y + 50;
		j++;
	}
	mlx_loop(vars.mlx);
}

int main(int ac, char **av)
{
	int fd;
	char **map;

	if(ac == 2)
	{
		if(!ft_verif_ber(av[1]))
		{
			fd = open(av[1], O_RDONLY);
			map = ft_creation_map(fd);
			if(ft_verification_map(map))
				ft_printf("Error\n");
			else
			{
				ft_ouverture_fenetre(map);
				int i;
				i = 0;
				while(map[i])
				{
					free(map[i]);
					i++;
				}
				free(map);
			}
			close(fd);
		}
		else
			ft_printf("Error\n");
	}
	return (0);
}
