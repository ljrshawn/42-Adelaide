/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:40:06 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/18 14:52:20 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printstr(int index, char str[])
{
	while (index >= 0)
	{
		write(1, &str[index], 1);
		index--;
	}
}

void	int_to_string(int nb, char str[])
{
	int	i;
	int	negative;
	int	digit;

	i = 0;
	negative = 0;
	if (nb < 0)
	{
		nb = -nb;
		negative = 1;
	}
	while (nb != 0)
	{
		digit = nb % 10;
		str[i] = digit + '0';
		i++;
		nb /= 10;
	}
	if (negative)
	{
		str[i] = '-';
	}
	printstr(i, str);
}

void	ft_putnbr(int nb)
{
	char	str[20];

	int_to_string(nb, str);
}

// int main() {
//    ft_putnbr(-42);

//    return 0;
// }
