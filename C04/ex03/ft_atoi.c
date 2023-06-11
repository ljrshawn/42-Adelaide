/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:07:44 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/27 10:21:11 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	chack_inner(char tem[], char str, char max[])
{
	int	index;

	index = 0;
	while (index < 9)
	{
		if (tem[index] > max[index])
		{
			return (0);
		}
		index++;
	}
	if (str > max[index])
	{
		return (0);
	}
	return (1);
}

int	check_valid(char tem[], char str, int neg)
{
	if (neg % 2)
	{
		return (chack_inner(tem, str, "2147483648"));
	}
	else
	{
		return (chack_inner(tem, str, "2147483647"));
	}
}

int	get_result(int neg, char tem[], int i)
{
	int	res;
	int	index;

	index = 0;
	res = 0;
	while (index < i)
	{
		if (neg % 2)
		{
			res = res * 10 - (tem[index] - '0');
		}
		else
		{
			res = res * 10 + (tem[index] - '0');
		}
		index++;
	}
	return (res);
}

int	get_index(char *str, char tem[], int neg)
{
	int	i;

	i = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (i == 9)
		{
			if (check_valid(tem, *str, neg))
			{
				tem[i] = *str;
				i++;
			}
			break ;
		}
		else
		{
			tem[i] = *str;
			i++;
			str++;
		}
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int		neg;
	char	tem[15];
	int		i;

	neg = 0;
	i = 0;
	while (*str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg++;
		str++;
	}
	while (*str == '0')
		str++;
	i = get_index(str, tem, neg);
	return (get_result(neg, tem, i));
}

// #include <stdio.h>
// int main() {
//     printf("%d", ft_atoi( " +----+--+-002147483648ab567"));
// }
