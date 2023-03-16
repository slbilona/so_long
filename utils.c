#include "so_long.h"

int	ft_new_strchr(char *str, char c)
{
	int i;
	int compte;

	i = 0;
	compte = 0;
	while(str[i])
	{
		if(str[i++] == c)
			compte++;
	}
	return (compte);
}

char	**ft_add_line(char **temp, char *str)
{
	char **map;
	static int y = 0;
	int i;
	int j;

	j = y - 1;
	map = malloc(sizeof(char *) * (y + 2));
	map[y] = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (j >= 0)
	{
		i = 0;
		map[j] = malloc(sizeof(char) * (ft_strlen(temp[j]) + 1));
		while (temp[j][i])
		{
			map[j][i] = temp[j][i];
			i++;
		}
		map[j][i] = 0;
		j--;
	}
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		map[y][i] = str[i];
		i++;
	}
	map[y][i] = 0;
	map[y + 1] = NULL;
	ft_free_temp(temp, y);
	y++;
	return (map);
}

void ft_free_temp(char **temp, int y)
{
	if(y > 0)
	{
		while(y >= 0)
		{
			free(temp[y]);
			y--;
		}
		free(temp);
	}
}

int ft_erreur(char **map)
{
	int i;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (1);
}