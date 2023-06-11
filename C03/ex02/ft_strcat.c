/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:14:58 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/23 09:15:02 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*dummy;

	dummy = dest;
	while (*dummy)
	{
		dummy++;
	}
	while (*src)
	{
		*dummy = *src;
		dummy++;
		src++;
	}
	*dummy = '\0';
	return (dest);
}

// int main() {
// 	char str[] = "ad";
// 	ft_strcat(str, "ASDFG");
//     printf("%s", str);
// }
