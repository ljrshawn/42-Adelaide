/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:42:52 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/22 13:43:05 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "ft_header.h"

int	inner(char *s1, char *s2, int res)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 < *s2)
		{
			res = -1;
			break ;
		}
		else if (*s1 > *s2)
		{
			res = 1;
			break ;
		}
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 != '\0')
	{
		res = -1;
	}
	else if (*s1 != '\0' && *s2 == '\0')
	{
		res = 1;
	}
	return (res);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	res;

	res = 0;
	res = inner(s1, s2, res);
	return (res);
}

// int main() {
// 	printf("%d\n", ft_strcmp("/200", "/0"));
// 	printf("%d", strcmp("/200", "/0"));
// }
