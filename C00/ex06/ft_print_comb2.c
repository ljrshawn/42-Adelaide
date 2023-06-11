/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:46:13 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/18 11:11:06 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printstr(char a, char b, char c, char d)
{
	if ((a == c && b == d) || (a == c && b > d) || (a > c))
	{
	}
	else
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, " ", 1);
		write(1, &c, 1);
		write(1, &d, 1);
		if (a == '9' && b == '8' && c == '9' && d == '9')
		{
			write(1, "", 1);
		}
		else
		{
			write(1, ", ", 2);
		}
	}
}

void	loopd(char a, char b, char c)
{
	char	d;

	d = '0';
	while (d <= '9')
	{
		printstr(a, b, c, d);
		d++;
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '9')
	{
		b = '0';
		while (b <= '9')
		{
			c = '0';
			while (c <= '9')
			{
				loopd(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}

// int main() {
//     ft_print_comb2();
// }
