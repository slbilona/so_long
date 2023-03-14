#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft_clone/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include <stdlib.h>



// parsing carte
int ft_verification(int fd);
int	ft_isstr(const char *s1, const char *s2);
int	ft_verif_lignes(char *str);
int ft_verif_rectangle(char *str);
int ft_verif_murs(char *str, int y, int x);

//utils
int ft_new_strchr(char *str, char c);
int ft_new_strlen(char *str);

#endif