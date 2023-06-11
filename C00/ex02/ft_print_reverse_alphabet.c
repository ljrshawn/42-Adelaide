/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:02:02 by jlyu              #+#    #+#             */
/*   Updated: 2023/05/17 11:02:15 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	alph;

	alph = 'z';
	while (alph >= 'a' )
	{
		write(1, &alph, 1);
		alph--;
	}
}

// int main() {
//     ft_print_alphabet();
// }
