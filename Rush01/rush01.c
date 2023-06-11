/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:13:02 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/28 14:41:41 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>

void	get_result(int dimension, int *data_matrix);

int	get_dimension(char *data)
{
	int		dimension;
	char	*tem;

	tem = data;
	dimension = 0;
	while (*tem)
	{
		if (*tem >= '0' && *tem <= '9')
		{
			dimension++;
		}
		tem++;
	}
	return (dimension / 4);
}

int	*get_require(char *data, int dimension)
{
	int	*dummy;
	int	*data_matrix;

	data_matrix = malloc(dimension * 4 * sizeof(int));
	dummy = data_matrix;
	while (*data)
	{
		if (*data >= '0' && *data <= '9')
		{
			*dummy = *data - '0';
			dummy++;
		}
		data++;
	}
	return (data_matrix);
}

void	rush(char *data)
{
	int	*data_matrix;
	int	dimension;

	dimension = get_dimension(data);
	data_matrix = get_require(data, dimension);
	get_result(dimension, data_matrix);
	free(data_matrix);
}
