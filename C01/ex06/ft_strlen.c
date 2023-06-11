/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:40:53 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/20 10:41:54 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_strlen(char *str)
{
	int	num;

	while (*str != '\0')
	{
		num++;
		str++;
	}
	return (num);
}

// int main() {
//     char string[] = "HEELO";

//     int num = ft_strlen(&string[0]);
//     printf("%d", num);
// }
