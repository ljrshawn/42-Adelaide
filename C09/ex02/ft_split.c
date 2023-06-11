/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:21:37 by jlyu              #+#    #+#             */
/*   Updated: 2023/06/02 11:21:41 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
		{
			return (1);
		}
		charset++;
	}
	if (c == '\0')
	{
		return (1);
	}
	return (0);
}

int	count_strnum(char *str, char *charset)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (check_sep(str[i + 1], charset) == 1
			&& check_sep(str[i], charset) == 0)
			res++;
		i++;
	}
	return (res);
}

void	copy_word(char *res, char *str, int start, int end)
{
	int	i;

	i = 0;
	while (i < end)
	{
		res[i] = str[start + i];
		i++;
	}
	res[i] = '\0';
}

void	save_char(char **res, char *str, char *charset)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (check_sep(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (check_sep(str[i + j], charset) == 0)
				j++;
			res[num] = malloc(sizeof(char) * (j + 1));
			copy_word(res[num], str, i, j);
			i += j;
			num++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	int		num;
	char	**res;

	num = count_strnum(str, charset);
	res = malloc((num + 1) * sizeof(char *));
	res[num] = 0;
	save_char(res, str, charset);
	return (res);
}

// #include <stdio.h>
// int main()
// {
// 	char **a = ft_split("abcdefghijk", "bjf");
// 	// while (a != 0)
// 	// {
// 		char *b = *a;
// 		while(*b)
// 		{
// 			printf("%c", *b);
// 			b++;
// 		}
// 		printf("\n");
// 		// a++;
// 	// }
// }
