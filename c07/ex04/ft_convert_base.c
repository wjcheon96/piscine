/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:51:59 by wcheon            #+#    #+#             */
/*   Updated: 2022/04/30 20:05:31 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str);
int	check_base(char *baes);
int	ft_find(char *base, char c);
int	ft_sign(char *str);
int	ft_atoi_base(char *str, char *base);

int	ft_itoa_len(long result, char *base_to)
{
	int	baselen;
	int	len;

	baselen = ft_strlen(base_to);
	len = 0;
	if (result < 0)
	{
			result = -result;
			len += 1;
	}
	if (result == 0)
		return (1);
	while (result > 0)
	{
		result = result / baselen;
		len += 1;
	}
	return (len);
}

void	ft_itoa(long result, char *base_to, char *arr, int len)
{
	int	baselen;

	baselen = ft_strlen(base_to);
	arr[len] = '\0';
	len--;
	if (result == 0)
		arr[len] = base_to[0];
	while (result > 0)
	{
		arr[len] = base_to[result % baselen];
		result = result / baselen;
		len--;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	result;
	char	*arr;
	int		len;

	len = 0;
	result = 0;
	if (!check_base(base_to) || !check_base(base_from))
		return (0);
	result = ft_atoi_base(nbr, base_from);
	len = ft_itoa_len(result, base_to);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == 0)
		return (0);
	if (result < 0)
	{
		arr[0] = '-';
		result = -result;
	}
	ft_itoa(result, base_to, arr, len);
	return (arr);
}

#include <string.h>

int main()
{
	printf("\n----------------------ex04----------------------------\n");
	char basefrom[100] = "0123456789";
	char baseto[100] = "0123456789";
	char input[100] = "      -123450";
	printf("basefrom : %s\nlen : %lu \n input num : %s baseto: %s \n\n\n",
	basefrom ,strlen(basefrom),input, baseto);
	char *result = ft_convert_base(input, basefrom, baseto);
	printf("result::: %s\n\n\n",result);
}

