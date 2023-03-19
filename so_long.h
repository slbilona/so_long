#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft_clone/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include <stdlib.h>



// parsing carte
int		ft_verif_lignes(char **map);
int		ft_verification_map(char **map);
int     ft_verification_cpe(char **map);
int     ft_verification_murs(char **map);
int		ft_isstr(char **map, const char *s2);
char	**ft_creation_map(int fd);

//utils
int		ft_erreur(char **map);
int     ft_verif_ber(char *str);
int     ft_trouve_y(char **map);
int		ft_new_strchr(char *str, char c);
char	**ft_add_line(char **temp, char *str);
void	ft_free_temp(char **temp, int y);

//verif chemin
int ft_trouve_p(char **map, char c);
int	ft_nombre_de_e_c(char **map, char c);
int	ft_verification_chemin(char **map, int i, int j);

#endif