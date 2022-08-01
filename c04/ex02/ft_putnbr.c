/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:54:57 by wcheon            #+#    #+#             */
/*   Updated: 2022/04/25 11:15:53 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	recul(int n)
{
	if (n < 10)
	{
		ft_putchar(n + '0');
	}
	else
	{
		recul(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

void	ft_putnbr(int nb)
{
	if (nb >= 0)
	{
		recul(nb);
	}
	else if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		write(1, "-", 1);
		recul(-nb);
	}
}
