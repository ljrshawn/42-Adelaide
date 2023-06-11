/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:53:38 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/30 14:55:21 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	num;
	int				i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	num = max - min;
	*range = malloc(num * sizeof(int));
	if (*range != NULL)
	{
		i = 0;
		while (min < max)
		{
			(*range)[i] = min;
			min++;
			i++;
		}
		return (num);
	}
	return (-1);
}
// #include <stdio.h>
// int main()
// {
//     int **re = malloc(sizeof(int *));
//     int i = ft_ultimate_range(re, 0, 10);
//     if (re[0] != NULL)
// 	{
// 		for (int j = 0; j < i; j++)
// 		{
// 			printf("%d ", re[0][j]);
// 		}
// 		printf("\n");
// 		free(re);
// 	}
// 	return 0;
// }
