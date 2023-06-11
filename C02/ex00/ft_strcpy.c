/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:55:11 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/21 10:55:14 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*dummy;

	dummy = dest;
	while (*src != '\0')
	{
		*dummy = *src;
		dummy++;
		src++;
	}
	*dummy = '\0';
	return (dest);
}
// int main(){
//     char src[20] = "Hello";
//     char dest[20];

//     ft_strcpy(&dest[0], &src[0]);
//     printf("%s", dest);
// }
