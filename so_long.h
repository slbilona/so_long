/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:49:57 by ilselbon          #+#    #+#             */
/*   Updated: 2023/04/14 20:27:23 by ilselbon         ###   ########.fr       */
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
	int		i;
	int		j;
	int		y;
	int		x;
	int		booleen;
	int		arrivee;
	int		img_width;
	int		img_height;
	int		droite_gauche;
	char	**map;
	void	*mlx;
	void	*win;
	void	*mur;
	void	*sol;
	void	*exit;
	void	*perso;
	void	*collec;
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
void	ft_move(t_vars *vars, int *i, int px, int py);

// utils mouvements
int		ft_verif_sortie(char **map, int i, int j);
int		ft_verif_mouvement(char **map, int i, int j, t_vars *vars);
void	ft_else(t_vars *vars, int px, int py, int i);

// fenetre
int		ft_free_all(t_vars *vars);
int		ft_initialisation_images(t_vars *vars);
int		ft_ouverture_fenetre(char **map, t_vars *vars);
void	ft_placement_px(int j, int y, t_vars *vars);

// utils fenetre
int		ft_croix(t_vars *vars);
int ft_juste_un_if(t_vars *vars);

#endif