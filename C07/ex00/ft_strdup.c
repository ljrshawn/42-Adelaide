/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:00:00 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/30 10:00:37 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*copystr(char *str, char *res)
{
	while (*str)
	{
		*res = *str;
		res++;
		str++;
	}
	*res = '\0';
	return (res);
}

char	*ft_strdup(char *src)
{
	char				*tem;
	unsigned int		num;
	char				*res;

	if (src == NULL)
		return (NULL);
	tem = src;
	num = 0;
	while (*tem)
	{
		num++;
		tem++;
	}
	res = malloc((num + 1) * sizeof(char));
	if (res != NULL)
	{
		copystr(src, res);
	}
	return (res);
}

// #include <stdio.h>
// int main()
// {
// 	char *a = ft_strdup("");
// 	while (*a)
// 	{
// 		printf("%c", *a);
// 		a++;
// 	}
// 	return 0;
// }
