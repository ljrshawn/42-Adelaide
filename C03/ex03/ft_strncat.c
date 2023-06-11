/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:34:39 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/24 16:20:54 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*dummy;

	dummy = dest;
	while (*dummy)
	{
		dummy++;
	}
	while (*src && nb > 0)
	{
		*dummy = *src;
		dummy++;
		src++;
		nb--;
	}
	*dummy = '\0';
	return (dest);
}

int main() {
	char str[] = "ad";
 	ft_strncat(str, "ASDFG", 2);
     printf("%s", str);
 }
