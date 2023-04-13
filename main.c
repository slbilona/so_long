/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:36:20 by ilselbon          #+#    #+#             */
/*   Updated: 2023/04/13 21:12:50 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	int		fd;

	if (ac == 2)
	{
		if (!ft_verif_ber(av[1]))
		{
			fd = open(av[1], O_RDONLY);
			vars.map = ft_creation_map(fd);
			close(fd);
			if (ft_verification_map(&vars))
				ft_printf("Error\n");
			else
			{
				vars.booleen = 0;
				vars.droite_gauche = 1;
				if (ft_ouverture_fenetre(vars.map, &vars))
					ft_printf("Error\n");
			}
		}
		else
			ft_printf("Error\n");
	}
	return (0);
}
