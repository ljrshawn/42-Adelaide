/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:36:14 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/31 10:53:06 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*addsep(char *tem, char *sep)
{
	while (*sep)
	{
		*tem = *sep;
		sep++;
		tem++;
	}
	return (tem);
}

void	joinstr(char *tem, char **strs, int size, char *sep)
{
	int		i;
	int		index;

	index = 0;
	while (index < size)
	{
		i = 0;
		while (strs[index][i] != '\0')
		{
			*tem = strs[index][i];
			i++;
			tem++;
		}
		if (index != size - 1)
			tem = addsep(tem, sep);
		index++;
	}
	*tem = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		index;
	int		num;
	int		i;
	char	*res;

	num = 0;
	index = 0;
	if (size == 0)
		return (malloc(0));
	while (index < size)
	{
		i = 0;
		while (strs[index][i++] != '\0')
			num++;
		index++;
	}
	i = 0;
	while (sep[i] != '\0')
		i++;
	num += (size - 1) * i;
	res = malloc((num + 1) * sizeof(char));
	joinstr(res, strs, size, sep);
	return (res);
}

// #include <stdio.h>
// int main()
// {
// 	char *str[] = {"hello", "world", "zaijun"};
// 	char sep[] = ", ";
// 	char *res = ft_strjoin(3, str, sep);
// 	printf("%s", res);
// 	return 0;
// }
