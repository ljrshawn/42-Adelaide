/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:58:46 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/22 14:00:28 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

int	inner(char *s1, char *s2, int res, unsigned int n)
{
	while (*s1 != '\0' && *s2 != '\0' && n > 0)
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
		n--;
	}
	if (*s1 == '\0' && *s2 != '\0' && n > 0)
	{
		res = -1;
	}
	else if (*s1 != '\0' && *s2 == '\0' && n > 0)
	{
		res = 1;
	}
	return (res);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	res;

	res = 0;
	res = inner(s1, s2, res, n);
	return (res);
}

// int main() {
// 	printf("%d\n", ft_strncmp("/2", "/2000", 10));
// 	printf("%d", strncmp("/2", "/2000", 10));
// }
