/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:40:57 by wcheon            #+#    #+#             */
/*   Updated: 2022/04/30 17:48:35 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	*arr;
	int	i;

	i = 0;
	len = max - min;
	arr = (int *)malloc(sizeof(int) * len);
	if (arr == 0)
		return (0);
	if (min >= max)
		return (0);
	while (i < len)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
/*
#include <stdio.h>
int main ()
{
	printf("-------ex01-------\n\n");
    int *ex01_arr1;
    int *ex01_arr2;
    int *ex01_arr3;

    printf("min : 1, max : 10\n");
    ex01_arr1 = ft_range(1, 10);
    for(int i = 0; i < 9; i++)
    {
        printf("%d ", ex01_arr1[i]);
    }
    printf("\n\n");
    printf("min : 10, max : 1\n");
    ex01_arr2 = ft_range(1, 0);
    printf("%p ", ex01_arr2);
    printf("\n\n");
    printf("min : -25, max : -10\n");
    ex01_arr3 = ft_range(-25, -10);
    for(int i = 0; i < 15; i++)
    {
        printf("%d ", ex01_arr3[i]);
    }
    printf("\n\n");
    free(ex01_arr1);
    free(ex01_arr2);
    free(ex01_arr3);
}
*/
