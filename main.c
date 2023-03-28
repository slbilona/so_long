#include "so_long.h"
/*
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1200, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1200, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int i = 5;
	int j = 5;
	while(i < 1070)
	{
		if(j < 10)
			my_mlx_pixel_put(&img, i, i, 0xABEC56);
		else if (j < 20)
			my_mlx_pixel_put(&img, i, i, 0xC756EC);
		j++;
		if(j == 20)
			j = 0;
		
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}*/

/*
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	ft_printf("Hello from key_hook!\n");
	return (0);
}

int mouse_hook(int keycode, t_vars *vars)
{
	ft_printf("%d\n", keycode);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
*/
/*
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	render_next_frame(int keycode, void *YourStruct)
{
	ft_printf("test\n");
	return (0);
}

int	main(void)
{
	t_vars YourStruct;

	YourStruct.mlx = mlx_init();
	mlx_loop_hook(YourStruct.mlx, render_next_frame, &YourStruct);
	mlx_loop(YourStruct.mlx);
}*/

/*
int main(int ac, char **av)
{
	int fd;

	if(ac == 2)
	{
		if(!ft_verif_ber(av[1]))
		{
			fd = open(av[1], O_RDONLY);
			if(ft_verification_map(ft_creation_map(fd)))
				ft_printf("Error\n");
			else
				ft_printf("c'est bon pour le moment\n");
			close(fd);
		}
		else
			ft_printf("Error\n");
	}
	return (0);
}*/