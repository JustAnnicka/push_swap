/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:26:43 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/28 19:09:28 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hex(unsigned int n, int format)
{
	char			*hex;
	int				count;
	unsigned long	x;

	x = n;
	count = ft_printf_countnbr_unsigned(n, 16);
	hex = ft_calloc(count + 1, sizeof(char));
	if (!hex)
		return (0);
	while (count-- > 0)
	{
		x = n % 16;
		n = n / 16;
		if (x == 0 || x <= 9)
			hex[count] = x + '0';
		else if (x >= 10 && x <= 15 && format == 'x')
			hex[count] = x + 87;
		else if (x >= 10 && x <= 15 && format == 'X')
			hex[count] = x + 55;
	}
	ft_putstr_fd(hex, 1);
	count = ft_strlen(hex);
	free(hex);
	return (count);
}
/* int main(void)
{
	printf("\ncount: %d",ft_printf_hex(1560, 'x'));
} */