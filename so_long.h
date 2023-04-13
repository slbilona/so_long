/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:49:57 by ilselbon          #+#    #+#             */
/*   Updated: 2023/04/13 16:04:05 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft_clone/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include <stdlib.h>

typedef struct s_vars {
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
	int		booleen;
}				t_vars;

// parsing carte
int		ft_verif_lignes(char **map);
int		ft_verification_cpe(char **map);
int		ft_verification_murs(char **map);
int		ft_verification_map(t_vars *vars);
int		ft_isstr(char **map, const char *s2);

// creation map
char	**ft_creation_map(int fd);
char	**ft_free_map(char **map, int y);
char	**ft_free_temp(char **temp, int y);
char	**ft_add_line(char **temp, char *str);
void	ft_derniere_ligne(char *str, char **map, int y);

// utils
int		ft_erreur(char **map);
int		ft_verif_un(char *str);
int		ft_verif_ber(char *str);
int		ft_trouve_y(char **map);
int		ft_new_strchr(char *str, char c);

// verif chemin
int		verif_emplacement(char *map);
int		ft_nombre_de_e_c(char **map, char c);
int		ft_trouve_p(char **map, char c, t_vars *vars);
int		ft_verification_chemin(char **map, int i, int j);

// mouvements
int		ft_mouvements_et_close(int keycode, t_vars *vars);
void	ft_bas(t_vars *vars, int *i);
void	ft_haut(t_vars *vars, int *i);
void	ft_droite(t_vars *vars, int *i);
void	ft_gauche(t_vars *vars, int *i);

// utils mouvements
int		ft_verif_sortie(char **map, int i, int j);
int		ft_verif_mouvement(char **map, int i, int j, t_vars *vars);

// fenetre
int		ft_croix(t_vars *vars);
int		ft_free_all(t_vars *vars);
int		ft_initialisation_images(t_vars *vars);
void	ft_placement_px(int j, int y, t_vars *vars);
int		ft_ouverture_fenetre(char **map, t_vars *vars);

#endif