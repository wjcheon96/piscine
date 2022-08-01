/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:16:51 by wcheon            #+#    #+#             */
/*   Updated: 2022/05/03 21:02:43 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}
/*
#include <stdio.h>

int	ft_check_alpha(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			return (0);
		if (str[i] >= 97 && str[i] <= 122)
			return (0);
		i++;
	}
	return (1);
}

int main()
{
	printf("-------ex03-------\n\n");
	char *ex02_arr[5];
	ex02_arr[0] = "helloworld";
	ex02_arr[1] = "abc";
	ex02_arr[2] = "iasdf";
	ex02_arr[3] = "sdfew";
	ex02_arr[4] = 0;
	printf(" : %d\n\n", ft_count_if(ex02_arr, 4, &ft_check_alpha));
}
*/
