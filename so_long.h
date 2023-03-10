#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft_clone/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include "minilibx-linux/mlx.h"

// parsing carte
int ft_checking();
int ft_verif_e_p_c(int fd);
int	ft_isstr(const char *s1, const char *s2);

#endif