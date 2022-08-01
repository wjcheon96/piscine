/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:30:34 by wcheon            #+#    #+#             */
/*   Updated: 2022/04/17 15:04:24 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	ft_write(int a, int b);
void	ft_putchar(char c);

void	ft_write(int a, int b)
{
	ft_putchar((a / 10) + '0');
	ft_putchar((a % 10) + '0');
	write(1, " ", 1);
	ft_putchar((b / 10) + '0');
	ft_putchar((b % 10) + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	while (num1 <= 98)
	{
		num2 = num1 + 1;
		while (num2 <= 99)
		{
			ft_write(num1, num2);
			if (!(num1 == 98 && num2 == 99))
				write(1, ", ", 2);
			num2++;
		}
		num1++;
	}
}
