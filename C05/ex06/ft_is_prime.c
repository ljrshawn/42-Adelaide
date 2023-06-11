/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:45:43 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/29 10:45:45 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb <= 0)
	{
		return (0);
	}
	while (i * i < nb && i <= 46340)
	{
		i++;
	}
	if (i * i == nb)
	{
		return (i);
	}
	return (i - 1);
}

int	ft_is_prime(int nb)
{
	int	sqrt;
	int	i;

	if (nb <= 1)
		return (0);
	sqrt = ft_sqrt(nb);
	i = 2;
	while (i <= sqrt)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
// #include <stdio.h>
// int main()
// {
//     printf("%d", ft_is_prime(2147395600));
// }