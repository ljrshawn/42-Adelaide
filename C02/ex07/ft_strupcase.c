/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:59:36 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/22 09:20:42 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strupcase(char *str)
{
	char	*dummy;

	dummy = str;
	while (*str != '\0')
	{
		if (*str - 'a' >= 0 && *str - 'a' < 26)
		{
			*str -= 32;
		}
		str++;
	}
	return (dummy);
}

// int main(){
//     char src[20] = "fd5432safds";

//     ft_strupcase(&src[0]);
//     printf("%s", src);
//     return 0;
// }
