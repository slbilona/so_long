#include "so_long.h"

int ft_verification(int fd)
{
	char		*str;
	static char	**map;
	static int	y = 0;
	static int	position = 0;
	static int	collectible = 0;
	static int	ft_exit = 0;

	str = get_next_line(fd);
	if(y == 0)
		map = NULL;
	if (str)
	{
		ft_exit += ft_new_strchr(str, 'E');
		collectible += ft_new_strchr(str, 'C');
		position += ft_new_strchr(str, 'P');
		if (ft_isstr(str, "01CEP\n ") == 1)
			return (1);
		if (ft_verif_lignes(str) == 1)
			return (1);
		ft_verif_rectangle(str);
		map = ft_add_line(map, str);
		free(str);
		y++;
		if (ft_verification(fd) == 1)
			return 1;
	}
	if(ft_verif_rectangle(str) == 1)
	{
		ft_printf("1\n");
		return (1);
	}
	if(position != 1 || ft_exit != 1 || collectible < 1)
		return (1);
	int j = 0;
	while(map[j])
	{
		ft_printf("%s\n", map[j]);
		j++;
	}
	return (0);
}

int ft_verif_rectangle(char *str)
{
	static int y = 0;
	static int x = 0;
	
	if (!str)
	{
		if(y == x)
			return (1);
	}
	else
	{
		x = ft_new_strlen(str);
		y++;
	}
	return (0);
}

int	ft_verif_lignes(char *str)
{
	static int	i = 0;
	static int	j = 0;

	if (i == 0)
		j = ft_new_strlen(str);
	if(ft_new_strlen(str) != j)
		return (1);
	i++;
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