#include <stdlib.h>
#include <unistd.h>

void	get_matrix(int dimension, char **result)
{
	char	**result_ptr;
	char	*b;

	result_ptr = result;
	while (result_ptr < result + dimension)
	{
		*result_ptr = malloc(dimension * sizeof(char));
		b = *result_ptr;
		while (b < *result_ptr + dimension)
		{
			*b = '0';
			b++;
		}
		result_ptr++;
	}
}

void	solve_inner(int col, int row, int dimension, int data, char **possible)
{
	int	i;
	int	j;

	j = data - 1;
	i = 0;
	if (row == 10)
	{
		if (j > 0)
		{
			while (i < j)
			{
				possible[i][col] = '1';
				i++;
			}
		}
		else
		{
			if (possible[i][col] == '0')
			{
				i = 1;
				while (i < dimension && possible[i][col] == '0')
				{
					possible[i][col] = '1';
					i++;
				}
			}
		}
	}
	if (row == -10)
	{
		if (j > 0)
		{
			i = 0;
			while (i < j)
			{
				possible[dimension - 1 - i][col] = '1';
				i++;
			}
		}
		else
		{
			if (possible[dimension - 1 - i][col] == '0')
			{
				i = 1;
				while (i < dimension && possible[dimension - 1 - i][col] == '0')
				{
					possible[dimension - 1 - i][col] = '1';
					i++;
				}
			}
		}
	}
	if (col == 10)
	{
		if (j > 0)
		{
			i = 0;
			while (i < j)
			{
				possible[row][i] = '1';
				i++;
			}
		}
		else
		{
			if (possible[row][i] == '0')
			{
				i = 1;
				while (i < dimension && possible[row][i] == '0')
				{
					possible[row][i] = '1';
					i++;
				}
			}
		}
	}
	if (col == -10)
	{
		if (j > 0)
		{
			i = 0;
			while (i < j)
			{
				possible[row][dimension - 1 - i] = '1';
				i++;
			}
		}
		else
		{
			if (possible[row][dimension - 1 - i] == '0')
			{
				i = 1;
				while (i < dimension && possible[row][dimension - 1 - i] == '0')
				{
					possible[row][dimension - 1 - i] = '1';
					i++;
				}
			}
		}
	}
}

void	solve(int index, int dimension, int data, char **possible)
{
	int	col;
	int	row;

	if (index / dimension < 2)
	{
		col = index % dimension;
		if (index / dimension < 1)
			row = 10;
		else
			row = -10;
	}
	else
	{
		row = index % dimension;
		if (index / dimension < 3)
			col = 10;
		else
			col = -10;
	}
	solve_inner(col, row, dimension, data, possible);
}

int	check(char **possible, int i, int j, int dimension)
{
	int	index;
	int	tem;

	index = 0;
	tem = 0;
	while (index < dimension)
	{
		if (index != i)
		{
			if (possible[index][j] == '0')
			{
				tem++;
			}
		}
		if (index != j)
		{
			if (possible[i][index] == '0')
			{
				tem++;
			}
		}
		index++;
	}
	if (tem > 1)
	{
		return (0);
	}
	return (1);
}

void	edit_matrix(int i, int j, int *data_matrix, char **result, int dimension, int d)
{
	int	index;

	index = 0;
	d = 0;
	while (index < dimension)
	{
		if (result[i][index] == dimension + '0')
		{
			if (index > j)
			{
				data_matrix[i + (2 * dimension)] = data_matrix[i + (2 * dimension)] - 1;
			}
			else
			{
				data_matrix[i + (3 * dimension)] = data_matrix[i + (3 * dimension)] - 1;
			}
		}
		if (result[index][j] == dimension + '0')
		{
			if (index > i)
			{
				data_matrix[j] = data_matrix[j] - 1;
			}
			else
			{
				data_matrix[j + dimension] = data_matrix[j + dimension] - 1;
			}
		}
		index++;
	}
}

void	save_number(char **possible, char **result, int *data_matrix, int dimension, int d)
{
	int	i;
	int	j;

	i = 0;
	while (i < dimension)
	{
		j = 0;
		while (j < dimension)
		{
			if (possible[i][j] == '0')
			{
				if (check(possible, i, j, dimension))
				{
					edit_matrix(i, j, data_matrix, result, dimension, d);
					result[i][j] = d + '0';
				}
			}
			j++;
		}
		i++;
	}
	if (d == dimension)
	{
		i = 0;
		while (i < dimension * 4)
		{
			data_matrix[i] = data_matrix[i] - 1;
			i++;
		}
	}
}

void	copy_arr(char **result, char **possible, int dimension)
{
	int	i;
	int	j;

	i = 0;
	while (i < dimension)
	{
		j = 0;
		while (j < dimension)
		{
			possible[i][j] = result[i][j];
			j++;
		}
		i++;
	}
}

void	printchar(char **result, int dimension)
{
	int	i;
	int	j;

	i = 0;
	while (i < dimension)
	{
		j = 0;
		while (j < dimension)
		{
			if (result[i][j] == '0')
			{
				write(1, "Error\n", 6);
				return ;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < dimension)
	{
		j = 0;
		while (j < dimension)
		{
			write(1, &result[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	get_result(int dimension, int *data_matrix)
{
	int		d;
	int		index;
	char	**result;
	char	**possible;

	d = dimension;
	result = malloc(dimension * sizeof(char *));
	possible = malloc(dimension * sizeof(char *));
	get_matrix(dimension, result);
	get_matrix(dimension, possible);
	while (d > 0)
	{
		index = 0;
		while (index < dimension * 4)
		{
			solve(index, dimension, data_matrix[index], possible);
			index++;
		}
		save_number(possible, result, data_matrix, dimension, d);
		copy_arr(result, possible, dimension);
		d--;
	}
	printchar(result, dimension);
	free(possible);
	free(result);
}