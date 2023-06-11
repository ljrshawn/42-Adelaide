#include "header.h"
#include <stdio.h>

void	input_value(int *matrix, int x, int y, int z)
{
	matrix[0] = x;
	matrix[1] = y;
	matrix[2] = z;
}

int	check_is_good(char **map, int i, int j, char c, int k)
{
	int	x;

	x = 0;
	while (x <= k)
	{
		if (map[i + k][x + j] == c || map[i + x][j + k] == c)
		{
			return (0);
		}
		x++;
	}
	return (1);
}

void	print_map(char **map, char *characters, int *matrix_size, int *result)
{
	int	i;
	int	j;

	i = 0;
	while (i < matrix_size[0])
	{
		j = 0;
		while (j < matrix_size[1])
		{
			if (i >= result[0] && i < result[0] + result[2]
				&& j >= result[1] && j < result[1] + result[2])
				write(1, &characters[2], 1);
			else
				write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	find_biggest_map(char **map, char *characters,
	int *matrix_size, int *result)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < matrix_size[0])
	{
		j = 0;
		while (j < matrix_size[1])
		{
			if (map[i][j] != characters[1])
			{
				k = 1;
				while ((i + k < matrix_size[0]) && (j + k < matrix_size[1])
					&& check_is_good(map, i, j, characters[1], k))
					k++;
				if (k > result[2])
					input_value(result, i, j, k);
			}
			j++;
		}
		i++;
	}
}

void	solve_map(char **map, char *characters, int *matrix_size)
{
	int	result[3];

	input_value(result, 0, 0, 0);
	find_biggest_map(map, characters, matrix_size, result);
	print_map(map, characters, matrix_size, result);
}
