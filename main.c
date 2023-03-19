#include "so_long.h"

// int    main(void)
// {
//     void    *mlx;
//     void    *mlx_win;
//     void     *img;
//     char     *relative_path = "download.xpm";
//     int     img_width;
//     int        img_height;

//     mlx = mlx_init();
//     img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
//     mlx_win = mlx_new_window(mlx, 720, 570, "Hello world!");

//     mlx_put_image_to_window(mlx, mlx_win, img, 5,5);
//     mlx_loop(mlx);
// }

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
		}
	}
	return (0);
}