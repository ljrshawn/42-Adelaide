/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:15:10 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/18 10:00:59 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printstr(char i, char j, char k)
{
	if (i != j && j != k && i != k)
	{
		write(1, &i, 1);
		write(1, &j, 1);
		write(1, &k, 1);
	}
	if (i == '7' && j == '8' && k == '9')
	{
		write(1, "", 1);
	}
	else
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	while (i <= '7' )
	{
		j = i + 1;
		while (j <= '8' )
		{
			k = j + 1;
			while (k <= '9' )
			{
				printstr(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}

// int main() {
//     ft_print_comb();
// }
