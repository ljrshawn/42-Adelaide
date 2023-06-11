/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:44:38 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/27 10:10:59 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printstr(char str)
{
	write(1, &str, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	i;

	i = nb;
	if (nb < 0)
	{
		printstr('-');
		i = nb * -1;
	}
	if (9 < i)
	{
		ft_putnbr(i / 10);
	}
	printstr(i % 10 + '0');
}
/*
#include <stdio.h>
int main() {
   ft_putnbr(2147483647);
   return 0;
}
*/