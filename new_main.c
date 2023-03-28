#include "so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	ft_mouvements_et_close(int keycode, t_vars *vars)
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
		exit(EXIT_SUCCESS);
	}
}

void ft_ouverture_fenetre(char **map)
{
	t_vars	vars;
	int x;
	int y;
	
	x = (ft_strlen(map[0]) * 50);
	y = (ft_trouve_y(map) * 50);
	ft_printf("x : %d, y : %d\n", x, y);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, x, y, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, ft_mouvements_et_close, &vars);
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
