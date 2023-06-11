/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:30:13 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/22 09:37:27 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int a, int b);

int	main(int args, char *argv[])
{
	int	a;
	int	b;
	int	index;

	while (argv[1][index])
	{
		a = a * 10 + (argv[1][index] - '0');
		index++;
	}
	index = 0;
	while (argv[2][index])
	{
		b = b * 10 + (argv[2][index] - '0');
		index++;
	}
	rush(a, b);
	return (0);
}
