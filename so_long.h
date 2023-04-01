#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft_clone/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*mur;
	void	*collec;
	void	*sol;
	void	*perso;
	void	*exit;
	int		y;
	int		x;
	int		img_width;
	int		img_height;
	char	**map;
}				t_vars;


// parsing carte
int		ft_verif_lignes(char **map);
int		ft_verification_map(t_vars *vars);
int     ft_verification_cpe(char **map);
int     ft_verification_murs(char **map);
int		ft_isstr(char **map, const char *s2);
char	**ft_creation_map(int fd);

//utils
int		ft_trouve_y(char **map);
int		ft_erreur(char **map);
int     ft_verif_ber(char *str);
int		ft_new_strchr(char *str, char c);
int		ft_trouve_p(char **map, char c, t_vars *vars);
char	**ft_add_line(char **temp, char *str);
void	ft_free_temp(char **temp, int y);

//verif chemin
int	ft_nombre_de_e_c(char **map, char c);
int	ft_verification_chemin(char **map, int i, int j);

#endif