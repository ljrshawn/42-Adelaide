/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:07:48 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/20 10:08:08 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int main() {
    int a = 10, b = 3;
    int div, mod;

    ft_div_mod(a, b, &div, &mod);

    printf("%d",div);
    printf("%d", mod);

    return 0;
}
*/
