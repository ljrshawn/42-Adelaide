/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 09:20:47 by jlyu              #+#    #+#             */
/*   Updated: 2023/06/03 09:20:50 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

void	copytostock(struct s_stock_str *res, char *av, int size)
{
	int		index;

	index = 0;
	res->size = size;
	res->str = malloc((size + 1) * sizeof(char));
	res->copy = malloc((size + 1) * sizeof(char));
	while (index < size)
	{
		(res->str)[index] = av[index];
		(res->copy)[index] = av[index];
		index++;
	}
	(res->str)[index] = '\0';
	(res->copy)[index] = '\0';
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*res;
	int					i;
	int					j;

	res = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (res != NULL)
	{
		i = 0;
		while (i < ac)
		{
			j = 0;
			while (av[i][j] != '\0')
			{
				j++;
			}
			copytostock(&res[i], av[i], j);
			i++;
		}
		res[i].str = 0;
	}
	return (res);
}
