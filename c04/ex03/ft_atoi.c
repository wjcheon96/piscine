/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:17:26 by wcheon            #+#    #+#             */
/*   Updated: 2022/04/26 10:01:36 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	result;
	int	flag;

	result = 0;
	flag = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			flag = -flag;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			result = ((result * 10) + (*str - '0'));
			str++;
		}
		else
			break ;
	}
	return (result * flag);
}
