/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:03:34 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/20 12:05:22 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	dummy[100];

	index = size - 1;
	while (index >= 0)
	{
		dummy[index] = *tab;
		tab++;
		index--;
	}
	tab = &dummy[0];
}

// int main() {
//     int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int size = 9;

//     ft_rev_int_tab(&tab[0], size);
// }
