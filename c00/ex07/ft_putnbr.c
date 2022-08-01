/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:10:37 by wcheon            #+#    #+#             */
/*   Updated: 2022/04/17 15:04:32 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
int		recul(int n);
void	ft_putchar(char c);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	recul(int n)
{
	if (n < 10)
	{
		ft_putchar(n + '0');
		return (0);
	}
	recul(n / 10);
	ft_putchar(n % 10 + '0');
	return (0);
}

void	ft_putnbr(int nb)
{
	if (nb >= 0)
		recul(nb);
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
