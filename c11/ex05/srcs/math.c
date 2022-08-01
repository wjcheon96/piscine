/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:34:09 by wcheon            #+#    #+#             */
/*   Updated: 2022/05/05 10:10:47 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_plus(int a, int b)
{	
	ft_putnbr(a + b);
	write(1, "\n", 1);
}

void	ft_minus(int a, int b)
{
	ft_putnbr(a - b);
	write(1, "\n", 1);
}

void	ft_multiple(int a, int b)
{
	ft_putnbr(a * b);
	write(1, "\n", 1);
}

void	ft_division(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return ;
	}
	ft_putnbr(a / b);
	write(1, "\n", 1);
}

void	ft_mod(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return ;
	}
	ft_putnbr(a % b);
	write(1, "\n", 1);
}
