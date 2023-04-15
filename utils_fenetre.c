/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fenetre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 22:12:29 by ilselbon          #+#    #+#             */
/*   Updated: 2023/04/15 15:19:19 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_croix(t_vars *vars)
{
	exit(ft_free_all(vars));
	return (0);
}

int	ft_juste_un_if(t_vars *vars)
{
	if (!vars->mur || !vars->collec || !vars->sol
		|| !vars->perso || !vars->exit || !vars->win)
		return (1);
	return (0);
}
