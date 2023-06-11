/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:47:46 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/24 12:54:25 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display(char number[], int i)
{
	i--;
	while (i >= 0)
	{
		write(1, &number[i], 1);
		i--;
	}
}

int	is_exist(char *base, char b)
{
	int	res;

	res = 0;
	while (*base != '\0')
	{
		if (*base == b)
		{
			res = 1;
			break ;
		}
		base++;
	}
	return (res);
}

int	get_base(char *base, char base_char[], int base_int)
{
	while (*base != '\0')
	{
		if (*base == '+' || *base == '-' || is_exist(base_char, *base))
		{
			base_char[0] = 'I';
			break ;
		}
		else
		{
			base_char[base_int] = *base;
			base_int++;
			base++;
		}
	}
	base_char[base_int] = '\0';
	return (base_int);
}

void	printnbr(int nbr, int base_int, char base_char[], int negtive)
{
	char	number[100];
	int		tem;
	int		i;

	tem = 0;
	i = 0;
	while (nbr != 0)
	{
		tem = nbr % base_int;
		number[i] = base_char[tem];
		i++;
		nbr /= base_int;
	}
	if (negtive)
	{
		number[i] = '-';
		i++;
	}
	display(number, i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	base_char[20];
	int		base_int;
	int		negtive;

	base_int = 0;
	if (!(*base == '\0' || *(base + 1) == '\0'))
	{
		base_int = get_base(base, base_char, base_int);
		if (base_char[0] != 'I')
		{
			if (nbr < 0)
			{
				negtive = 1;
				nbr = -nbr;
			}
			if (nbr == 0)
				display("0", 0);
			else
				printnbr(nbr, base_int, base_char, negtive);
		}
	}
}

// int main() {
//     ft_putnbr_base(128, "01");
//     return 0;
// }
