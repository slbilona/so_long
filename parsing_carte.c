#include "so_long.h"

char **ft_creation_map(int fd)
{
	char		*str;
	static char	**map;

	str = get_next_line(fd);
	map = NULL;
	while (str)
	{
		map = ft_add_line(map, str);
		free(str);
		str = get_next_line(fd);
	}
	return (map);
}

int	ft_verif_lignes(char **map)
{
	int j;
	int temp;

	j = 0;
	temp = ft_strlen(map[0]);
	while(map[j])
	{
		if(temp != (int)ft_strlen(map[j]))
			return (1);
		j++;
	}
	if(j == temp)
		return (1);
	return (0);
}

int	ft_isstr(char **map, const char *s2)
{
	int i;
	int j;
	
	j = 0;
	while (map[j])
	{
		i = 0;
		while(map[j][i])
		{
			if (ft_strchr(s2, map[j][i]) == 0)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int ft_verification_CPE(char **map)
{
	int j;
	int C;
	int P;
	int E;

	j = 0;
	C = 0;
	P = 0;
	E = 0;
	while (map[j])
	{
		E += ft_new_strchr(map[j], 'E');
		C += ft_new_strchr(map[j], 'C');
		P += ft_new_strchr(map[j], 'P');
		j++;
	}
	if (E != 1 || P != 1 || C <= 0)
		return (1);
	return (0);
}

int		ft_verification_map(char **map)
{
	//verif caracteres
	if(ft_isstr(map, "CEP01"))
		return (ft_erreur(map));
	//verifs C E P
	if(ft_verification_CPE(map))
		return (ft_erreur(map));
	//verif lignes et rectangles
	if(ft_verif_lignes(map))
		return (ft_erreur(map));
	//verif murs

	int i;
	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}