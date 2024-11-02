#include "so_long.h"

int	map_size_x(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (i - 1);
}

int	map_size_y(char *map)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map[++i])
		if (map[i] == '\n')
			j++;
	return (j + 1);
}

char	*map_reader(int fd)
{
	char	*line;
	char	*aaa;
	char	*temp;
	int		len;

	line = (char *)malloc((BUFFER_SIZE) * sizeof(char));
	line[0] = '\0';
	while (1)
	{
		aaa = get_next_line(fd);
		if (!aaa)
			break ;
		temp = ft_strjoin(line, aaa);
		free(line);
		line = temp;
		free(aaa);
	}
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}
