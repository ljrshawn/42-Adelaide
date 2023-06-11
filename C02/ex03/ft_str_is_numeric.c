/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:54:50 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/21 11:55:06 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	check_num(char *str)
{
	int	res;

	res = 1;
	while (*str != '\0')
	{
		if (!(*str - '0' >= 0 && *str - '0' < 9))
		{
			res = 0;
			break ;
		}
		str++;
	}
	return (res);
}

int	ft_str_is_numeric(char *str)
{
	int	res;

	if (*str == '-')
	{
		str++;
		res = check_num(str);
	}
	else
	{
		res = check_num(str);
	}
	return (res);
}

// int main(){
//     char src[20] = "fs";

//     int is = ft_str_is_numeric(&src[0]);
//     printf("%d", is);
// }
