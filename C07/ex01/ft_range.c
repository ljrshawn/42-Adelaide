/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:13:11 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/30 11:15:01 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	unsigned int	num;
	int				*res;
	int				i;

	if (min >= max)
	{
		return (NULL);
	}
	num = max - min;
	res = malloc(num * sizeof(int));
	i = 0;
	if (res != NULL)
	{
		while (min < max)
		{
			res[i] = min;
			min++;
			i++;
		}
	}
	return (res);
}
// #include <stdio.h>
// int main()
// {
//     int *re = ft_range(-2, 10);
//     if (re != NULL)
// 	{
// 		for (int i = 0; i < 10+2; i++)
// 		{
// 			printf("%d ", re[i]);
// 		}
// 		printf("\n");
// 		free(re);
// 	}
// 	return 0;
// }
