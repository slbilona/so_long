#include "so_long.h"

int ft_checking()
{
	//verif murs
	//verif rectangle
	//verif entre/sortie/perso/items
	int fd = open("map1.ber", O_RDONLY);
	if(ft_verif_e_p_c(fd))
		return (0);
	return (1);
}

int ft_verif_e_p_c(int fd)
{
	char *str = "slt";
	static int position = 0;
	static int collectible = 0;
	static int exit = 0;
	str = get_next_line(fd);
	if(str)
	{
		if(ft_strchr(str, 'E'))
			exit++;
		if(ft_strchr(str, 'C'))
			collectible++;
		if(ft_strchr(str, 'P'))
			position++;
		if(ft_isstr(str, "01CEP\n") == 1)
			return(1);
		free(str);
		ft_verif_e_p_c(fd);
	}
	if(position != 1 || collectible != 1 || exit != 1)
		return (1);
	return (0);
}

int	ft_isstr(const char *s1, const char *s2)
{
	int i = 0;
	while(s1[i])
	{
		if(!ft_strchr(s2, s1[i]))
			return (1);
		i++;
	}
	return (0);
}