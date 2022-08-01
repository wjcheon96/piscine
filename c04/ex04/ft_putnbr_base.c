/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:23:31 by wcheon            #+#    #+#             */
/*   Updated: 2022/04/26 10:00:59 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(base);
	if (!base[0] || len <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	temp;
	int			len;
	int			err;

	err = check_base(base);
	len = ft_strlen(base);
	temp = nbr;
	if (err == 1)
	{
		if (temp < 0)
		{
			write(1, "-", 1);
			temp = -temp;
		}
		if (temp < len)
			ft_putchar(base[temp % len]);
		else
		{
			ft_putnbr_base(temp / len, base);
			ft_putchar(base[temp % len]);
		}
	}
}
