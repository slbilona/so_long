#include "so_long.h"

int	ft_croix(t_vars *vars)
{
	exit(ft_free_all(vars));
	return (0);
}

int ft_juste_un_if(t_vars *vars)
{
	if (!vars->mur || !vars->collec || !vars->sol
		|| !vars->perso || !vars->exit || !vars->win)
		return (1);
	return (0);
}
