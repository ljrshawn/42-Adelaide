#include "header.h"

int	is_inchar(char c, char *characters)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (c == characters[i] || c == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_map_length(char *map, int i, char *characters, int size)
{
	int	index;
	int	length;
	int	j;

	index = 0;
	length = 0;
	j = 1;
	while (map[i + index] != '\0' && is_inchar(map[i + index], characters))
	{
		if (map[i + index] == '\n')
		{
			j++;
			length = length == 0 ? index : length;
			if (length != index || index == 0)
					return (0);
			i = i + index + 1;
			index = 0;
		}
		else
			index++;
	}
	if (j - 1 != size)
		return (0);
	if (is_inchar(map[i + index], characters) != 1 && map[i + index] != '\0')
			return (0);
	return (1);
}

int	check_map(char *map)
{
	int		i;
	int		j;
	int		num;
	char	*characters;

	i = -1;
	characters = malloc(3 * sizeof(char));
	while (map[++i] != '\n');
	j = -1;
	num = 0;
	while (++j < i - 3)
		num = num * 10 + (map[j] - '0');
	if (i >= 4)
	{
		if (map[i - 1] != map[i - 2] && map[i - 2] != map[i - 3])
		{
			characters[0] = map[i - 3];
			characters[1] = map[i - 2];
			characters[2] = map[i - 1];
			return(check_map_length(map, i + 1, characters, num));
		}
	}
	return (0);
}

void	save_row_data(char *map, char **res, int index, int *matrix_size)
{
	int	i;
	int	j;
	int	k;
	int	size;

	i = 0;
	while(map[index + i] != '\n')
		i++;
	size = i;
	matrix_size[1] = size;
	i = 0;
	j = 0;
	k = 0;
	res[j] = malloc((size + 1) * sizeof(char));
	res[j][size] = '\0';
	while(map[index + i] != '0')
	{
		if (map[index + i] == '\n' && map[index + i + 1] == '\0')
		{
			break ;
		}
		if (map[index + i] == '\n' && map[index + i + 1] != '\0')
		{
			j++;
			res[j] = malloc((size + 1) * sizeof(char));
			res[j][size] = '\0';
			k = 0;
		}
		else
		{
			char c = map[index + i];
			res[j][k] = c;
			k++;
		}
		i++;
	}
}

char	**save_data(char *data, char *characters, int *matrix_size)
{
	int		num;
	char	**res;
	int		i;
	int		j;

	i = -1;
	while (data[++i] != '\n');
	characters[0] = data[i - 3];
	characters[1] = data[i - 2];
	characters[2] = data[i - 1];
	j = -1;
	num = 0;
	while (++j < i - 3)
		num = num * 10 + (data[j] - '0');
	matrix_size[0] = num;
	res = malloc((num + 1) * sizeof(char *));
	res[num] = 0;
	save_row_data(data, res, i + 1, matrix_size);
	return (res);
}

void clean_buffer(char	*buffer, int		size)
{
	int i;

	i = 0;
	while (i < size)
	{
		buffer[i] = '\0';
		i++;
	}
}

void	read_map(char *path)
{
	int		size;
	int		file;
	char	buffer[3000000];
	char	**res;
	char	characters[3];
	int		matrix_size[2];

	file = open(path, O_RDONLY);
	if (file != -1)
	{
		clean_buffer(buffer, 3000000);
		while ((size = read(file, buffer, 2999999)) > 0)
		{
			if (check_map(buffer))
			{
				res = save_data(buffer, characters, matrix_size);
				solve_map(res, characters, matrix_size);
				free(res);
				close(file);
			}
			else
				write(1, "map error\n", 10);
		}
	}
	else
		write(1, "map error\n", 10);	
}

void	read_save_map(char *path)
{	
	read_map(path);
}