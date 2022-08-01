/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:29:38 by wcheon            #+#    #+#             */
/*   Updated: 2022/04/20 16:04:48 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_hex(unsigned char np);
void	ft_putstr_non_printable(char *str);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hex(unsigned char np)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[np / 16]);
	ft_putchar(hex[np % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			write(1, "\\", 1);
			ft_hex(str[i]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}
