#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

int ft_verification(int fd)
{
	char *str;
	static int i = 0;
	static int position = 0;
	static int collectible = 0;
	static int ft_exit = 0;

	str = get_next_line(fd);
	if(str)
	{
		ft_exit += ft_new_strchr(str, 'E');
		collectible += ft_new_strchr(str, 'C');
		position += ft_new_strchr(str, 'P');
		if(ft_isstr(str, "01CEP\n") == 1)
			return (1);
		if(ft_verif_rectangle(str) == 1)
			return(1);
		free(str);
		i++;
		if(ft_verification(fd) == 1)
			return 1;
	}
	if(position != 1 || ft_exit != 1 || collectible < 1)
		return (1);
	//verif murs
	//verif rectangle
	//verif entre/sortie/perso/items
	return (0);
}

int	ft_verif_rectangle(char *str)
{
	static int	i = 0;
	static int	j = 0;

	if (i == 0)
		j = ft_new_strlen(str);
	//ft_printf("taille_str : %d, j : %d, i : %d\n", ft_new_strlen(str), j, i);
	if(ft_new_strlen(str) != j)
		return (1);
	i++;
	//ft_printf("i : %d\n", i);
	return (0);
}

int	ft_isstr(const char *s1, const char *s2)
{
	int i;
	
	i = 0;
	while (s1[i])
	{
		if (ft_strchr(s2, s1[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}