/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:59:36 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/21 12:09:28 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	res;

	res = 1;
	while (*str != '\0')
	{
		if (*str < ' ' || *str > '~')
		{
			res = 0;
			break ;
		}
		str++;
	}
	return (res);
}

// int main(){
//     char src[20] = "~";

//     int is = ft_str_is_printable(&src[0]);
//     printf("%d", is);
// }
