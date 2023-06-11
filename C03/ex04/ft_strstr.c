/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:25:54 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/23 11:10:57 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*check_str(char *str, char *to_find, char *start)
{
	char	*end;
	char	*needle;

	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			start = str;
			end = str;
			needle = to_find;
			while (*end != '\0' && *needle != '\0' && *end == *needle)
			{
				end++;
				needle++;
			}
			if (*needle == '\0')
				break ;
			else
				start = NULL;
		}
		str++;
	}
	return (start);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*start;

	start = NULL;
	if (*to_find == '\0')
	{
		start = str;
	}
	else
	{
		start = check_str(str, to_find, start);
	}
	return (start);
}

// int main() {
//     char str[] = "hello world!";
//     char *find = ft_strstr(str, "w");
//     printf("%s\n", find);

//     return 0;
// }
