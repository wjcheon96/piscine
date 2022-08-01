/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 10:22:51 by wcheon            #+#    #+#             */
/*   Updated: 2022/04/30 10:34:31 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] >= 9 && base[i] <= 13) || base[i] == 32)
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

int	ft_find(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_sign(char *str)
{
	int	sign;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;
	int	index;

	sign = 1;
	sign = ft_sign(str);
	while ((*str >= 9 && *str <= 13) || *str == 32
		|| *str == '+' || *str == '-')
		str++;
	result = 0;
	index = ft_find(base, *str);
	{
		while (*str && index >= 0)
		{
			result = result * ft_strlen(base) + index;
			str++;
			index = ft_find(base, *str);
		}
	}
	return (result * sign);
}
